#include <Windows.h>
#include <stdio.h>

/*��λ��굽ָ������(�У���)*/
int gotoXY(int x, int y) {
	COORD c;
	c.X = y;
	c.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

/*���ÿ���̨������ݵ���ɫ*/
int setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return 0;
}