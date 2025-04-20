#pragma once
#include "sprite.h"

class Food : public Sprite
{
public:
	Food();

	virtual void draw();

	void changePos();
};