#include "game.h"

GLvoid gamePage()
{
	glColor4f(232.0f / 255.0f, 232.0f / 255.0f, 232.0f / 255.0f, 1.0f);
	drawRect({ -1.6f, -1.0f }, { 1.6f, 1.0f });

	glColor4f((GLfloat)(125.0 / 255.0), (GLfloat)(125.0 / 255.0), (GLfloat)(255.0 / 255.0), (GLfloat)1.0);
	drawRect({ -1.6f, -1.0f }, { -1.0f, 1.0f });

	glColor4f((GLfloat)(255.0 / 255.0), (GLfloat)(125.0 / 255.0), (GLfloat)(125.0 / 255.0), (GLfloat)1.0);
	drawRect({ 1.0f, -1.0f }, { 1.6f, 1.0f });

	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	drawRect({ 1.1f, -0.07f }, { 1.5f, 0.07f });

	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	drawRect({ 1.23f, -0.2f }, { 1.37f, 0.2f });

	Font info{ -1.55f, -0.95f, 0.0f, 1000.0f, 10.0f };
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glPrint("JoSuhee", info);
}