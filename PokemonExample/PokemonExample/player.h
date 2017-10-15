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

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	void runUp();
	void runDown();
	void runLeft();
	void runRight();

	void stopMoving();

	virtual void animationDone(string currentAnimation);
	virtual void setupAnimations();
private:
	float _dx, _dy;

	Direction facing = DOWN;
};

#endif // !PLAYER_H
