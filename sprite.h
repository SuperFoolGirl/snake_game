#pragma once
#include <iostream>
using namespace std;

#include <easyx.h> // 下载的库

// 精灵类作为父类 贪吃蛇和食物继承它
class Sprite
{
public:
	Sprite() : Sprite(0, 0) {};								// 委托构造，构造函数全部交给下面的构造函数
	Sprite(int x, int y) : m_x(x), m_y(y), m_color(RED) {};

	// 用于绘制精灵
	virtual void draw();

	void moveBy(int dx, int dy);

	// 碰撞检测
	bool collision(const Sprite &other);

	// 注意下属性里放的都是游戏固有背景的那些东西 坐标、颜色
protected: // 只有派生类才可以访问
	int m_x;
	int m_y;
	COLORREF m_color;
};