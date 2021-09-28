#pragma once
#ifndef GAME_H
# define GAME_H

#include <Windows.h>
#include <stdarg.h>

# include <GL/glut.h>
# include <GL/GL.h>
# include <GL/GLU.h>
# include <cstdlib>

/*==========key event========*/
void processNormalKey(unsigned char key, int x, int y);

/*==========print textt========*/
GLvoid	glPrint(const char* text);
GLvoid	KillFont(GLvoid);
int			InitFont(GLvoid);

#endif