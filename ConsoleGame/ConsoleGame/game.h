#pragma once
#ifndef GAME_H
# define GAME_H

#include <Windows.h>
#include <stdarg.h>

# include <GL/glut.h>
# include <GL/GL.h>
# include <GL/GLU.h>
# include <cstdlib>
# include <cmath>
# include <stdio.h>
# include <vector>
# include "font.h"
using namespace std;

/*==========page===========*/
GLvoid		startPage();

/*==========monuse event=====*/
void			mouse(int button, int state, int x, int y);
void			hover_mouse(int x, int y);

/*==========key event========*/
void			processNormalKey(unsigned char key, int x, int y);
void			processSpcialKey(int key, int x, int y);

/*==========print text========*/
GLvoid		glPrint(const char* text, Font info);

/*==========timer===========*/
void			cubeTimer(int v);


#endif