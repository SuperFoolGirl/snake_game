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