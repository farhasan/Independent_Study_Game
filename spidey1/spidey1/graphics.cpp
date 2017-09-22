#include <SDL.h>
#include "graphics.h"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(1280, 720, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Spidey Example");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(_window);
}
