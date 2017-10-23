#ifndef MAP_H

#include <vector>

using std::vector;

class Graphics;
class Sprite;


class Map
{
public:
	static Map* createTestMap(Graphics& graphics);

	void update(int elapsedTime);
	void draw(Graphics& graphics) const;
	
	static void createPokeCenter(Map* map, Sprite* pokeCenter, int rowCoord, int colCoord);
	static void createPokeMart(Map* map, Sprite* pokeMart, int rowCoord, int colCoord);
	static void createSmallTrees(Map* map, Sprite* tree, int rowCoord, int colCoord);
	static void createPath(Map* map, Sprite* leftTile, Sprite* middleTile, Sprite* rightTile, int rowCoord, int numCols);
	static void createRegularGrass(Map* map, Sprite* regularGrass, int row, int col, int numRows, int numCols);
private:
	vector<vector<Sprite*>> mapTiles;
};

#endif // !MAP_H

