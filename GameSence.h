#pragma once
#include "sprite.h"
#include "snake.h"
#include "food.h"

class GameSence
{
public:
	GameSence() {};

	void run();

	void onMsg(const ExMessage &msg); // 响应键盘鼠标消息 代替_getch()

	// 判断蛇能否迟到食物
	void snakeEatFood();

private:
	Snake snake;
	Food food;
};