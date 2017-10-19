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
private:
	vector<vector<Sprite*>> mapTiles;
};

#endif // !MAP_H

