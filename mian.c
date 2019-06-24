#include <stdio.h>
#include <Windows.h>

int main() {

	drawMap();
	

	return 0;
}

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

/*绘制地图*/
int drawMap() {
	int mapLength = 20;
	for (int i = 0; i < mapLength; i++) {
		for (int j = 0; j < mapLength * 2; j += 2) {
			if (0 == i || mapLength - 1 == i) {
				gotoXY(i, j);
				setColor(5);
				printf("□");
			}
			else if (0 == j || (mapLength - 1) * 2 == j) {
				gotoXY(i, j);
				setColor(5);
				printf("□");
			}
			else {
				setColor(3);
				printf("■");
			}
		}
	}
	//setColor(255);
	return 0;
}
