#include "player.h"
#include "graphics.h"

namespace player_constants
{
	const float WALK_SPEED = 0.13f;
	const float RUN_SPEED = 0.23f;
}

Player::Player()
{

}

Player::Player(Graphics& graphics, float x, float y) :
	AnimatedSprite(graphics, "sprites/brandon.png", 64, 32, 25, 21, x, y, 145)
{
	graphics.loadImage("sprites/brandon.png");
	setupAnimations();
}

float Player::getX()
{
	return _x;
}

float Player::getY()
{
	return _y;
}

void Player::setupAnimations()
{
	addAnimation(1, 271, 32, "IdleUp", 23, 21, Vector2(0, 0));
	addAnimation(1, 64, 32, "IdleDown", 23, 21, Vector2(0, 0));
	addAnimation(1, 746, 32, "IdleLeft", 23, 21, Vector2(0, 0));
	addAnimation(1, 166, 32, "IdleRight", 23, 21, Vector2(0, 0));
	
	
	addAnimation(3, 297, 32, "WalkUp", 23, 21, Vector2(0, 0));
	addAnimation(3, 88, 32, "WalkDown", 22, 21, Vector2(0, 0));
	addAnimation(3, 770, 32, "WalkLeft", 23, 21, Vector2(0, 0));
	addAnimation(3, 189, 32, "WalkRight", 23, 21, Vector2(0, 0));

	addAnimation(4, 271, 5, "RunUp", 23, 21, Vector2(0, 0));
	addAnimation(4, 62, 5, "RunDown", 23, 21, Vector2(0, 0));
	addAnimation(4, 743, 5, "RunLeft", 23, 21, Vector2(0, 0));
	addAnimation(4, 168, 5, "RunRight", 23, 21, Vector2(0, 0));
}

void Player::moveUp()
{
	if (_y < -8.0f) { _dy = 0.0f; }
	else
	{
		_dy = -player_constants::WALK_SPEED;
		_dx = 0.0f;
		playAnimation("WalkUp");
		facing = UP;
	}
}

void Player::runUp()
{
	if (_y < -8.0f) { _dy = 0.0f; }
	else
	{
		_dy = -player_constants::RUN_SPEED;
		_dx = 0.0f;
		playAnimation("RunUp");
		facing = UP;
	}
}

void Player::moveDown()
{
	if (_y > 503.0f) { _dy = 0.0f; }
	else
	{
		_dy = player_constants::WALK_SPEED;
		_dx = 0.0f;
		playAnimation("WalkDown");
		facing = DOWN;
	}
}

void Player::runDown()
{
	if (_y > 503.0f) { _dy = 0.0f; }
	else
	{
		_dy = player_constants::RUN_SPEED;
		_dx = 0.0f;
		playAnimation("RunDown");
		facing = DOWN;
	}
}

void Player::moveRight(int levelWidth)
{
	if (_x > 930.0f) { _dx = 0.0f; }
	else
	{
		_dx = player_constants::WALK_SPEED;
		_dy = 0.0f;
		playAnimation("WalkRight");
		facing = RIGHT;
	}
}

void Player::runRight(int levelWidth)
{
	if (_x > 930.0f) { _dx = 0.0f; }
	else
	{
		_dx = player_constants::RUN_SPEED;
		_dy = 0.0f;
		playAnimation("RunRight");
		facing = RIGHT;
	}
}

void Player::moveLeft(int levelWidth)
{
	if (_x < 5.0f) { _dx = 0.0f; }
	else
	{
		_dx = -player_constants::WALK_SPEED;
		_dy = 0.0f;
		playAnimation("WalkLeft");
		facing = LEFT;
	}
}

void Player::runLeft(int levelWidth)
{
	if (_x < 5.0f) { _dx = 0.0f; }
	else
	{
		_dx = -player_constants::RUN_SPEED;
		_dy = 0.0f;
		playAnimation("RunLeft");
		facing = LEFT;
	}
}

void Player::stopMoving()
{
	_dx = 0.0f;
	_dy = 0.0f;
	switch (facing)
	{
	case 0 :
		playAnimation("IdleUp");
		break;
	
	case 1:
		playAnimation("IdleDown");
		break;
	
	case 2:
		playAnimation("IdleLeft");
		break;
	
	case 3:
		playAnimation("IdleRight");
		break;
	}
}

void Player::animationDone(string currentAnimation)
{

}

void Player::update(float elapsedTime)
{
	_x += _dx * elapsedTime;
	_y += _dy * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics)
{
	AnimatedSprite::draw(graphics, _x, _y);
}


