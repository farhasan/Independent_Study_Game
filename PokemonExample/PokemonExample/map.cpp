#include "map.h"
#include "sprite.h"

#include <SDL.h>
#include <vector>


using std::vector;

void Map::createPokeCenter(Map* map, Sprite* pokeCenter, int rowCoord, int colCoord)
{
	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = colCoord; col < colCoord + 4; col += 4)
		{
			map->mapTiles[row][col] = pokeCenter;
		}
	}
}

void Map::createPokeMart(Map* map, Sprite* pokeMart, int rowCoord, int colCoord)
{
	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = colCoord; col < colCoord + 4; col += 4)
		{
			map->mapTiles[row][col] = pokeMart;
		}
	}
}

void Map::createSmallTrees(Map* map, Sprite* smallTrees, int rowCoord, int numCols)
{
	for (int row = rowCoord; row < rowCoord + 4; row += 2)
	{
		for (int col = 0; col < numCols; col += 2)
		{
			map->mapTiles[row][col] = smallTrees;
		}
	}
}

void Map::createPath(Map* map, Sprite* leftTile, Sprite* middleTile, Sprite* rightTile, int rowCoord, int numCols)
{
	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = 0; col < 2; col += 2)
		{
			map->mapTiles[row][col] = leftTile;
		}
	}

	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = 2; col < numCols - 2; col++)
		{
			map->mapTiles[row][col] = middleTile;
		}
	}

	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = numCols - 2; col < numCols; col += 2)
		{
			map->mapTiles[row][col] = rightTile;
		}
	}
}

void Map::createRegularGrass(Map* map, Sprite* regularGrass, int row, int col, int numRows, int numCols)
{
	for (int _row = row; _row < numRows; _row++)
	{
		for (int _col = col; _col < numCols; _col++)
		{
			map->mapTiles[_row][_col] = regularGrass;
		}
	}
}

Map* Map::createTestMap(Graphics& graphics) {
	Map* map = new Map();

	const int numRows = 45;
	const int numCols = 40;

	Sprite* regularGrass(new Sprite(graphics, "sprites/tileset.png", 16, 0, 16, 16, 0, 0));
	Sprite* smallTrees(new Sprite(graphics, "sprites/tileset.png", 96, 16, 32, 32, 0, 0));
	Sprite* pokeCenter(new Sprite(graphics, "sprites/tileset.png", 0, 144, 64, 64, 0, 0));
	Sprite* pokeMart(new Sprite(graphics, "sprites/tileset.png", 0, 80, 64, 64, 0, 0));
	Sprite* leftEndPathTile(new Sprite(graphics, "sprites/tileset.png", 0, 560, 32, 48, 0, 0));
	Sprite* middlePathTile(new Sprite(graphics, "sprites/tileset.png", 16, 560, 16, 48, 0, 0));
	Sprite* rightEndPathTile(new Sprite(graphics, "sprites/tileset.png", 16, 560, 32, 48, 0, 0));

	map->mapTiles = vector<vector<Sprite*>>(numRows, vector<Sprite*>(numCols));
	
	createSmallTrees(map, smallTrees, 0, numCols);
	createPokeCenter(map, pokeCenter, 4, 4);
	
	createRegularGrass(map, regularGrass, 4, 0, 10, 4);
	createRegularGrass(map, regularGrass, 8, 4, 10, 8);
	createRegularGrass(map, regularGrass, 4, 8, 10, numCols);

	createPath(map, leftEndPathTile, middlePathTile, rightEndPathTile, 10, numCols);
	createPokeMart(map, pokeMart, 14, 28);
	
	createRegularGrass(map, regularGrass, 13, 0, 19, 28);
	createRegularGrass(map, regularGrass, 13, 32, 19, numCols);
	createRegularGrass(map, regularGrass, 13, 28, 14, 32);
	createRegularGrass(map, regularGrass, 18, 28, 19, 32);
	
	createSmallTrees(map, smallTrees, 19, numCols);

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

void Map::draw(Graphics& graphics, SDL_Rect& camera) const
{
	for (size_t row = 0; row < mapTiles.size(); row++)
	{
		for (size_t col = 0; col < mapTiles[row].size(); col++)
		{
			if (mapTiles[row][col]) 
			{ 
				mapTiles[row][col]->draw(graphics, col*32, row*32, camera);
			}
		}
	}
}

