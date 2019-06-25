#include <Windows.h>
#include <stdio.h>

/*定位光标到指定坐标(行，列)*/
int gotoXY(int x, int y) {
	COORD c;
	c.X = y;
	c.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

/*设置控制台输出内容的颜色*/
int setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return 0;
}