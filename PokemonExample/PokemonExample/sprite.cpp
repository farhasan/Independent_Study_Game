#include "graphics.h"
#include "sprite.h"
#include "globals.h"

using std::string;

Sprite::Sprite() {}

Sprite::Sprite(Graphics& graphics, const string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	_x(posX), _y(posY)
{
	_sourceRect.x = sourceX;
	_sourceRect.y = sourceY;
	_sourceRect.w = width;
	_sourceRect.h = height;

	_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

	if (_spriteSheet == nullptr) { printf("\nUnable to load image\n"); }
}

Sprite::~Sprite()
{

}

void Sprite::draw(Graphics& graphics, int x, int y, SDL_Rect& camera)
{
	SDL_Rect destinationRectangle = { x-(camera.x/1.5), y-(camera.y/1.5), _sourceRect.w * globals::SPRITE_SCALE, _sourceRect.h * globals::SPRITE_SCALE };
	graphics.blitSurface(_spriteSheet, &_sourceRect, &destinationRectangle);
}

void Sprite::update(int elapsedTime)
{

}