#include "animatedsprite.h"
#include "graphics.h"
#include "sprite.h"

using std::pair;

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics& graphics, const string& filePath, int sourceX, int sourceY,
	int width, int height, float posX, float posY, float timeToUpdate) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	_frameIndex(0),
	_timeElapsed(0),
	_timeToUpdate(timeToUpdate),
	_visible(true),
	_currentAnimationOnce(false),
	_currentAnimation("")
{}

void AnimatedSprite::addAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset) {
	vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++) {
		SDL_Rect newRect = { x + (i * width), y, width, height };
		rectangles.push_back(newRect);
	}
	_animations.insert(pair<string, vector<SDL_Rect> >(name, rectangles));
	_offsets.insert(pair<string, Vector2>(name, offset));
}

void AnimatedSprite::resetAnimations() {
	_animations.clear();
	_offsets.clear();
}

void AnimatedSprite::playAnimation(string animation, bool once) {
	_currentAnimationOnce = once;
	if (_currentAnimation != animation) {
		_currentAnimation = animation;
		_frameIndex = 0;
	}
}

void AnimatedSprite::setVisible(bool visible) {
	_visible = visible;
}

void AnimatedSprite::stopAnimation() {
	_frameIndex = 0;
	animationDone(_currentAnimation);
}

void AnimatedSprite::update(int elapsedTime) {
	Sprite::update();

	_timeElapsed += elapsedTime;
	if (_timeElapsed > _timeToUpdate) {
		_timeElapsed -= _timeToUpdate;
		if (_frameIndex < _animations[_currentAnimation].size() - 1) {
			_frameIndex++;
		}
		else {
			if (_currentAnimationOnce == true) {
				setVisible(false);
			}
			_frameIndex = 0;
			animationDone(_currentAnimation);
		}
	}
}

void AnimatedSprite::draw(Graphics& graphics, int x, int y) {
	if (_visible) {
		SDL_Rect destinationRectangle;
		destinationRectangle.x = x + _offsets[_currentAnimation].x;
		destinationRectangle.y = y + _offsets[_currentAnimation].y;
		destinationRectangle.w = _sourceRect.w * globals::SPRITE_SCALE;
		destinationRectangle.h = _sourceRect.h * globals::SPRITE_SCALE;

		SDL_Rect sourceRect = _animations[_currentAnimation][_frameIndex];
		graphics.blitSurface(_spriteSheet, &sourceRect, &destinationRectangle);
	}
}

void AnimatedSprite::animationDone(std::string currentAnimation) {}

void AnimatedSprite::setupAnimations() {
	addAnimation(3, 78, 438, "Idle", 59, 46, Vector2(0, 0));
}