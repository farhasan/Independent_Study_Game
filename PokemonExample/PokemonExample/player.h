#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"

using std::string;

class Graphics;

class Player : public AnimatedSprite
{
public:
	Player();
	Player(Graphics& graphics, float x, float y);
	void draw(Graphics& graphics);
	void update(float elapsedTime);

	float getX();
	float getY();

	void moveUp();
	void moveDown();
	void moveRight(int levelWidth);
	void moveLeft(int levelWidth);

	void runUp();
	void runDown();
	void runLeft(int levelWidth);
	void runRight(int levelWidth);

	void stopMoving();

	virtual void animationDone(string currentAnimation);
	virtual void setupAnimations();
private:
	float _dx, _dy;

	Direction facing = DOWN;
};

#endif // !PLAYER_H
