#include "sprite.h"
#include "food.h"

void Food::draw()
{
	setfillcolor(this->m_color);
	solidellipse(m_x, m_y, m_x + 10, m_y + 10);
}

Food::Food()
{
	changePos();
}

void Food::changePos()
{
	// 随机生成坐标
	// 这样写 很难吃到食物 因为蛇的移动是10的整数倍
	// m_x = rand() % 640;
	// m_y = rand() % 480;
	m_x = rand() % 64 * 10;
	m_y = rand() % 48 * 10;
}
