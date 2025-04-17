#pragma once
#include "sprite.h"

class Food : public Sprite
{
public:
	Food();

	void draw();

	void changePos();
};