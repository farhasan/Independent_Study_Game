#ifndef TILE_H

#include "sprite.h"

enum TileType
{
	POKECENTER_TILE,
	POKEMART_TILE,
	SMALL_TREE_TILE,
	LEFT_TILE,
	MIDDLE_TILE,
	RIGHT_TILE,
	REG_GRASS_TILE
};

struct Tile
{
	//Tile(TileType tt = REG_GRASS_TILE, Sprite* s = nullptr) : tile_type(tt), tile_sprite(s) {}
	//Tile(){}
	TileType tile_type;
	Sprite* tile_sprite;
};

#endif // !TILE_H
