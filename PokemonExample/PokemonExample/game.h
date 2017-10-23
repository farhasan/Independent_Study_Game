#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "map.h"

class Graphics;

class Game
{
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics, int mapNum);
	void update(float elapsedTime, int mapNum);

	Player _player;
	vector<Map*> maps;
};

#endif // !GAME_H
