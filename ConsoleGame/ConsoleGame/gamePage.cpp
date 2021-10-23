#include "game.h"

GLvoid gamePage()
{
	glColor4f(232.0f / 255.0f, 232.0f / 255.0f, 232.0f / 255.0f, 1.0f);
	drawRect({ -1.6f, -1.0f }, { 1.6f, 1.0f });

	glColor4f((GLfloat)(7.0 / 255.0), (GLfloat)(44.0 / 255.0), (GLfloat)(105.0 / 255.0), (GLfloat)1.0);
	drawRect({ -1.6f, -1.0f }, { -1.0f, 1.0f });

	glColor4f((GLfloat)(255.0 / 255.0), (GLfloat)(125.0 / 255.0), (GLfloat)(125.0 / 255.0), (GLfloat)1.0);
	drawRect({ 1.0f, -1.0f }, { 1.6f, 1.0f });
}