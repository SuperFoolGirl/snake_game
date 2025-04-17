#pragma once
#include "sprite.h"
#include <vector>

class Snake : public Sprite
{
public:
	Snake() : Snake(0, 0) {}
	Snake(int x, int y);

	void draw(); // 重写父类虚函数

	void bodymove();

	bool collision(const Sprite &other); // 这里与父类碰撞成员函数无关，只有对象才能调用成员函数

	void incrment();

private:
	// 蛇的节数 且不止一节 借助容器
	std::vector<Sprite> nodes; // 这里std::可以不写 如果用了标准命名空间的话

public:		 // 为了让外界访问
	int dir; // 表示蛇的方向
};