#ifndef MAP_H

#include <vector>
#include "tile.h"

using std::vector;

class Graphics;
class Sprite;
struct SDL_Rect;


class Map
{
public:
	static Map* createTestMap(Graphics& graphics);

	void update(int elapsedTime);
	void draw(Graphics& graphics, SDL_Rect& camera) const;

	vector<vector<Sprite*>> getMapTiles;
	
	static void createPokeCenter(Map* map, Tile pokeCenter, int rowCoord, int colCoord);
	static void createPokeMart(Map* map, Tile pokeMart, int rowCoord, int colCoord);
	static void createSmallTrees(Map* map, Tile tree, int rowCoord, int colCoord);
	static void createPath(Map* map, Tile leftTile, Tile middleTile, Tile rightTile, int rowCoord, int numCols);
	static void createRegularGrass(Map* map, Tile regularGrass, int row, int col, int numRows, int numCols);
private:

	vector<vector<Tile>> mapTiles;
};

#endif // !MAP_H

