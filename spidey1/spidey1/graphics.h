#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

using std::string;
using std::map;

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics {
public:
	Graphics();
	~Graphics();

	SDL_Surface* loadImage(const string& filePath);
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	void flip();
	void clear();
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	map<string, SDL_Surface*> _spriteSheets;
};

#endif