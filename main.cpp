/*
oop设计思路
1. gamesence作为系统类，负责游戏底层逻辑（移动）、键盘响应、游戏状态（开始、结束）等
2. sprite类作为基类，负责绘制、碰撞检测等功能
3. snake类作为派生类，负责蛇的绘制、移动、碰撞检测等功能
4. food类作为派生类，负责食物的绘制、碰撞检测等功能
5. 游戏主函数负责游戏的初始化、循环等功能
*/

#include "sprite.h"
#include "snake.h"
#include "GameSence.h"
#include <graphics.h>
#include <ctime>

int main()
{
	initgraph(640, 480, EX_SHOWCONSOLE); // 窗口大小 这里只能用EX 不能用EM

	srand(time(nullptr)); // 设置随机数种子

	GameSence gs;

	while (true)
	{
		gs.run(); // 蛇不断移动位置
		Sleep(50);
	}

	getchar(); // 防止闪退

	return 0;
}