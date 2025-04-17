#include "sprite.h"
#include "GameSence.h"
#include <graphics.h>

void GameSence::run()
{
	BeginBatchDraw(); // 双缓冲绘图
	cleardevice();	  // 清屏 防止蛇无限在屏幕移动
	snake.draw();	  // 蛇也要绘制啊
	food.draw();
	EndBatchDraw();

	// 移动蛇 改变其坐标
	snake.bodymove();

	snakeEatFood();

	// 获取消息
	ExMessage msg = {0};			  // 转到定义发现EM是个结构体
	while (peekmessage(&msg, EM_KEY)) // 通过while来看有没有消息 没有了就跳出循环
	{
		onMsg(msg);
	}
}

void GameSence::onMsg(const ExMessage &msg)
{
	// 如果有键盘按下
	if (msg.message == WM_KEYDOWN)
	{
		// 改变蛇的移动方向 获取键盘 _getch()
		// 判断具体是哪个键按下 virsual key code 虚拟键码
		if (msg.vkcode == VK_UP ||
			msg.vkcode == VK_DOWN ||
			msg.vkcode == VK_LEFT ||
			msg.vkcode == VK_RIGHT) // 只有按上下左右的时候 才会执行读取
		{
			snake.dir = msg.vkcode;
		}
		switch (msg.vkcode)
		{
		case VK_UP:
			if (snake.dir != VK_DOWN) // 不能原地掉头
				snake.dir = msg.vkcode;
		case VK_DOWN:
			if (snake.dir != VK_UP)
				snake.dir = msg.vkcode;
		case VK_LEFT:
			if (snake.dir != VK_RIGHT)
				snake.dir = msg.vkcode;
		case VK_RIGHT:
			if (snake.dir != VK_LEFT)
				snake.dir = msg.vkcode;
		default:
			break;
		}
	}
}

void GameSence::snakeEatFood()
{
	if (snake.collision(food)) // 如果蛇和食物产生了碰撞
	{
		// 蛇增加一节 食物随机生成新的 为了体现模块化思想 单独写一个函数
		snake.incrment();
		food.changePos();
	}
}