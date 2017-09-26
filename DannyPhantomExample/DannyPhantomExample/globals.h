#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals
{
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;

	const float SPRITE_SCALE = 2.0f;
}

struct Vector2
{
	int x, y;
	Vector2(): x(0), y(0) {}
	Vector2(int x1, int y1): x(x1), y(y1) {}
	Vector2 zero() { return Vector2(0, 0); }
};

#endif // !GLOBALS_H
