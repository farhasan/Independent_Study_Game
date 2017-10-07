#include "player.h"
#include "graphics.h"

namespace player_constants
{
	const float RUN_SPEED = 0.2f;
}

Player::Player()
{

}

Player::Player(Graphics& graphics, float x, float y) :
	AnimatedSprite(graphics, "sprites/dannyphantom.png", 78, 438, 59, 46, x, y, 145)
{
	graphics.loadImage("sprites/dannyphantom.png");
	setupAnimations();
	playAnimation("Run");
}

void Player::setupAnimations()
{
	addRightAnimation(3, 78, 438, "IdleRight", 59, 46, Vector2(0, 0));
	addLeftAnimation(3, 726, 438, "IdleLeft", 59, 46, Vector2(0,0));

	addRightAnimation(3, 261, 438, "RunRight", 54, 46, Vector2(0, 0));
	addFrameToAnimation(getAnimations(), "RunRight", 15, 499, 54, 46);
	addLeftAnimation(3, 597, 438, "RunLeft", 54, 46, Vector2(0, 0));
	addFrameToAnimation(getAnimations(), "RunLeft", 852, 499, 54, 46);


	addRightAnimation(2, 69, 556, "Punch1", 60, 48, Vector2(0, 0));
	addRightAnimation(2, 192, 556, "Punch2", 60, 48, Vector2(0, 0));
	addRightAnimation(2, 252, 556, "Punch3", 60, 48, Vector2(0, 0));
}

void Player::moveRight()
{
	_dx = player_constants::RUN_SPEED;
	playAnimation("RunRight");
	facing = RIGHT;
}

void Player::moveLeft()
{
	_dx = -player_constants::RUN_SPEED;
	playAnimation("RunLeft");
	facing = LEFT;
}

void Player::stopMoving()
{
	_dx = 0.0f;
	playAnimation(facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::animationDone(string currentAnimation)
{

}

void Player::update(float elapsedTime)
{
	_x += _dx * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics)
{
	AnimatedSprite::draw(graphics, _x, _y);
}


