// opengl_mipnapy_1d.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
/*
(c) Janusz Ganczarski
http://www.januszg.hg.pl
JanuszG@enter.net.pl
*/
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "glext.h"
// tekstura "tęcza" o szerokości 512 tekseli
unsigned char spectrum_512[512 * 3] =
{
	0xff, 0x3a, 0x01, 0xff, 0x3b, 0x01, 0xff, 0x3c, 0x01, 0xff, 0x3d, 0x01,
	0xff, 0x3e, 0x01, 0xff, 0x3f, 0x01, 0xff, 0x40, 0x01, 0xfe, 0x42, 0x01,
	0xfe, 0x43, 0x01, 0xfe, 0x43, 0x01, 0xfe, 0x45, 0x01, 0xfe, 0x46, 0x01,
	0xfe, 0x47, 0x01, 0xfe, 0x48, 0x01, 0xfe, 0x49, 0x01, 0xfe, 0x4b, 0x01,
	0xfe, 0x4c, 0x01, 0xfe, 0x4d, 0x01, 0xfe, 0x4e, 0x01, 0xfe, 0x4f, 0x01,
	0xfe, 0x4f, 0x01, 0xfe, 0x51, 0x01, 0xfe, 0x52, 0x01, 0xfe, 0x53, 0x01,
	0xfe, 0x54, 0x01, 0xfe, 0x55, 0x01, 0xfe, 0x57, 0x01, 0xfe, 0x58, 0x01,
	0xfe, 0x59, 0x01, 0xfd, 0x5a, 0x01, 0xfd, 0x5b, 0x01, 0xfd, 0x5c, 0x01,
	0xfd, 0x5d, 0x01, 0xfd, 0x5e, 0x01, 0xfd, 0x5f, 0x01, 0xfd, 0x60, 0x01,
	0xfd, 0x61, 0x01, 0xfd, 0x62, 0x01, 0xfd, 0x64, 0x01, 0xfd, 0x65, 0x01,
	0xfd, 0x66, 0x01, 0xfd, 0x67, 0x01, 0xfd, 0x68, 0x01, 0xfd, 0x69, 0x01,
	0xfd, 0x6a, 0x01, 0xfd, 0x6b, 0x01, 0xfd, 0x6d, 0x01, 0xfd, 0x6e, 0x01,
	0xfd, 0x6f, 0x01, 0xfd, 0x70, 0x01, 0xfd, 0x71, 0x01, 0xfd, 0x73, 0x01,
	0xfd, 0x73, 0x01, 0xfc, 0x74, 0x01, 0xfd, 0x76, 0x01, 0xfd, 0x77, 0x01,
	0xfc, 0x78, 0x01, 0xfc, 0x79, 0x01, 0xfc, 0x7a, 0x01, 0xfc, 0x7b, 0x01,
	0xfc, 0x7c, 0x01, 0xfc, 0x7e, 0x01, 0xfc, 0x7e, 0x01, 0xfc, 0x80, 0x01,
	0xfc, 0x81, 0x01, 0xfc, 0x82, 0x01, 0xfc, 0x83, 0x01, 0xfc, 0x84, 0x01,
	0xfc, 0x86, 0x01, 0xfc, 0x87, 0x01, 0xfc, 0x87, 0x01, 0xfc, 0x89, 0x01,
	0xfc, 0x8a, 0x01, 0xfc, 0x8a, 0x01, 0xfc, 0x8c, 0x01, 0xfc, 0x8d, 0x01,
	0xfc, 0x8e, 0x01, 0xfc, 0x8f, 0x01, 0xfb, 0x90, 0x01, 0xfb, 0x92, 0x01,
	0xfb, 0x92, 0x01, 0xfb, 0x93, 0x01, 0xfb, 0x95, 0x01, 0xfb, 0x96, 0x01,
	0xfb, 0x97, 0x01, 0xfb, 0x98, 0x01, 0xfb, 0x99, 0x01, 0xfb, 0x9a, 0x01,
	0xfb, 0x9c, 0x01, 0xfb, 0x9d, 0x00, 0xfb, 0x9e, 0x01, 0xfb, 0x9f, 0x01,
	0xfb, 0xa0, 0x01, 0xfb, 0xa1, 0x01, 0xfb, 0xa2, 0x01, 0xfb, 0xa3, 0x01,
	0xfb, 0xa4, 0x01, 0xfa, 0xa5, 0x01, 0xfa, 0xa6, 0x01, 0xfa, 0xa8, 0x01,
	0xfa, 0xa9, 0x01, 0xfa, 0xaa, 0x01, 0xfa, 0xab, 0x01, 0xfa, 0xac, 0x01,
	0xfa, 0xad, 0x01, 0xfa, 0xae, 0x01, 0xfa, 0xaf, 0x01, 0xfa, 0xb1, 0x01,
	0xfa, 0xb2, 0x01, 0xfa, 0xb3, 0x01, 0xfa, 0xb4, 0x01, 0xfa, 0xb5, 0x01,
	0xfa, 0xb6, 0x01, 0xfa, 0xb7, 0x01, 0xfa, 0xb8, 0x01, 0xfa, 0xba, 0x01,
	0xfa, 0xba, 0x01, 0xfa, 0xbb, 0x01, 0xfa, 0xbd, 0x01, 0xfa, 0xbe, 0x01,
	0xfa, 0xbf, 0x01, 0xfa, 0xc0, 0x01, 0xf9, 0xc1, 0x01, 0xf9, 0xc2, 0x01,
	0xfa, 0xc4, 0x01, 0xf9, 0xc5, 0x01, 0xf9, 0xc6, 0x01, 0xf9, 0xc7, 0x01,
	0xf9, 0xc8, 0x01, 0xf9, 0xca, 0x01, 0xf9, 0xca, 0x01, 0xf9, 0xcb, 0x01,
	0xf9, 0xcd, 0x01, 0xf9, 0xce, 0x01, 0xf9, 0xce, 0x01, 0xf9, 0xd0, 0x01,
	0xf9, 0xd1, 0x01, 0xf9, 0xd2, 0x01, 0xf9, 0xd3, 0x01, 0xf8, 0xd4, 0x01,
	0xf9, 0xd5, 0x01, 0xf9, 0xd6, 0x01, 0xf9, 0xd8, 0x01, 0xf9, 0xd9, 0x01,
	0xf8, 0xda, 0x01, 0xf8, 0xdb, 0x01, 0xf8, 0xdc, 0x01, 0xf8, 0xdd, 0x01,
	0xf8, 0xde, 0x01, 0xf8, 0xdf, 0x01, 0xf8, 0xe0, 0x01, 0xf8, 0xe2, 0x01,
	0xf8, 0xe3, 0x01, 0xf8, 0xe4, 0x01, 0xf8, 0xe5, 0x01, 0xf8, 0xe6, 0x01,
	0xf8, 0xe7, 0x01, 0xf8, 0xe8, 0x01, 0xf8, 0xe9, 0x01, 0xf8, 0xea, 0x01,
	0xf8, 0xeb, 0x01, 0xf8, 0xed, 0x01, 0xf8, 0xed, 0x01, 0xf8, 0xef, 0x01,
	0xf8, 0xf0, 0x01, 0xf8, 0xf1, 0x01, 0xf8, 0xf2, 0x01, 0xf7, 0xf3, 0x01,
	0xf7, 0xf4, 0x01, 0xf7, 0xf5, 0x01, 0xf7, 0xf6, 0x01, 0xf7, 0xf8, 0x01,
	0xf7, 0xf9, 0x01, 0xf7, 0xfa, 0x01, 0xf7, 0xfb, 0x01, 0xf7, 0xfc, 0x01,
	0xf7, 0xfd, 0x01, 0xf6, 0xfe, 0x01, 0xf6, 0xfe, 0x01, 0xf5, 0xfe, 0x02,
	0xf4, 0xfd, 0x03, 0xf3, 0xfd, 0x03, 0xf1, 0xfc, 0x04, 0xf0, 0xfb, 0x05,
	0xef, 0xfa, 0x05, 0xee, 0xfa, 0x06, 0xec, 0xf9, 0x07, 0xeb, 0xf8, 0x07,
	0xea, 0xf7, 0x08, 0xe8, 0xf7, 0x08, 0xe7, 0xf6, 0x09, 0xe6, 0xf5, 0x09,
	0xe4, 0xf5, 0x0a, 0xe3, 0xf4, 0x0b, 0xe2, 0xf3, 0x0b, 0xe1, 0xf2, 0x0c,
	0xdf, 0xf1, 0x0c, 0xde, 0xf1, 0x0d, 0xdd, 0xf0, 0x0e, 0xdc, 0xef, 0x0e,
	0xda, 0xee, 0x0f, 0xd8, 0xee, 0x10, 0xd8, 0xed, 0x10, 0xd6, 0xec, 0x11,
	0xd5, 0xec, 0x11, 0xd4, 0xeb, 0x12, 0xd3, 0xea, 0x12, 0xd1, 0xea, 0x13,
	0xd0, 0xe9, 0x14, 0xcf, 0xe8, 0x14, 0xce, 0xe8, 0x15, 0xcc, 0xe7, 0x16,
	0xcb, 0xe6, 0x16, 0xca, 0xe5, 0x17, 0xc8, 0xe5, 0x18, 0xc7, 0xe4, 0x18,
	0xc6, 0xe3, 0x19, 0xc5, 0xe2, 0x19, 0xc3, 0xe2, 0x1a, 0xc2, 0xe1, 0x1a,
	0xc1, 0xe0, 0x1b, 0xc0, 0xdf, 0x1c, 0xbe, 0xdf, 0x1d, 0xbd, 0xde, 0x1d,
	0xbc, 0xdd, 0x1e, 0xbb, 0xdd, 0x1e, 0xb9, 0xdc, 0x1f, 0xb8, 0xdb, 0x20,
	0xb7, 0xda, 0x20, 0xb5, 0xda, 0x21, 0xb4, 0xd9, 0x22, 0xb3, 0xd8, 0x22,
	0xb1, 0xd8, 0x23, 0xb0, 0xd7, 0x24, 0xaf, 0xd6, 0x24, 0xae, 0xd5, 0x25,
	0xad, 0xd5, 0x25, 0xac, 0xd4, 0x26, 0xaa, 0xd3, 0x27, 0xa9, 0xd3, 0x27,
	0xa7, 0xd2, 0x28, 0xa6, 0xd1, 0x29, 0xa5, 0xd1, 0x29, 0xa3, 0xd0, 0x2a,
	0xa2, 0xcf, 0x2a, 0xa1, 0xce, 0x2b, 0xa0, 0xce, 0x2c, 0x9f, 0xcd, 0x2c,
	0x9e, 0xcc, 0x2d, 0x9c, 0xcb, 0x2d, 0x9b, 0xcb, 0x2e, 0x9a, 0xca, 0x2f,
	0x99, 0xc9, 0x30, 0x97, 0xc8, 0x30, 0x96, 0xc8, 0x31, 0x95, 0xc7, 0x32,
	0x94, 0xc6, 0x32, 0x92, 0xc6, 0x33, 0x91, 0xc5, 0x34, 0x90, 0xc4, 0x34,
	0x8e, 0xc3, 0x35, 0x8d, 0xc3, 0x35, 0x8c, 0xc2, 0x36, 0x8b, 0xc1, 0x36,
	0x8a, 0xc1, 0x37, 0x88, 0xc0, 0x38, 0x87, 0xbf, 0x38, 0x85, 0xbe, 0x39,
	0x84, 0xbe, 0x3a, 0x83, 0xbd, 0x3a, 0x82, 0xbc, 0x3b, 0x80, 0xbc, 0x3b,
	0x7f, 0xbb, 0x3c, 0x7e, 0xba, 0x3d, 0x7d, 0xba, 0x3d, 0x7b, 0xb9, 0x3e,
	0x7a, 0xb8, 0x3f, 0x79, 0xb7, 0x3f, 0x77, 0xb7, 0x40, 0x76, 0xb6, 0x40,
	0x75, 0xb5, 0x41, 0x74, 0xb4, 0x41, 0x72, 0xb4, 0x42, 0x71, 0xb3, 0x43,
	0x70, 0xb2, 0x43, 0x6e, 0xb1, 0x44, 0x6d, 0xb1, 0x45, 0x6c, 0xb0, 0x45,
	0x6b, 0xaf, 0x46, 0x6a, 0xae, 0x46, 0x68, 0xae, 0x47, 0x67, 0xad, 0x48,
	0x66, 0xac, 0x48, 0x64, 0xab, 0x49, 0x63, 0xab, 0x49, 0x62, 0xaa, 0x4a,
	0x60, 0xa9, 0x4b, 0x5f, 0xa8, 0x4b, 0x5e, 0xa8, 0x4c, 0x5c, 0xa7, 0x4d,
	0x5b, 0xa6, 0x4d, 0x5a, 0xa5, 0x4e, 0x59, 0xa5, 0x4e, 0x58, 0xa4, 0x4f,
	0x56, 0xa3, 0x50, 0x55, 0xa3, 0x50, 0x54, 0xa2, 0x51, 0x52, 0xa1, 0x52,
	0x51, 0xa1, 0x52, 0x51, 0xa0, 0x53, 0x50, 0x9f, 0x54, 0x4f, 0x9e, 0x54,
	0x4f, 0x9d, 0x55, 0x4f, 0x9c, 0x56, 0x4e, 0x9b, 0x57, 0x4e, 0x9a, 0x58,
	0x4e, 0x99, 0x58, 0x4d, 0x99, 0x59, 0x4d, 0x97, 0x5a, 0x4d, 0x97, 0x5a,
	0x4c, 0x96, 0x5b, 0x4c, 0x95, 0x5c, 0x4c, 0x94, 0x5c, 0x4b, 0x93, 0x5d,
	0x4b, 0x92, 0x5e, 0x4b, 0x91, 0x5f, 0x4b, 0x90, 0x60, 0x4a, 0x90, 0x60,
	0x4a, 0x8f, 0x61, 0x4a, 0x8e, 0x62, 0x49, 0x8d, 0x63, 0x49, 0x8c, 0x63,
	0x48, 0x8b, 0x64, 0x48, 0x8a, 0x65, 0x48, 0x89, 0x65, 0x47, 0x88, 0x66,
	0x47, 0x87, 0x67, 0x47, 0x86, 0x67, 0x46, 0x85, 0x68, 0x46, 0x84, 0x69,
	0x45, 0x83, 0x6a, 0x45, 0x83, 0x6a, 0x45, 0x82, 0x6b, 0x45, 0x81, 0x6c,
	0x45, 0x80, 0x6d, 0x44, 0x7f, 0x6d, 0x44, 0x7e, 0x6e, 0x43, 0x7d, 0x6f,
	0x43, 0x7d, 0x6f, 0x43, 0x7b, 0x70, 0x42, 0x7b, 0x71, 0x42, 0x7a, 0x72,
	0x42, 0x79, 0x72, 0x41, 0x78, 0x73, 0x41, 0x77, 0x74, 0x41, 0x76, 0x75,
	0x41, 0x75, 0x75, 0x40, 0x74, 0x76, 0x40, 0x73, 0x77, 0x40, 0x72, 0x77,
	0x3f, 0x71, 0x78, 0x3f, 0x70, 0x79, 0x3f, 0x70, 0x7a, 0x3e, 0x6f, 0x7b,
	0x3e, 0x6e, 0x7b, 0x3e, 0x6d, 0x7c, 0x3d, 0x6c, 0x7d, 0x3d, 0x6b, 0x7d,
	0x3c, 0x6a, 0x7e, 0x3c, 0x69, 0x7f, 0x3c, 0x69, 0x80, 0x3b, 0x67, 0x80,
	0x3b, 0x67, 0x81, 0x3b, 0x66, 0x82, 0x3b, 0x65, 0x83, 0x3a, 0x64, 0x83,
	0x3a, 0x63, 0x84, 0x3a, 0x62, 0x85, 0x39, 0x61, 0x86, 0x39, 0x60, 0x86,
	0x39, 0x5f, 0x87, 0x38, 0x5e, 0x88, 0x38, 0x5d, 0x89, 0x38, 0x5c, 0x89,
	0x37, 0x5c, 0x8a, 0x37, 0x5a, 0x8b, 0x37, 0x5a, 0x8b, 0x37, 0x59, 0x8c,
	0x36, 0x58, 0x8d, 0x36, 0x57, 0x8d, 0x36, 0x56, 0x8e, 0x35, 0x55, 0x8f,
	0x35, 0x54, 0x90, 0x35, 0x53, 0x90, 0x34, 0x53, 0x91, 0x34, 0x52, 0x92,
	0x33, 0x51, 0x93, 0x33, 0x50, 0x93, 0x33, 0x4f, 0x94, 0x32, 0x4e, 0x95,
	0x32, 0x4d, 0x95, 0x32, 0x4c, 0x96, 0x31, 0x4b, 0x97, 0x31, 0x4a, 0x98,
	0x31, 0x49, 0x99, 0x30, 0x48, 0x99, 0x30, 0x47, 0x9a, 0x30, 0x46, 0x9b,
	0x30, 0x45, 0x9b, 0x2f, 0x45, 0x9c, 0x2f, 0x44, 0x9d, 0x2f, 0x43, 0x9e,
	0x2e, 0x42, 0x9e, 0x2e, 0x41, 0x9f, 0x2d, 0x40, 0xa0, 0x2d, 0x3f, 0xa1,
	0x2d, 0x3e, 0xa1, 0x2d, 0x3d, 0xa2, 0x2c, 0x3c, 0xa3, 0x2c, 0x3b, 0xa3,
	0x2c, 0x3a, 0xa4, 0x2c, 0x39, 0xa5, 0x2b, 0x39, 0xa6, 0x2b, 0x38, 0xa6,
	0x2a, 0x37, 0xa7, 0x2a, 0x36, 0xa8, 0x2a, 0x35, 0xa8, 0x29, 0x34, 0xa9,
	0x29, 0x33, 0xaa, 0x28, 0x32, 0xab, 0x28, 0x32, 0xab, 0x27, 0x31, 0xac,
	0x27, 0x2f, 0xad, 0x27, 0x2f, 0xae, 0x26, 0x2e, 0xae, 0x26, 0x2d, 0xaf,
	0x26, 0x2c, 0xb0, 0x26, 0x2b, 0xb0, 0x26, 0x2a, 0xb1, 0x25, 0x29, 0xb2,
	0x25, 0x28, 0xb3, 0x25, 0x28, 0xb3, 0x24, 0x26, 0xb4, 0x24, 0x25, 0xb5,
	0x24, 0x25, 0xb5, 0x24, 0x24, 0xb6, 0x24, 0x23, 0xb5, 0x24, 0x23, 0xb5,
	0x24, 0x23, 0xb5, 0x25, 0x23, 0xb4, 0x25, 0x23, 0xb3, 0x25, 0x23, 0xb3,
	0x26, 0x23, 0xb1, 0x26, 0x23, 0xb0, 0x27, 0x23, 0xaf, 0x27, 0x23, 0xae,
	0x27, 0x24, 0xae, 0x28, 0x24, 0xad, 0x28, 0x24, 0xac, 0x29, 0x24, 0xab,
	0x29, 0x24, 0xaa, 0x2a, 0x24, 0xa9, 0x2a, 0x24, 0xa8, 0x2b, 0x24, 0xa7,
	0x2b, 0x24, 0xa6, 0x2c, 0x24, 0xa5, 0x2c, 0x24, 0xa5, 0x2d, 0x24, 0xa4,
	0x2d, 0x24, 0xa3, 0x2e, 0x24, 0xa2, 0x2e, 0x24, 0xa1, 0x2e, 0x24, 0xa0,
	0x2f, 0x24, 0x9f, 0x2f, 0x25, 0x9f, 0x2f, 0x25, 0x9e, 0x30, 0x25, 0x9d,
	0x30, 0x25, 0x9c, 0x31, 0x25, 0x9a, 0x31, 0x25, 0x9a, 0x32, 0x25, 0x98,
	0x32, 0x25, 0x98, 0x33, 0x25, 0x97, 0x33, 0x25, 0x96, 0x33, 0x25, 0x95,
	0x34, 0x25, 0x95, 0x34, 0x25, 0x93, 0x35, 0x25, 0x92, 0x35, 0x25, 0x92,
	0x36, 0x25, 0x91, 0x36, 0x25, 0x90, 0x37, 0x25, 0x8f, 0x37, 0x25, 0x8e,
	0x37, 0x25, 0x8e, 0x38, 0x26, 0x8c, 0x38, 0x26, 0x8b, 0x39, 0x26, 0x8b,
	0x39, 0x26, 0x8a, 0x3a, 0x26, 0x89, 0x3a, 0x26, 0x88, 0x3b, 0x26, 0x87,
	0x3b, 0x26, 0x86, 0x3c, 0x26, 0x86, 0x3c, 0x26, 0x84, 0x3d, 0x26, 0x83,
	0x3d, 0x26, 0x82, 0x3e, 0x26, 0x82, 0x3e, 0x26, 0x81, 0x3f, 0x26, 0x80,
	0x3f, 0x26, 0x7f, 0x3f, 0x27, 0x7e, 0x40, 0x27, 0x7d, 0x40, 0x27, 0x7c
};
// tekstura "tęcza" o szerokości 256 tekseli
unsigned char spectrum_256[256 * 3] =
{
	0xff, 0x3b, 0x01, 0xff, 0x3d, 0x01, 0xff, 0x3f, 0x01, 0xff, 0x41, 0x01,
	0xfe, 0x43, 0x01, 0xfe, 0x46, 0x01, 0xfe, 0x48, 0x01, 0xfe, 0x4a, 0x01,
	0xfe, 0x4d, 0x01, 0xfe, 0x4f, 0x01, 0xfe, 0x50, 0x01, 0xfe, 0x53, 0x01,
	0xfe, 0x55, 0x01, 0xfe, 0x58, 0x01, 0xfe, 0x5a, 0x01, 0xfd, 0x5c, 0x01,
	0xfd, 0x5e, 0x01, 0xfd, 0x60, 0x01, 0xfd, 0x62, 0x01, 0xfd, 0x65, 0x01,
	0xfd, 0x67, 0x01, 0xfd, 0x69, 0x01, 0xfd, 0x6b, 0x01, 0xfd, 0x6e, 0x01,
	0xfd, 0x70, 0x01, 0xfd, 0x72, 0x01, 0xfd, 0x74, 0x01, 0xfd, 0x77, 0x01,
	0xfc, 0x79, 0x01, 0xfc, 0x7b, 0x01, 0xfc, 0x7d, 0x01, 0xfc, 0x7f, 0x01,
	0xfc, 0x82, 0x01, 0xfc, 0x84, 0x01, 0xfc, 0x87, 0x01, 0xfc, 0x88, 0x01,
	0xfc, 0x8a, 0x01, 0xfc, 0x8d, 0x01, 0xfc, 0x8f, 0x01, 0xfb, 0x91, 0x01,
	0xfb, 0x93, 0x01, 0xfb, 0x96, 0x01, 0xfb, 0x98, 0x01, 0xfb, 0x9a, 0x01,
	0xfb, 0x9d, 0x01, 0xfb, 0x9f, 0x01, 0xfb, 0xa1, 0x01, 0xfb, 0xa3, 0x01,
	0xfb, 0xa5, 0x01, 0xfa, 0xa7, 0x01, 0xfa, 0xaa, 0x01, 0xfa, 0xac, 0x01,
	0xfa, 0xae, 0x01, 0xfa, 0xb0, 0x01, 0xfa, 0xb3, 0x01, 0xfa, 0xb5, 0x01,
	0xfa, 0xb7, 0x01, 0xfa, 0xb9, 0x01, 0xfa, 0xbb, 0x01, 0xfa, 0xbe, 0x01,
	0xfa, 0xc0, 0x01, 0xf9, 0xc2, 0x01, 0xfa, 0xc5, 0x01, 0xf9, 0xc7, 0x01,
	0xf9, 0xc9, 0x01, 0xf9, 0xcb, 0x01, 0xf9, 0xce, 0x01, 0xf9, 0xcf, 0x01,
	0xf9, 0xd2, 0x01, 0xf9, 0xd4, 0x01, 0xf9, 0xd6, 0x01, 0xf9, 0xd9, 0x01,
	0xf8, 0xdb, 0x01, 0xf8, 0xdd, 0x01, 0xf8, 0xdf, 0x01, 0xf8, 0xe1, 0x01,
	0xf8, 0xe4, 0x01, 0xf8, 0xe6, 0x01, 0xf8, 0xe8, 0x01, 0xf8, 0xea, 0x01,
	0xf8, 0xec, 0x01, 0xf8, 0xee, 0x01, 0xf8, 0xf1, 0x01, 0xf8, 0xf3, 0x01,
	0xf7, 0xf5, 0x01, 0xf7, 0xf7, 0x01, 0xf7, 0xfa, 0x01, 0xf7, 0xfc, 0x01,
	0xf7, 0xfe, 0x01, 0xf6, 0xfe, 0x02, 0xf4, 0xfd, 0x03, 0xf1, 0xfc, 0x05,
	0xef, 0xfa, 0x06, 0xec, 0xf9, 0x07, 0xe9, 0xf7, 0x08, 0xe7, 0xf6, 0x09,
	0xe4, 0xf5, 0x0b, 0xe2, 0xf3, 0x0c, 0xdf, 0xf1, 0x0d, 0xdd, 0xf0, 0x0e,
	0xd9, 0xee, 0x10, 0xd7, 0xed, 0x11, 0xd5, 0xec, 0x12, 0xd2, 0xea, 0x13,
	0xd0, 0xe9, 0x14, 0xcd, 0xe8, 0x16, 0xcb, 0xe6, 0x17, 0xc8, 0xe5, 0x18,
	0xc6, 0xe3, 0x19, 0xc3, 0xe2, 0x1a, 0xc1, 0xe0, 0x1c, 0xbe, 0xdf, 0x1d,
	0xbc, 0xdd, 0x1e, 0xb9, 0xdc, 0x20, 0xb6, 0xda, 0x21, 0xb4, 0xd9, 0x22,
	0xb1, 0xd8, 0x24, 0xaf, 0xd6, 0x25, 0xad, 0xd5, 0x26, 0xaa, 0xd3, 0x27,
	0xa7, 0xd2, 0x29, 0xa4, 0xd1, 0x2a, 0xa2, 0xcf, 0x2b, 0xa0, 0xce, 0x2c,
	0x9d, 0xcc, 0x2d, 0x9b, 0xcb, 0x2f, 0x98, 0xc9, 0x30, 0x96, 0xc8, 0x32,
	0x93, 0xc6, 0x33, 0x91, 0xc5, 0x34, 0x8e, 0xc3, 0x35, 0x8c, 0xc2, 0x36,
	0x89, 0xc1, 0x38, 0x86, 0xbf, 0x39, 0x84, 0xbe, 0x3a, 0x81, 0xbc, 0x3b,
	0x7f, 0xbb, 0x3d, 0x7c, 0xba, 0x3e, 0x7a, 0xb8, 0x3f, 0x77, 0xb7, 0x40,
	0x75, 0xb5, 0x41, 0x72, 0xb4, 0x43, 0x6f, 0xb2, 0x44, 0x6d, 0xb1, 0x45,
	0x6b, 0xaf, 0x46, 0x68, 0xae, 0x48, 0x65, 0xac, 0x49, 0x63, 0xab, 0x4a,
	0x60, 0xa9, 0x4b, 0x5d, 0xa8, 0x4d, 0x5b, 0xa6, 0x4e, 0x59, 0xa5, 0x4f,
	0x56, 0xa3, 0x50, 0x53, 0xa2, 0x52, 0x51, 0xa1, 0x53, 0x50, 0x9f, 0x54,
	0x4f, 0x9d, 0x56, 0x4e, 0x9b, 0x58, 0x4e, 0x99, 0x59, 0x4d, 0x97, 0x5a,
	0x4c, 0x96, 0x5c, 0x4c, 0x94, 0x5d, 0x4b, 0x92, 0x5f, 0x4b, 0x90, 0x60,
	0x4a, 0x8f, 0x62, 0x49, 0x8d, 0x63, 0x48, 0x8b, 0x65, 0x48, 0x89, 0x66,
	0x47, 0x87, 0x67, 0x46, 0x85, 0x69, 0x45, 0x83, 0x6a, 0x45, 0x82, 0x6c,
	0x45, 0x80, 0x6d, 0x44, 0x7e, 0x6f, 0x43, 0x7c, 0x70, 0x42, 0x7b, 0x72,
	0x42, 0x79, 0x73, 0x41, 0x77, 0x75, 0x41, 0x75, 0x76, 0x40, 0x73, 0x77,
	0x3f, 0x71, 0x79, 0x3f, 0x70, 0x7b, 0x3e, 0x6e, 0x7c, 0x3d, 0x6c, 0x7d,
	0x3c, 0x6a, 0x7f, 0x3c, 0x68, 0x80, 0x3b, 0x67, 0x82, 0x3b, 0x65, 0x83,
	0x3a, 0x63, 0x85, 0x39, 0x61, 0x86, 0x39, 0x5f, 0x88, 0x38, 0x5d, 0x89,
	0x37, 0x5b, 0x8b, 0x37, 0x5a, 0x8c, 0x36, 0x58, 0x8d, 0x36, 0x56, 0x8f,
	0x35, 0x54, 0x90, 0x34, 0x53, 0x92, 0x33, 0x51, 0x93, 0x33, 0x4f, 0x95,
	0x32, 0x4d, 0x96, 0x31, 0x4b, 0x98, 0x31, 0x49, 0x99, 0x30, 0x47, 0x9b,
	0x30, 0x45, 0x9c, 0x2f, 0x44, 0x9e, 0x2e, 0x42, 0x9f, 0x2d, 0x40, 0xa1,
	0x2d, 0x3e, 0xa2, 0x2c, 0x3c, 0xa3, 0x2c, 0x3a, 0xa5, 0x2b, 0x39, 0xa6,
	0x2a, 0x37, 0xa8, 0x2a, 0x35, 0xa9, 0x29, 0x33, 0xab, 0x28, 0x32, 0xac,
	0x27, 0x2f, 0xae, 0x26, 0x2e, 0xaf, 0x26, 0x2c, 0xb0, 0x26, 0x2a, 0xb2,
	0x25, 0x28, 0xb3, 0x24, 0x26, 0xb5, 0x24, 0x25, 0xb6, 0x24, 0x23, 0xb5,
	0x25, 0x23, 0xb5, 0x25, 0x23, 0xb3, 0x26, 0x23, 0xb1, 0x27, 0x23, 0xaf,
	0x28, 0x24, 0xae, 0x29, 0x24, 0xac, 0x2a, 0x24, 0xaa, 0x2b, 0x24, 0xa8,
	0x2c, 0x24, 0xa6, 0x2d, 0x24, 0xa5, 0x2e, 0x24, 0xa3, 0x2e, 0x24, 0xa1,
	0x2f, 0x25, 0x9f, 0x30, 0x25, 0x9e, 0x31, 0x25, 0x9b, 0x32, 0x25, 0x99,
	0x33, 0x25, 0x98, 0x33, 0x25, 0x96, 0x34, 0x25, 0x94, 0x35, 0x25, 0x92,
	0x36, 0x25, 0x91, 0x37, 0x25, 0x8f, 0x38, 0x26, 0x8d, 0x39, 0x26, 0x8b,
	0x3a, 0x26, 0x8a, 0x3b, 0x26, 0x88, 0x3c, 0x26, 0x86, 0x3d, 0x26, 0x84,
	0x3e, 0x26, 0x82, 0x3f, 0x26, 0x81, 0x3f, 0x27, 0x7f, 0x40, 0x27, 0x7d
};
// tekstura "tęcza" o szerokości 128 tekseli
unsigned char spectrum_128[128 * 3] =
{
	0xff, 0x3c, 0x01, 0xff, 0x40, 0x01, 0xfe, 0x44, 0x01, 0xfe, 0x49, 0x01,
	0xfe, 0x4e, 0x01, 0xfe, 0x51, 0x01, 0xfe, 0x56, 0x01, 0xfd, 0x5b, 0x01,
	0xfd, 0x5f, 0x01, 0xfd, 0x63, 0x01, 0xfd, 0x68, 0x01, 0xfd, 0x6c, 0x01,
	0xfd, 0x71, 0x01, 0xfd, 0x75, 0x01, 0xfc, 0x7a, 0x01, 0xfc, 0x7e, 0x01,
	0xfc, 0x83, 0x01, 0xfc, 0x87, 0x01, 0xfc, 0x8b, 0x01, 0xfc, 0x90, 0x01,
	0xfb, 0x94, 0x01, 0xfb, 0x99, 0x01, 0xfb, 0x9e, 0x01, 0xfb, 0xa2, 0x01,
	0xfa, 0xa6, 0x01, 0xfa, 0xab, 0x01, 0xfa, 0xaf, 0x01, 0xfa, 0xb4, 0x01,
	0xfa, 0xb8, 0x01, 0xfa, 0xbc, 0x01, 0xfa, 0xc1, 0x01, 0xf9, 0xc6, 0x01,
	0xf9, 0xca, 0x01, 0xf9, 0xce, 0x01, 0xf9, 0xd3, 0x01, 0xf9, 0xd7, 0x01,
	0xf8, 0xdc, 0x01, 0xf8, 0xe0, 0x01, 0xf8, 0xe5, 0x01, 0xf8, 0xe9, 0x01,
	0xf8, 0xed, 0x01, 0xf8, 0xf2, 0x01, 0xf7, 0xf6, 0x01, 0xf7, 0xfb, 0x01,
	0xf6, 0xfe, 0x01, 0xf2, 0xfc, 0x04, 0xed, 0xf9, 0x06, 0xe8, 0xf6, 0x09,
	0xe3, 0xf4, 0x0b, 0xde, 0xf0, 0x0d, 0xd8, 0xed, 0x10, 0xd3, 0xeb, 0x12,
	0xce, 0xe8, 0x15, 0xc9, 0xe5, 0x17, 0xc4, 0xe2, 0x1a, 0xbf, 0xdf, 0x1c,
	0xba, 0xdc, 0x1f, 0xb5, 0xd9, 0x21, 0xb0, 0xd7, 0x24, 0xab, 0xd4, 0x26,
	0xa5, 0xd1, 0x29, 0xa1, 0xce, 0x2b, 0x9c, 0xcb, 0x2e, 0x97, 0xc8, 0x31,
	0x92, 0xc5, 0x33, 0x8d, 0xc2, 0x36, 0x88, 0xc0, 0x38, 0x82, 0xbd, 0x3b,
	0x7d, 0xba, 0x3d, 0x78, 0xb7, 0x40, 0x73, 0xb4, 0x42, 0x6e, 0xb1, 0x44,
	0x69, 0xae, 0x47, 0x64, 0xab, 0x49, 0x5e, 0xa8, 0x4c, 0x5a, 0xa5, 0x4e,
	0x54, 0xa2, 0x51, 0x50, 0xa0, 0x53, 0x4f, 0x9c, 0x57, 0x4d, 0x98, 0x59,
	0x4c, 0x95, 0x5c, 0x4b, 0x91, 0x5f, 0x4a, 0x8e, 0x62, 0x48, 0x8a, 0x65,
	0x47, 0x86, 0x68, 0x45, 0x82, 0x6b, 0x44, 0x7f, 0x6e, 0x43, 0x7b, 0x71,
	0x41, 0x78, 0x74, 0x40, 0x74, 0x76, 0x3f, 0x70, 0x7a, 0x3e, 0x6d, 0x7c,
	0x3c, 0x69, 0x7f, 0x3b, 0x66, 0x82, 0x3a, 0x62, 0x85, 0x38, 0x5e, 0x88,
	0x37, 0x5a, 0x8b, 0x36, 0x57, 0x8e, 0x35, 0x53, 0x91, 0x33, 0x50, 0x94,
	0x32, 0x4c, 0x97, 0x30, 0x48, 0x9a, 0x2f, 0x44, 0x9d, 0x2e, 0x41, 0xa0,
	0x2d, 0x3d, 0xa2, 0x2c, 0x39, 0xa5, 0x2a, 0x36, 0xa8, 0x28, 0x32, 0xab,
	0x27, 0x2e, 0xae, 0x26, 0x2b, 0xb1, 0x25, 0x27, 0xb4, 0x24, 0x24, 0xb5,
	0x25, 0x23, 0xb4, 0x27, 0x23, 0xb0, 0x28, 0x24, 0xad, 0x2a, 0x24, 0xa9,
	0x2c, 0x24, 0xa5, 0x2e, 0x24, 0xa2, 0x2f, 0x25, 0x9e, 0x31, 0x25, 0x9a,
	0x33, 0x25, 0x97, 0x35, 0x25, 0x93, 0x37, 0x25, 0x90, 0x38, 0x26, 0x8c,
	0x3a, 0x26, 0x89, 0x3c, 0x26, 0x85, 0x3e, 0x26, 0x81, 0x40, 0x27, 0x7e
};
// tekstura "tęcza" o szerokości 64 tekseli
unsigned char spectrum_64[64 * 3] =
{
	0xff, 0x3e, 0x01, 0xfe, 0x47, 0x01, 0xfe, 0x4f, 0x01, 0xfe, 0x58, 0x01,
	0xfd, 0x61, 0x01, 0xfd, 0x6a, 0x01, 0xfd, 0x73, 0x01, 0xfc, 0x7c, 0x01,
	0xfc, 0x85, 0x01, 0xfc, 0x8e, 0x01, 0xfb, 0x96, 0x01, 0xfb, 0xa0, 0x01,
	0xfa, 0xa8, 0x01, 0xfa, 0xb1, 0x01, 0xfa, 0xba, 0x01, 0xf9, 0xc3, 0x01,
	0xf9, 0xcc, 0x01, 0xf9, 0xd5, 0x01, 0xf8, 0xde, 0x01, 0xf8, 0xe7, 0x01,
	0xf8, 0xef, 0x01, 0xf7, 0xf8, 0x01, 0xf4, 0xfd, 0x03, 0xea, 0xf8, 0x07,
	0xe0, 0xf2, 0x0c, 0xd6, 0xec, 0x11, 0xcc, 0xe7, 0x16, 0xc2, 0xe1, 0x1b,
	0xb7, 0xdb, 0x20, 0xad, 0xd5, 0x25, 0xa3, 0xd0, 0x2a, 0x99, 0xca, 0x2f,
	0x8f, 0xc4, 0x34, 0x85, 0xbe, 0x39, 0x7b, 0xb9, 0x3e, 0x70, 0xb3, 0x43,
	0x66, 0xad, 0x48, 0x5c, 0xa7, 0x4d, 0x52, 0xa1, 0x52, 0x4e, 0x9a, 0x58,
	0x4b, 0x93, 0x5e, 0x49, 0x8c, 0x64, 0x46, 0x84, 0x69, 0x43, 0x7d, 0x6f,
	0x41, 0x76, 0x75, 0x3e, 0x6e, 0x7b, 0x3b, 0x67, 0x81, 0x39, 0x60, 0x87,
	0x36, 0x58, 0x8c, 0x34, 0x51, 0x92, 0x31, 0x4a, 0x98, 0x2e, 0x42, 0x9e,
	0x2c, 0x3b, 0xa4, 0x29, 0x34, 0xaa, 0x26, 0x2c, 0xaf, 0x24, 0x25, 0xb5,
	0x26, 0x23, 0xb2, 0x29, 0x24, 0xab, 0x2d, 0x24, 0xa3, 0x30, 0x25, 0x9c,
	0x34, 0x25, 0x95, 0x37, 0x25, 0x8e, 0x3b, 0x26, 0x87, 0x3f, 0x26, 0x7f
};
// tekstura "tęcza" o szerokości 32 tekseli
unsigned char spectrum_32[32 * 3] =
{
	0xfe, 0x42, 0x01, 0xfe, 0x54, 0x01, 0xfd, 0x65, 0x01, 0xfc, 0x77, 0x01,
	0xfc, 0x89, 0x01, 0xfb, 0x9b, 0x01, 0xfa, 0xad, 0x01, 0xfa, 0xbe, 0x01,
	0xf9, 0xd0, 0x01, 0xf8, 0xe2, 0x01, 0xf7, 0xf4, 0x01, 0xef, 0xfa, 0x05,
	0xdb, 0xef, 0x0f, 0xc7, 0xe4, 0x18, 0xb2, 0xd8, 0x23, 0x9e, 0xcd, 0x2d,
	0x8a, 0xc1, 0x37, 0x76, 0xb6, 0x41, 0x61, 0xaa, 0x4a, 0x50, 0x9d, 0x55,
	0x4a, 0x8f, 0x61, 0x45, 0x80, 0x6c, 0x3f, 0x72, 0x78, 0x3a, 0x63, 0x84,
	0x35, 0x55, 0x8f, 0x30, 0x46, 0x9b, 0x2a, 0x37, 0xa7, 0x25, 0x29, 0xb2,
	0x27, 0x24, 0xae, 0x2f, 0x24, 0xa0, 0x35, 0x25, 0x91, 0x3d, 0x26, 0x83
};
// tekstura "tęcza" o szerokości 16 tekseli
unsigned char spectrum_16[16 * 3] =
{
	0xfe, 0x4b, 0x01, 0xfd, 0x6e, 0x01, 0xfb, 0x92, 0x01, 0xfa, 0xb6, 0x01,
	0xf8, 0xd9, 0x01, 0xf3, 0xf7, 0x03, 0xd1, 0xe9, 0x14, 0xa8, 0xd2, 0x28,
	0x80, 0xbb, 0x3c, 0x59, 0xa3, 0x50, 0x47, 0x88, 0x66, 0x3d, 0x6b, 0x7e,
	0x32, 0x4d, 0x95, 0x28, 0x30, 0xac, 0x2b, 0x24, 0xa7, 0x39, 0x26, 0x8a
};
// tekstura "tęcza" o szerokości 8 tekseli
unsigned char spectrum_8[8 * 3] =
{
	0xfd, 0x5d, 0x01, 0xfb, 0xa4, 0x01, 0xf6, 0xe8, 0x02, 0xbd, 0xde, 0x1e,
	0x6c, 0xb0, 0x46, 0x42, 0x7a, 0x72, 0x2d, 0x3f, 0xa1, 0x32, 0x25, 0x99
};
// tekstura "tęcza" o szerokości 4 tekseli
unsigned char spectrum_4[4 * 3] =
{
	0xfc, 0x80, 0x01, 0xd9, 0xe3, 0x10, 0x57, 0x94, 0x5c, 0x30, 0x32, 0x9d
};
// tekstura "tęcza" o szerokości 2 tekseli
unsigned char spectrum_2[2 * 3] =
{
	0xeb, 0xb2, 0x08, 0x43, 0x63, 0x7c
};
// tekstura "tęcza" o szerokości 1 teksela
unsigned char spectrum_1[1 * 3] =
{
	0x97, 0x8a, 0x42
};
// stałe do obsługi menu podręcznego
enum
{
	FULL_WINDOW, // aspekt obrazu - całe okno
	ASPECT_1_1, // aspekt obrazu 1:1
	EXIT // wyjście
};
// aspekt obrazu
int aspect = FULL_WINDOW;
// usunięcie definicji makr near i far
#ifdef near
#undef near
#endif
#ifdef far
#undef far
#endif
// rozmiary bryły obcinania
const GLdouble left = -2.0;
const GLdouble right = 2.0;
const GLdouble bottom = -2.0;
const GLdouble top = 2.0;
const GLdouble near = 3.0;
const GLdouble far = 7.0;
// współczynnik skalowania
GLfloat scale = 0.5;
// identyfikatory list wyświetlania
GLint RECT_LIST;
GLint SPECTRUM_1_LIST, SPECTRUM_2_LIST, SPECTRUM_3_LIST;
// filtr pomniejszający
GLint min_filter = GL_NEAREST_MIPMAP_NEAREST;
// funkcja generująca scenę 3D
void DisplayScene()
{
	// kolor tła - zawartośæ bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// czyszczenie bufora koloru
	glClear(GL_COLOR_BUFFER_BIT);
	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);
	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();
	// przesunięcie układu współrzędnych obiektów do środka bryły odcinania
	glTranslatef(0, 0, -(near + far) / 2);
	// skalowanie obiektu - klawisze "+" i "-"
	glScalef(scale, 1.0, 1.0);
	// włączenie teksturowania jednowymiarowego
	glEnable(GL_TEXTURE_1D);
	// tryb upakowania bajtów danych tekstury
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// filtr powiększający
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// usunięcie błędów przy renderingu brzegu tekstury
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	// filtr pomniejszający
	glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, min_filter);
	// wyświetlenie tekstur
	glCallList(SPECTRUM_1_LIST);
	glCallList(SPECTRUM_2_LIST);
	glCallList(SPECTRUM_3_LIST);
	// skierowanie poleceñ do wykonania
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
		// wysokośæ okna większa od wysokości okna
		if (width < height && width > 0)
			glFrustum(left, right, bottom*height / width, top*height / width, near, far);
		else
			// szerokośæ okna większa lub równa wysokości okna
			if (width >= height && height > 0)
				glFrustum(left*width / height, right*width / height, bottom, top, near,
					far);
	}
	else
		glFrustum(left, right, bottom, top, near, far);
	// generowanie sceny 3D
	DisplayScene();
}
// obsługa klawiatury
void Keyboard(unsigned char key, int x, int y)
{
	// klawisz +
	if (key == '+')
		scale += 0.05;
	else
		// klawisz -
		if (key == '-' && scale > 0.05)
			scale -= 0.05;
	// narysowanie sceny
	DisplayScene();
}
// obsługa menu podręcznego
void Menu(int value)
{
	switch (value)
	{
		// filtr pomniejszający
	case GL_NEAREST_MIPMAP_NEAREST:
	case GL_NEAREST_MIPMAP_LINEAR:
	case GL_LINEAR_MIPMAP_NEAREST:
	case GL_LINEAR_MIPMAP_LINEAR:
		min_filter = value;
		DisplayScene();
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
		// wyjście
	case EXIT:
		exit(0);
	}
}
// utworzenie list wyświetlania
void GenerateDisplayLists()
{
	// generowanie identyfikatora listy wyświetlania
	RECT_LIST = glGenLists(1);
	// lista wyświetlania - prostokąt
	glNewList(RECT_LIST, GL_COMPILE);
	// nałżenie tekstury na prostokąt
	glBegin(GL_QUADS);
	glTexCoord1f(1.0);
	glVertex2f(1.5, 0.7);
	glTexCoord1f(0.0);
	glVertex2f(-1.5, 0.7);
	glTexCoord1f(0.0);
	glVertex2f(-1.5, -0.7);
	glTexCoord1f(1.0);
	glVertex2f(1.5, -0.7);
	glEnd();
	// koniec listy wyświetlania
	glEndList();
	// sprawdzenie czy implementacja biblioteki obsługuje tekstury o wymiarze 256
	GLint size;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &size);
	if (size < 512)
	{
		printf("Rozmiar tekstur mniejszy od 512");
		exit(0);
	}
	// generowanie identyfikatora listy wyświetlania
	SPECTRUM_1_LIST = glGenLists(1);
	// lista wyświetlania - pierwsza "tęcza"
	glNewList(SPECTRUM_1_LIST, GL_COMPILE);
	// definiowanie tekstury i mipmap
	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_512);
	glTexImage1D(GL_TEXTURE_1D, 1, GL_RGB, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_256);
	glTexImage1D(GL_TEXTURE_1D, 2, GL_RGB, 128, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_128);
	glTexImage1D(GL_TEXTURE_1D, 3, GL_RGB, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_64);
	glTexImage1D(GL_TEXTURE_1D, 4, GL_RGB, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_32);
	glTexImage1D(GL_TEXTURE_1D, 5, GL_RGB, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_16);
	glTexImage1D(GL_TEXTURE_1D, 6, GL_RGB, 8, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_8);
	glTexImage1D(GL_TEXTURE_1D, 7, GL_RGB, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_4);
	glTexImage1D(GL_TEXTURE_1D, 8, GL_RGB, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_2);
	glTexImage1D(GL_TEXTURE_1D, 9, GL_RGB, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_1);
	// odłżenie macierzy modelowania na stos
	glPushMatrix();
	// przesunięcie prostokąta do góry o dwie jednostki
	glTranslatef(0.0, 2.0, 0.0);
	// nałżenie tekstury na prostokąt
	glCallList(RECT_LIST);
	// zdjęcie macierzy modelowania ze stosu
	glPopMatrix();
	// koniec listy wyświetlania
	glEndList();
	// generowanie identyfikatora listy wyświetlania
	SPECTRUM_2_LIST = glGenLists(1);
	// lista wyświetlania - druga "tęcza"
	glNewList(SPECTRUM_2_LIST, GL_COMPILE);
	// definiowanie tekstury łącznie z mipmapami
	gluBuild1DMipmaps(GL_TEXTURE_1D, GL_RGB, 512, GL_RGB, GL_UNSIGNED_BYTE, spectrum_512);
	// nałżenie tekstury na prostokąt
	glCallList(RECT_LIST);
	// koniec listy wyświetlania
	glEndList();
	// generowanie identyfikatora listy wyświetlania
	SPECTRUM_3_LIST = glGenLists(1);
	// lista wyświetlania - trzecia "tęcza"
	glNewList(SPECTRUM_3_LIST, GL_COMPILE);
	// włączenie automatycznego generowania mipmap
	glTexParameteri(GL_TEXTURE_1D, GL_GENERATE_MIPMAP, GL_TRUE);
	// definiowanie tekstury
	glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, spectrum_512);
	// wyłączenie automatycznego generowania mipmap
	glTexParameteri(GL_TEXTURE_1D, GL_GENERATE_MIPMAP, GL_FALSE);
	// odłżenie macierzy modelowania na stos
	glPushMatrix();
	// przesunięcie prostokąta do dołu o dwie jednostki
	glTranslatef(0.0, -2.0, 0.0);
	// nałżenie tekstury na prostokąt
	glCallList(RECT_LIST);
	// zdjęcie macierzy modelowania ze stosu
	glPopMatrix();
	// koniec listy wyświetlania
	glEndList();
}
// sprawdzenie i przygotowanie obsługi wybranych rozszerzeñ
void ExtensionSetup()
{
	// pobranie numeru wersji biblioteki OpenGL
	const char *version = (char*)glGetString(GL_VERSION);
	// odczyt wersji OpenGL
	int major = 0, minor = 0;
	if (sscanf_s(version, "%d.%d", &major, &minor) != 2)
	{
#ifdef WIN32
		printf("Błędny format wersji OpenGL\n");
#else
		printf("Bledny format wersji OpenGL\n");
#endif
		exit(0);
	}
	// sprawdzenie czy jest co najmniej wersja 1.4 OpenGL lub
	// czy jest obsługiwane rozszerzenie GL_SGIS_generate_mipmap
	if (!(major > 1 || minor >= 4) &&
		!glutExtensionSupported("GL_SGIS_generate_mipmap"))
	{
		printf("Brak rozszerzenia GL_SGIS_generate_mipmap!\n");
		exit(0);
	}
	// sprawdzenie czy jest co najmniej wersja 1.2 OpenGL lub
	// czy jest obsługiwane rozszerzenie GL_SGIS_texture_edge_clamp
	if (!(major > 1 || minor >= 2) &&
		!glutExtensionSupported("GL_SGIS_texture_edge_clamp"))
	{
		printf("Brak rozszerzenia GL_SGIS_texture_edge_clamp!\n");
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
	glutInitWindowSize(500, 500);
	// utworzenie głównego okna programu
	glutCreateWindow("Mipmapy 1D");
	// dołączenie funkcji generującej scenę 3D
	glutDisplayFunc(DisplayScene);
	// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
	glutReshapeFunc(Reshape);
	// dołączenie funkcji obsługi klawiatury
	glutKeyboardFunc(Keyboard);
	// utworzenie podmenu - Filtr pomniejszający
	int MenuMinFilter = glutCreateMenu(Menu);
	glutAddMenuEntry("GL_NEAREST_MIPMAP_NEAREST", GL_NEAREST_MIPMAP_NEAREST);
	glutAddMenuEntry("GL_NEAREST_MIPMAP_LINEAR", GL_NEAREST_MIPMAP_LINEAR);
	glutAddMenuEntry("GL_LINEAR_MIPMAP_NEAREST", GL_LINEAR_MIPMAP_NEAREST);
	glutAddMenuEntry("GL_LINEAR_MIPMAP_LINEAR", GL_LINEAR_MIPMAP_LINEAR);
	// utworzenie podmenu - Aspekt obrazu
	int MenuAspect = glutCreateMenu(Menu);
#ifdef WIN32
	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
#else
	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif
	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);
	// menu główne
	glutCreateMenu(Menu);
#ifdef WIN32
	glutAddSubMenu("Filtr pomniejszający", MenuMinFilter);
	glutAddSubMenu("Aspekt obrazu", MenuAspect);
	glutAddMenuEntry("Wyjście", EXIT);
#else
	glutAddSubMenu("Filtr pomniejszajacy", MenuMinFilter);
	glutAddSubMenu("Aspekt obrazu", MenuAspect);
	glutAddMenuEntry("Wyjscie", EXIT);
#endif
	// określenie przycisku myszki obsługującego menu podręczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	// sprawdzenie i przygotowanie obsługi wybranych rozszerzeñ
	ExtensionSetup();
	// utworzenie list wyświetlania
	GenerateDisplayLists();
	// wprowadzenie programu do obsługi pętli komunikatów
	glutMainLoop();
	return 0;
}