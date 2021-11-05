#include "game.h"

bool keyPress[4] = { false,};

static GLvoid paint_button()
{
	if (keyPress[0]) //left
	{
		glColor4f(58.0f / 255.0f, 58.0f / 255.0f, 58.0f / 255.0f, 1.0f);
		drawRect({ 1.1f, -0.07f }, { 1.23f, 0.07f });
	}
	if (keyPress[1]) //right
	{
		glColor4f(58.0f / 255.0f, 58.0f / 255.0f, 58.0f / 255.0f, 1.0f);
		drawRect({ 1.37f, -0.07f }, { 1.5f, 0.07f });
	}
	if (keyPress[2]) //up
	{
		glColor4f(58.0f / 255.0f, 58.0f / 255.0f, 58.0f / 255.0f, 1.0f);
		drawRect({ 1.23f, 0.07f }, { 1.37f, 0.2f });
	}
	if (keyPress[3]) //down
	{
		glColor4f(58.0f / 255.0f, 58.0f / 255.0f, 58.0f / 255.0f, 1.0f);
		drawRect({ 1.23f, -0.2f }, { 1.37f, -0.07f });
	}
}


GLvoid gamePage()
{
	glColor4f(232.0f / 255.0f, 232.0f / 255.0f, 232.0f / 255.0f, 1.0f);
	drawRect({ -1.6f, -1.0f }, { 1.6f, 1.0f });

	glColor4f((GLfloat)(54.0 / 255.0), (GLfloat)(59.0 / 255.0), (GLfloat)(108.0 / 255.0), (GLfloat)1.0);
	drawRect({ -1.6f, -1.0f }, { -1.0f, 1.0f });

	glColor4f((GLfloat)(122.0 / 255.0), (GLfloat)(8.0 / 255.0), (GLfloat)(8.0 / 255.0), (GLfloat)1.0);
	drawRect({ 1.0f, -1.0f }, { 1.6f, 1.0f });

	glColor4f(92.0f / 255.0f, 92.0f / 255.0f, 92.0f / 255.0f, 1.0f);
	drawRect({ 1.1f, -0.07f }, { 1.5f, 0.07f });
	drawRect({ 1.23f, -0.2f }, { 1.37f, 0.2f });

	//draw_img(0, { -1.0f, -1.0f }, { -0.9f,-0.9f });
	draw_map();

	paint_button();
	
	Font info{ -1.55f, -0.95f, 0.0f, 1000.0f, 3.0f };
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glPrint("JoSuhee", info);
}