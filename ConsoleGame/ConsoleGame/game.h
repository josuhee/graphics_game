#pragma once
#ifndef GAME_H
# define GAME_H

# include <Windows.h>
# include <stdarg.h>

# include <GL/glut.h>
# include <GL/GL.h>
# include <GL/GLU.h>

# include <cstdlib>
# include <cmath>
# include <stdio.h>
# include <vector>
# include "font.h"
using namespace std;

typedef struct s_point_f {
	float x;
	float y;
}t_point_f;

/*==========page===========*/
GLvoid		startPage();
GLvoid		gamePage();

/*==========monuse event=====*/
void			mouse(int button, int state, int x, int y);
void			hover_mouse(int x, int y);

/*==========key event========*/
void			processNormalKey(unsigned char key, int x, int y);
void			processSpcialKey(int key, int x, int y);

/*==========draw utils========*/
GLvoid		glPrint(const char* text, Font info);
void			drawCude(float x, float y, bool flag, float degree);
void			drawRect(t_point_f p1, t_point_f p2);
void			init_image(void);
void			draw_img(int n, t_point_f p1, t_point_f p2);

/*==========timer===========*/
void			cubeTimer(int v);


#endif