// GKzaj6zad1.cpp: Definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <GL/glut.h>
#include <stdlib.h>
#include "materials.h"

// stałe do obsługi menu podręcznego

enum
{
	BRASS,                // mosiądz
	BRONZE,               // brąz
	POLISHED_BRONZE,      // polerowany brąz
	CHROME,               // chrom
	COPPER,               // miedź
	POLISHED_COPPER,      // polerowana miedź
	GOLD,                 // złoto
	POLISHED_GOLD,        // polerowane złoto
	PEWTER,               // grafit (cyna z ołowiem)
	SILVER,               // srebro
	POLISHED_SILVER,      // polerowane srebro
	EMERALD,              // szmaragd
	JADE,                 // jadeit
	OBSIDIAN,             // obsydian
	PEARL,                // perła
	RUBY,                 // rubin
	TURQUOISE,            // turkus
	BLACK_PLASTIC,        // czarny plastik
	BLACK_RUBBER,         // czarna guma
	FULL_WINDOW,       // aspekt obrazu - całe okno
	ASPECT_1_1,        // aspekt obrazu 1:1
	WIRED,
	SOLID,
	EXIT               // wyjście
};

bool wired = true;

// aspekt obrazu

int aspect = FULL_WINDOW;

// rozmiary bryły obcinania

const GLdouble left = -20.0;
const GLdouble right = 20.0;
const GLdouble bottom = -20.0;
const GLdouble top = 20.0;
const GLdouble near_ = 50.0;
const GLdouble far_ = 170.0;

// współczynnik skalowania

GLfloat scale = 1.0;

// kąty obrotu

GLfloat rotatex = 0.0;
GLfloat rotatey = 0.0;

// przesunięcie

GLfloat translatex = 0.0;
GLfloat translatey = 0.0;

// wskaŸnik naciśnięcia lewego przycisku myszki

int button_state = GLUT_UP;

// poło¿enie kursora myszki

int button_x, button_y;

//
const GLfloat *ambient = BronzeAmbient;
const GLfloat *diffuse = BronzeDiffuse;
const GLfloat *specular = BronzeSpecular;
GLfloat shininess = BronzeShininess;

void rysuj12()
{
	if (wired)
		glutWireDodecahedron();
	else
		glutSolidDodecahedron();
}

void RysujKwadrat(int z) 
{
	for (int i = 1; i <= z; i++) 
	{
		for (int j = 1; j <= z; j++)
		{
			rysuj12();
			glTranslatef(0.0, 3.0, 0.0);
		}
		glTranslatef(3.0, -z*3.0, 0.0);
	}
	glTranslatef(-z*3.0, 0.0, 0.0);
}

// funkcja rysująca piramidę z sześcianów

void Pyramid()
{
	for (int i = 15; i != 0; i--) 
	{
		RysujKwadrat(i);
		glTranslatef(1.5, 1.5, 3.0);
	}
}

// funkcja generująca scenę 3D

void Display()
{
	// kolor tła - zawartość bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// przesunięcie układu współrzędnych obiektu do środka bryły odcinania
	glTranslatef(0, 0, -(near_ + far_) / 2);

	// przesunięcie obiektu - ruch myszką
	glTranslatef(translatex, translatey, 0.0);

	// skalowanie obiektu - klawisze "+" i "-"
	glScalef(scale, scale, scale);

	// obroty obiektu - klawisze kursora
	glRotatef(rotatex, 1.0, 0, 0);
	glRotatef(rotatey, 0, 1.0, 0);

	// kolor krawędzi obiektu
	//glColor3f(0.0, 0.0, 0.0);


	// rysowanie piramidy
	Pyramid();

	// skierowanie poleceń do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}

// zmiana wielkości okna

void Reshape(int width, int height)
{
	// obszar renderingu - całe okno
	glViewport(0, 0, width, height);

	// wybór macierzy rzutowania
	glMatrixMode(GL_PROJECTION);

	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();

	// parametry bryły obcinania
	if (aspect == ASPECT_1_1)
	{
		// wysokość okna większa od wysokości okna
		if (width < height && width > 0)
			glFrustum(left, right, bottom*height / width, top*height / width, near_, far_);
		else

			// szerokość okna większa lub równa wysokości okna
			if (width >= height && height > 0)
				glFrustum(left*width / height, right*width / height, bottom, top, near_, far_);
	}
	else
		glFrustum(left, right, bottom, top, near_, far_);

	// generowanie sceny 3D
	Display();
}

// obsługa klawiatury

void Keyboard(unsigned char key, int x, int y)
{
	// klawisz +
	if (key == '+')
		scale += 0.1;
	else

		// klawisz -
		if (key == '-' && scale > 0.1)
			scale -= 0.1;

	// odrysowanie okna
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obsługa klawiszy funkcyjnych i klawiszy kursora

void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		rotatey -= 1;
		break;

		// kursor w górę
	case GLUT_KEY_UP:
		rotatex -= 1;
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		rotatey += 1;
		break;

		// kursor w dół
	case GLUT_KEY_DOWN:
		rotatex += 1;
		break;
	}

	// odrysowanie okna
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obsługa przycisków myszki

void MouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		// zapamiętanie stanu lewego przycisku myszki
		button_state = state;

		// zapamiętanie poło¿enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_x = x;
			button_y = y;
		}
	}
}

// obsługa ruchu kursora myszki

void MouseMotion(int x, int y)
{
	if (button_state == GLUT_DOWN)
	{
		translatex += 1.1 *(right - left) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_x);
		button_x = x;
		translatey += 1.1 *(top - bottom) / glutGet(GLUT_WINDOW_HEIGHT) * (button_y - y);
		button_y = y;
		glutPostRedisplay();
	}
}

// obsługa menu podręcznego

void Menu(int value)
{
	switch (value)
	{
	case BRASS:

		ambient = BrassAmbient;

		diffuse = BrassDiffuse;

		specular = BrassSpecular;

		shininess = BrassShininess;

		Display();

		break;

		// materiał - brąz

	case BRONZE:

		ambient = BronzeAmbient;

		diffuse = BronzeDiffuse;

		specular = BronzeSpecular;

		shininess = BronzeShininess;

		Display();

		break;

		// materiał - polerowany brąz

	case POLISHED_BRONZE:

		ambient = PolishedBronzeAmbient;

		diffuse = PolishedBronzeDiffuse;

		specular = PolishedBronzeSpecular;

		shininess = PolishedBronzeShininess;

		Display();

		break;

		// materiał - chrom

	case CHROME:

		ambient = ChromeAmbient;

		diffuse = ChromeDiffuse;

		specular = ChromeSpecular;

		shininess = ChromeShininess;

		Display();

		break;

		// materiał - miedź

	case COPPER:

		ambient = CopperAmbient;

		diffuse = CopperDiffuse;

		specular = CopperSpecular;

		shininess = CopperShininess;

		Display();

		break;

		// materiał - polerowana miedź

	case POLISHED_COPPER:

		ambient = PolishedCopperAmbient;

		diffuse = PolishedCopperDiffuse;

		specular = PolishedCopperSpecular;

		shininess = PolishedCopperShininess;

		Display();

		break;

		// materiał - złoto

	case GOLD:

		ambient = GoldAmbient;

		diffuse = GoldDiffuse;

		specular = GoldSpecular;

		shininess = GoldShininess;

		Display();

		break;

		// materiał - polerowane złoto

	case POLISHED_GOLD:

		ambient = PolishedGoldAmbient;

		diffuse = PolishedGoldDiffuse;

		specular = PolishedGoldSpecular;

		shininess = PolishedGoldShininess;

		Display();

		break;

		// materiał - grafit (cyna z ołowiem)

	case PEWTER:

		ambient = PewterAmbient;

		diffuse = PewterDiffuse;

		specular = PewterSpecular;

		shininess = PewterShininess;

		Display();

		break;

		// materiał - srebro

	case SILVER:

		ambient = SilverAmbient;

		diffuse = SilverDiffuse;

		specular = SilverSpecular;

		shininess = SilverShininess;

		Display();

		break;

		// materiał - polerowane srebro

	case POLISHED_SILVER:

		ambient = PolishedSilverAmbient;

		diffuse = PolishedSilverDiffuse;

		specular = PolishedSilverSpecular;

		shininess = PolishedSilverShininess;

		Display();

		break;

		// materiał - szmaragd

	case EMERALD:

		ambient = EmeraldAmbient;

		diffuse = EmeraldDiffuse;

		specular = EmeraldSpecular;

		shininess = EmeraldShininess;

		Display();

		break;

		// materiał - jadeit

	case JADE:

		ambient = JadeAmbient;

		diffuse = JadeDiffuse;

		specular = JadeSpecular;

		shininess = JadeShininess;

		Display();

		break;

		// materiał - obsydian

	case OBSIDIAN:

		ambient = ObsidianAmbient;

		diffuse = ObsidianDiffuse;

		specular = ObsidianSpecular;

		shininess = ObsidianShininess;

		Display();

		break;

		// materiał - perła

	case PEARL:

		ambient = PearlAmbient;

		diffuse = PearlDiffuse;

		specular = PearlSpecular;

		shininess = PearlShininess;

		Display();

		break;

		// metariał - rubin

	case RUBY:

		ambient = RubyAmbient;

		diffuse = RubyDiffuse;

		specular = RubySpecular;

		shininess = RubyShininess;

		Display();

		break;

		// materiał - turkus

	case TURQUOISE:

		ambient = TurquoiseAmbient;

		diffuse = TurquoiseDiffuse;

		specular = TurquoiseSpecular;

		shininess = TurquoiseShininess;

		Display();

		break;

		// materiał - czarny plastik

	case BLACK_PLASTIC:

		ambient = BlackPlasticAmbient;

		diffuse = BlackPlasticDiffuse;

		specular = BlackPlasticSpecular;

		shininess = BlackPlasticShininess;

		Display();

		break;

		// materiał - czarna guma

	case BLACK_RUBBER:

		ambient = BlackRubberAmbient;

		diffuse = BlackRubberDiffuse;

		specular = BlackRubberSpecular;

		shininess = BlackRubberShininess;

		Display();

		break;

		// obszar renderingu - całe okno
	case FULL_WINDOW:
		aspect = FULL_WINDOW;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspect = ASPECT_1_1;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;
	case WIRED:
		wired = true;
		Display();
		break;
	case SOLID:
		wired = false;
		Display();
		break;
		// wyjście
	case EXIT:
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);

	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// rozmiary głównego okna programu
	glutInitWindowSize(400, 400);

	// utworzenie głównego okna programu
	glutCreateWindow("Stos modelowania");

	// dołączenie funkcji generującej scenę 3D
	glutDisplayFunc(Display);

	// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
	glutReshapeFunc(Reshape);

	// dołączenie funkcji obsługi klawiatury
	glutKeyboardFunc(Keyboard);

	// dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(SpecialKeys);

	// obsługa przycisków myszki
	glutMouseFunc(MouseButton);

	// obsługa ruchu kursora myszki
	glutMotionFunc(MouseMotion);

	// utworzenie podmenu - aspekt obrazu
	int MenuAspect = glutCreateMenu(Menu);

	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);

	int Menu3d = glutCreateMenu(Menu);

	glutAddMenuEntry("WIRED", WIRED);
	glutAddMenuEntry("SOLID", SOLID);

	int MenuMaterial = glutCreateMenu(Menu);

	glutAddMenuEntry("Mosiądz", BRASS);

	glutAddMenuEntry("Brąz", BRONZE);

	glutAddMenuEntry("Polerowany brąz", POLISHED_BRONZE);

	glutAddMenuEntry("Chrom", CHROME);

	glutAddMenuEntry("Miedź", COPPER);

	glutAddMenuEntry("Polerowana miedź", POLISHED_COPPER);

	glutAddMenuEntry("Złoto", GOLD);

	glutAddMenuEntry("Polerowane złoto", POLISHED_GOLD);

	glutAddMenuEntry("Grafit (cyna z ołowiem)", PEWTER);

	glutAddMenuEntry("Srebro", SILVER);

	glutAddMenuEntry("Polerowane srebro", POLISHED_SILVER);

	glutAddMenuEntry("Szmaragd", EMERALD);

	glutAddMenuEntry("Jadeit", JADE);

	glutAddMenuEntry("Obsydian", OBSIDIAN);

	glutAddMenuEntry("Perła", PEARL);

	glutAddMenuEntry("Rubin", RUBY);

	glutAddMenuEntry("Turkus", TURQUOISE);

	glutAddMenuEntry("Czarny plastik", BLACK_PLASTIC);

	glutAddMenuEntry("Czarna guma", BLACK_RUBBER);

	// menu główne
	glutCreateMenu(Menu);
	glutAddSubMenu("Aspekt obrazu", MenuAspect);
	glutAddSubMenu("Typ Piramidy", Menu3d);
	glutAddSubMenu("Materiał", MenuMaterial);
	glutAddMenuEntry("Wyjście", EXIT);

	// określenie przycisku myszki obsługującego menu podręczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// wprowadzenie programu do obsługi pętli komunikatów
	glutMainLoop();
	return 0;
}