#include "sprite.h"
#include "snake.h"

Snake::Snake(int x, int y)
{
	this->dir = VK_RIGHT; // 一开始初始化方向向右 否则蛇不走.别写int啊 int就又在重定义了
	// 初始化三节蛇
	nodes.push_back(Sprite(20, 0)); // x坐标不同
	nodes.push_back(Sprite(10, 0));
	nodes.push_back(Sprite(0, 0));
}

void Snake::draw()
{
	// 绘制每一节蛇
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i].draw();
	}
}

void Snake::bodymove()
{
	// 要让身体跟着动
	// 每一节蛇变换到上一节的位置
	// 变换的方向是从后往前 因为蛇是不断以蛇头方向移动的
	for (size_t i = nodes.size() - 1; i > 0; i--) // size返回值是size_t类型
	{
		nodes[i] = nodes[i - 1];
	}

	// 头动
	// nodes[0].moveBy(10, 0);//nodes是Snake类型的 首元素是蛇头 x轴每次移动10个像素 y不动
	// 蛇头朝着不同方向移动
	switch (dir)
	{
	case VK_UP:
		nodes[0].moveBy(0, -10);
		break;
	case VK_DOWN:
		nodes[0].moveBy(0, 10);
		break;
	case VK_LEFT:
		nodes[0].moveBy(-10, 0);
		break;
	case VK_RIGHT:
		nodes[0].moveBy(10, 0);
		break;
	}
}

bool Snake::collision(const Sprite &other)
{
	// 只有蛇头和食物碰撞才算碰撞
	// nodes是sprite类型 可以调用成员函数collision 不在一个类里不算重载
	return nodes[0].collision(other);
}

void Snake::incrment()
{
	nodes.push_back(Sprite()); // 不用传参
}
