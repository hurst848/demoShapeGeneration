#include <SDL.h>
#include <windows.h>
#include <iostream>


#include "ridgidShape.h"
#include "display.h"
#include "transformer.h"
#include "D:\CPP Projects\SDL2Project_GOOP\SDLutil.h"

circle makeCircle();
ridgidShape makeShape();
void loopTransformer(SDL_Renderer** renderer, transformer transform, ridgidShape *tester, SDL_Rect *background, SDL_Window* window, display* ptr);

int main(int argc, char* args[])
{
	

	display* ptr = nullptr;
	while (true)
	{
		ptr = new display();

		if (ptr != NULL)
		{
			std::cout << "Display Created Succsessfully ";
			Sleep(1000);
			std::cout << ". ";
			Sleep(1000);
			std::cout << ". ";
			Sleep(1000);
			std::cout << ". " << std::endl;
			break;
		}
		delete ptr;
		std::cout << "BADTOKEN" << std::endl;
	}
	SDL_Rect bckgrnd;
	bckgrnd.x = 0;
	bckgrnd.y = 0;
	bckgrnd.w = 2560;
	bckgrnd.h = 1440;
	transformer transform;
	

	circle crcl = makeCircle();
	//ridgidShape test = makeShape();

	//transform.sendToDisplay(test, ptr, false);
	transform.sendToDisplay(crcl,ptr);

	SDL_Window* window;
	SDL_Renderer* renderer;
	initAll(&window, &renderer, 2560, 1440);
	
	//loopTransformer(&renderer,transform,&test,&bckgrnd,window,ptr);

	//SDL_RenderClear(renderer);
	drawBackground(&renderer, &window, &bckgrnd);
	
	ptr->updateScreen(&renderer);
	SDL_RenderPresent(renderer);
	//SDL_RenderPresent(renderer);

	
	SDL_Delay(10000);
	
	
	//system("pause");
	



	return 0;
}


circle makeCircle()
{
	std::cout << "Please enter X Coord of Circle: " << std::endl;
	int _x = readInt();
	std::cout << "Please enter Y Coord of Circle: " << std::endl;
	int _y = readInt();
	std::cout << "Please enter Radius of Circle: " << std::endl;
	int _r = readInt();
	circle crcl(_x, _y, _r);
	return crcl;
}


ridgidShape makeShape()
{
	std::cout << "enter number of sides" << std::endl;
	int numsidesofshape = readInt();
	ridgidShape test(numsidesofshape);
	return test;

}

void loopTransformer(SDL_Renderer** renderer, transformer transform, ridgidShape *tester, SDL_Rect *background, SDL_Window *window, display *ptr)
{
	bool exit = false;
	while (!(exit))
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				exit = true;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_w)
				{
					transform.translate(tester, 0, -10);
					
				}
				else if (event.key.keysym.sym == SDLK_s)
				{
					transform.translate(tester, 0, 10);
				}
				else if (event.key.keysym.sym == SDLK_a)
				{
					transform.translate(tester, -10, 0);
				}
				else if (event.key.keysym.sym == SDLK_d)
				{
					transform.translate(tester, 10, 0);
				}
				else if (event.key.keysym.sym == SDLK_e)
				{
					transform.rotate(tester, 10);
				}
				else if (event.key.keysym.sym == SDLK_q)
				{
					transform.rotate(tester, -10);
				}
				else if (event.key.keysym.sym == SDLK_UP)
				{
					transform.scale(tester,0,2);
				}
				else if (event.key.keysym.sym == SDLK_DOWN)
				{
					transform.scale(tester, 0, 0.5);
				}
				else if (event.key.keysym.sym == SDLK_LEFT)
				{
					transform.scale(tester, 0.5, 0);
				}
				else if (event.key.keysym.sym == SDLK_RIGHT)
				{
					transform.scale(tester, 2, 0);
				}
			}
		}
		
		transform.sendToDisplay(*tester,ptr,false);
		drawBackground(renderer, &window, background);
		ptr->updateScreen(renderer);
		SDL_RenderPresent(*renderer);
		SDL_RenderClear(*renderer);
	}
}