#pragma once
#include "pixel.h"
#include <SDL.h>

class display
{
public:
	pixel screen[2560][1440];
	int resX = 2560;
	int resY = 1440;

	void updateScreen(SDL_Renderer **renderer);
	void updatePixel(int x, int y, int _r, int _g, int _b, int _w);
	display();
};

