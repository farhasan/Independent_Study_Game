#include <algorithm>

#include <SDL.h>

#include "game.h"
#include "globals.h"
#include "graphics.h"
#include "input.h"

using std::min;
using std::pair;

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
	
	_player = Player(graphics, 80, 200);
	maps.push_back(Map::createTestMap(graphics));

	//SDL_Rect camera = { 0, 0, globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT };

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0) { input.keyDownEvent(event); }
			}
			else if (event.type == SDL_KEYUP) { input.keyUpEvent(event); }
			else if (event.type == SDL_QUIT) { return; }
			if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) { return; }

			if
				(
					!input.isKeyHeld(SDL_SCANCODE_UP) &&
					!input.isKeyHeld(SDL_SCANCODE_DOWN) &&
					!input.isKeyHeld(SDL_SCANCODE_LEFT) &&
					!input.isKeyHeld(SDL_SCANCODE_RIGHT)
				)
			{
				_player.stopMoving();
			}

			else if (input.isKeyHeld(SDL_SCANCODE_UP))
			{
				if(!input.isKeyHeld(SDL_SCANCODE_X)) { _player.moveUp(); }
				else { _player.runUp(); }
			} 
			else if (input.isKeyHeld(SDL_SCANCODE_DOWN))
			{
				if (!input.isKeyHeld(SDL_SCANCODE_X)) { _player.moveDown(); }
				else { _player.runDown(); }
			}
			else if (input.isKeyHeld(SDL_SCANCODE_LEFT))
			{
				if (!input.isKeyHeld(SDL_SCANCODE_X)) { _player.moveLeft(1280); }
				else { _player.runLeft(1280); }
			}
			else if (input.isKeyHeld(SDL_SCANCODE_RIGHT))
			{
				if (!input.isKeyHeld(SDL_SCANCODE_X)) { _player.moveRight(1280); }
				else { _player.runRight(1280); }
			}
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

		update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME), 0);
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		draw(graphics, 0);
	}
}

void Game::draw(Graphics &graphics, int mapNum)
{
	graphics.clear();
	maps[mapNum]->draw(graphics);
	_player.draw(graphics);
	graphics.flip();
}

void Game::update(float elapsedTime, int mapNum)
{
	_player.update(elapsedTime);
	maps[mapNum]->update(elapsedTime);
}