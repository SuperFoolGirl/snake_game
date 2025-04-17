#include "sprite.h"

void Sprite::draw()
{
	// 填充颜色
	setfillcolor(this->m_color);

	// 绘制矩形
	fillrectangle(this->m_x, this->m_y, (this->m_x + 10), (this->m_y + 10)); // 不再创建新变量设置宽高
}

void Sprite::moveBy(int dx, int dy)
{
	this->m_x += dx;
	this->m_y += dy;
}

bool Sprite::collision(const Sprite &other)
{
	return this->m_x == other.m_x && this->m_y == other.m_y;
}