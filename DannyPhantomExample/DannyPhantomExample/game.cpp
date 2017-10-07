#include <algorithm>

#include <SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

using std::min;

namespace
{
	const int FPS = 60;
	const int MAX_FRAME_TIME = 6 * 1000 / FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;
	_player = Player(graphics, 100, 100);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true)
	{
		input.beginNewFrame();

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0) { input.keyDownEvent(event); }
			}
			else if (event.type == SDL_KEYUP) { input.keyUpEvent(event); }
			else if (event.type == SDL_QUIT) { return; }
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) { return; }

		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true) { _player.moveRight(); }
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true) { _player.moveLeft(); }

		if (!input.isKeyHeld(SDL_SCANCODE_RIGHT) && !input.isKeyHeld(SDL_SCANCODE_LEFT)) { _player.stopMoving(); }

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		
		update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		draw(graphics);
	}
}

void Game::draw(Graphics &graphics)
{
	graphics.clear();
	_player.draw(graphics);
	graphics.flip();
}

void Game::update(float elapsedTime)
{
	_player.update(elapsedTime);
}