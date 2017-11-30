#include "map.h"
#include "sprite.h"

#include <SDL.h>
#include <vector>


using std::vector;

void Map::createPokeCenter(Map* map, Tile pokeCenter, int rowCoord, int colCoord)
{
	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = colCoord; col < colCoord + 4; col += 4)
		{
			map->mapTiles[row][col].tile_sprite = pokeCenter.tile_sprite;
		}
	}
}

void Map::createPokeMart(Map* map, Tile pokeMart, int rowCoord, int colCoord)
{
	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = colCoord; col < colCoord + 4; col += 4)
		{
			map->mapTiles[row][col].tile_sprite = pokeMart.tile_sprite;
		}
	}
}

void Map::createSmallTrees(Map* map, Tile smallTrees, int rowCoord, int numCols)
{
	for (int row = rowCoord; row < rowCoord + 4; row += 2)
	{
		for (int col = 0; col < numCols; col += 2)
		{
			map->mapTiles[row][col].tile_sprite = smallTrees.tile_sprite;
		}
	}
}

void Map::createPath(Map* map, Tile leftTile, Tile middleTile, Tile rightTile, int rowCoord, int numCols)
{
	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = 0; col < 2; col += 2)
		{
			map->mapTiles[row][col].tile_sprite = leftTile.tile_sprite;
		}
	}

	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = 2; col < numCols - 2; col++)
		{
			map->mapTiles[row][col].tile_sprite = middleTile.tile_sprite;
		}
	}

	for (int row = rowCoord; row < rowCoord + 4; row += 4)
	{
		for (int col = numCols - 2; col < numCols; col += 2)
		{
			map->mapTiles[row][col].tile_sprite = rightTile.tile_sprite;
		}
	}
}

void Map::createRegularGrass(Map* map, Tile regularGrass, int row, int col, int numRows, int numCols)
{
	for (int _row = row; _row < numRows; _row++)
	{
		for (int _col = col; _col < numCols; _col++)
		{
			map->mapTiles[_row][_col].tile_sprite = regularGrass.tile_sprite;
		}
	}
}

Map* Map::createTestMap(Graphics& graphics) {
	Map* map = new Map();

	const int numRows = 45;
	const int numCols = 40;

	Sprite* s_regularGrass(new Sprite(graphics, "sprites/tileset.png", 16, 0, 16, 16, 0, 0));
	Sprite* s_smallTrees(new Sprite(graphics, "sprites/tileset.png", 96, 16, 32, 32, 0, 0));
	Sprite* s_pokeCenter(new Sprite(graphics, "sprites/tileset.png", 0, 144, 64, 64, 0, 0));
	Sprite* s_pokeMart(new Sprite(graphics, "sprites/tileset.png", 0, 80, 64, 64, 0, 0));
	Sprite* s_leftEndPathTile(new Sprite(graphics, "sprites/tileset.png", 0, 560, 32, 48, 0, 0));
	Sprite* s_middlePathTile(new Sprite(graphics, "sprites/tileset.png", 16, 560, 16, 48, 0, 0));
	Sprite* s_rightEndPathTile(new Sprite(graphics, "sprites/tileset.png", 16, 560, 32, 48, 0, 0));

	Tile regularGrass;
	Tile smallTrees;
	Tile pokeCenter;
	Tile pokeMart;
	Tile leftEndPathTile;
	Tile middlePathTile;
	Tile rightEndPathTile;

	//need to fix constructors so for now have to manually set the sprites and types

	regularGrass.tile_type = REG_GRASS_TILE;
	regularGrass.tile_sprite = s_regularGrass;

	smallTrees.tile_type = SMALL_TREE_TILE;
	smallTrees.tile_sprite = s_smallTrees;

	pokeCenter.tile_type = POKECENTER_TILE;
	pokeCenter.tile_sprite = s_pokeCenter;

	pokeMart.tile_type = POKEMART_TILE;
	pokeMart.tile_sprite = s_pokeMart;

	leftEndPathTile.tile_type = LEFT_TILE;
	leftEndPathTile.tile_sprite = s_leftEndPathTile;

	middlePathTile.tile_type = MIDDLE_TILE;
	middlePathTile.tile_sprite = s_middlePathTile;

	rightEndPathTile.tile_type = RIGHT_TILE;
	rightEndPathTile.tile_sprite = s_rightEndPathTile;

	map->mapTiles = vector<vector<Tile>>(numRows, vector<Tile>(numCols));
	
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
			if (mapTiles[row][col].tile_sprite) { mapTiles[row][col].tile_sprite->update(elapsedTime); }
		}
	}
}

void Map::draw(Graphics& graphics, SDL_Rect& camera) const
{
	for (size_t row = 0; row < mapTiles.size(); row++)
	{
		for (size_t col = 0; col < mapTiles[row].size(); col++)
		{
			if (mapTiles[row][col].tile_sprite) 
			{ 
				mapTiles[row][col].tile_sprite->draw(graphics, col*32, row*32, camera);
			}
		}
	}
}

