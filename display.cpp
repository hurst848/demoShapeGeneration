#include "display.h"
#include <iostream>


void display::updateScreen(SDL_Renderer **renderer)
{
	int pixlelsDone = 0;
	for (int i = 0; i < resX; i++)
	{
		
		for (int j = 0; j < resY; j++)
		{

			if (!(screen[i][j].r == 0 && screen[i][j].g == 0 && screen[i][j].b == 0))
			{
				SDL_Rect tmp;
				tmp.w = 1;
				tmp.h = 1;
				tmp.x = i;
				tmp.y = j;
				SDL_SetRenderDrawColor(*renderer, screen[i][j].r, screen[i][j].g, screen[i][j].b, screen[i][j].w);
				SDL_RenderFillRect(*renderer, &tmp);
				//SDL_RenderPresent(*renderer);
				pixlelsDone++;
				//printf("%d", pixlelsDone);
				//printf(" pixels complete \n");
				//printf("%d", j);
				//printf(" y complete \n");

			}
		}
		
		//printf("%d", i);
		//printf(" x complete \r");
		
	}
	
}

void display::updatePixel(int x, int y, int _r, int _g, int _b, int _w)
{
	
	screen[x][y].r = _r;
	screen[x][y].g = _g;
	screen[x][y].b = _b;
	screen[x][y].w = _w;
}

display::display()
{
	for (int i = 0; i < 2560; i++)
	{
		for (int j = 0; j < 1440; j++)
		{
			screen[i][j].r = 0;
			screen[i][j].g = 0;
			screen[i][j].b = 0;
			screen[i][j].w = 255;
		}
	}
	resX = 2560;
	resY = 1440;
}