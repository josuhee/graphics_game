#pragma once
#ifndef GAME_H
# define GAME_H

# include <Windows.h>
# include <stdarg.h>

# include <GL/glut.h>
# include <GL/GL.h>
# include <GL/GLU.h>

# include <cstdlib>
# include <cstring>
# include <cmath>
# include <stdio.h>
# include <vector>
# include "font.h"
using namespace std;

typedef struct s_point_f {
	float x;
	float y;
}t_point_f;

typedef struct s_map
{
	char map[10][11];
	int player_x;
	int player_y;
	int item_cnt;
	int enemy_x;
	int enemy_y;
	bool clear;
}t_map;

/*==========page===========*/
GLvoid		startPage();
GLvoid		gamePage();
GLvoid		endPage();

/*========serach player========*/
pair<int,int> search_player();

/*==========monuse event=====*/
void			mouse(int button, int state, int x, int y);
void			hover_mouse(int x, int y);

/*==========key event========*/
void			processNormalKey(unsigned char key, int x, int y);
void			processSpcialKey(int key, int x, int y);
void			processSpecialKeyUp(int key, int x, int y);

/*==========draw utils========*/
GLvoid		glPrint(const char* text, Font info);
void			drawCude(float x, float y, bool flag, float degree);
void			drawRect(t_point_f p1, t_point_f p2);
void			init_image(void);
void			draw_img(int n, t_point_f p1, t_point_f p2);
void			draw_img_player(int n, t_point_f p1, t_point_f p2);
void			draw_img_item(int n, t_point_f p1, t_point_f p2);
void			draw_img_enemy(int n, t_point_f p1, t_point_f p2);

/*==========timer===========*/
void			cubeTimer(int v);

/*==========map============*/
t_map*		get_map_info();
void			create_map();
void			draw_map();

#endif