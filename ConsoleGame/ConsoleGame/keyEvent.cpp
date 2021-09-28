#include "game.h"

void processNormalKey(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		atexit(KillFont);
		exit(0);
	}
}