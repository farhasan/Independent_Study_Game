#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

using std::map;
using std::string;
using std::vector;

class Graphics;

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(Graphics& graphics, const string& filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY, float timeToUpdate);

	void playAnimation(string animation, bool once = false);
	void update(int elapsedTime);
	void draw(Graphics& graphics, int x, int y);

	map<string, vector<SDL_Rect>> getAnimations();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	string _currentAnimation;

	void addRightAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset);
	void addLeftAnimation(int frames, int x, int y, string name, int width, int height, Vector2 offset);
	void addFrameToAnimation(map <string, vector<SDL_Rect>>& animations, string animationName, int x, int y, int width, int height);
	void resetAnimations();
	void stopAnimation();
	void setVisible(bool visible);
	virtual void animationDone(string currentAnimation) = 0;
	virtual void setupAnimations() = 0;

private:
	int _frameIndex;
	double _timeElapsed;
	bool _visible;

	map <string, vector<SDL_Rect>> _animations;
	map <string, Vector2> _offsets;

};

#endif // !ANIMATEDSPRITE_H

