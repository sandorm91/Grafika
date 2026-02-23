#include "line.h"
#include "point.h"
#include "color.h"

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	/*SDL*/
	int error_code;
	SDL_Window* window;
	bool need_run;
	SDL_Event event;
	SDL_Renderer* renderer;
	int i;
	/*SDL*/
	int red;
	int green;
	int blue;
	Color color;
	Point start;
	bool startset;
	Point end;
	bool endset;
	Line line;
	if( argc==4)
	{
		sscanf(argv[1],"%d", &red);
		sscanf(argv[2],"%d", &green);
		sscanf(argv[3],"%d", &blue);
	}
	else{
		red=255;
		green=255;
		blue=255;
	}
	set_color_data(&color,red,green,blue);


	error_code = SDL_Init(SDL_INIT_EVERYTHING);
	if (error_code != 0) {
		printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
		return error_code;
	}

	window = SDL_CreateWindow(
    "Vonal(a)zó",
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    1000, 1000, 0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, SDL_ALPHA_OPAQUE);
		
	need_run = true;
	startset = false;
	endset = false;
	while (need_run) {
		while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_MOUSEBUTTONDOWN:
				if(startset && !endset)
				{
					endset=true;
					SDL_GetMouseState(&end.x,&end.y);
					set_line_data(&line, start.x, start.y, end.x, end.y,color);
					SDL_RenderDrawLine(renderer, line.st_x, line.st_y, line.end_x, line.end_y);
					SDL_RenderPresent(renderer);
				}
				else
				{
					if(startset && endset)
					{
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
						SDL_RenderClear(renderer);
						SDL_RenderPresent(renderer);
						SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, SDL_ALPHA_OPAQUE);
						endset=false;
					}
					startset = true;
					SDL_GetMouseState(&start.x,&start.y);
				}
				break;
				case SDL_KEYDOWN:
				case SDL_SCANCODE_Q:
					need_run = false;
					break;
				case SDL_QUIT:
					need_run = false;
					break;
			}
		}
		
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	



	return 0;
}
