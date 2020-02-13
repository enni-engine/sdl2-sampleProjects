#include <SDL.h>
#include <SDL_timer.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	SDL_Event event;
	SDL_Window *window;

	// retutns zero on success else non-zero 
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
		printf("error initializing SDL: %s\n", SDL_GetError()); 
	} 
	window = SDL_CreateWindow("SDL Examples", 
									SDL_WINDOWPOS_CENTERED, 
									SDL_WINDOWPOS_CENTERED, 
									640, 480, 0); 
	if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }


	while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0; 
} 
