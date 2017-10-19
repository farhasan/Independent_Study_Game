#include "map.h"
#include "sprite.h"

#include <SDL.h>
#include <vector>


using std::vector;

Map* Map::createTestMap(Graphics& graphics) {
	Map* map = new Map();

	const int numRows = 45;
	const int numCols = 80;

	Sprite* sprite(new Sprite(graphics, "sprites/tileset.png", 16, 0, 16, 16, 0, 0));

	map->mapTiles = vector<vector<Sprite*>>(numRows, vector<Sprite*>(numCols));

	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			map->mapTiles[row][col] = sprite;
		}
	}

	return map;
}

void Map::update(int elapsedTime)
{
	for (size_t row = 0; row < mapTiles.size(); row++)
	{
		for (size_t col = 0; col < mapTiles[row].size(); col++)
		{
			if (mapTiles[row][col]) { mapTiles[row][col]->update(elapsedTime); }
		}
	}
}

void Map::draw(Graphics& graphics) const
{
	for (size_t row = 0; row < mapTiles.size(); row++)
	{
		for (size_t col = 0; col < mapTiles[row].size(); col++)
		{
			if (mapTiles[row][col]) { mapTiles[row][col]->draw(graphics, col*32, row*32); }
		}
	}
}
