#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

using std::string;

class Graphics;

class Sprite
{
public:
	Sprite();
	Sprite(Graphics& graphics, const string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update(int elapsedTime);
	void draw(Graphics& graphics, int x, int y, SDL_Rect& camera);

protected:
	float _x, _y;

	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

private:

};

#endif