#include "map.h"
#include "snake.h"
#include "scene.h"
#include "util.h"
#include <Windows.h>
#include <stdio.h>

int sleepTime = 500;//单位：ms
int endState = 0;       //结束原因

int main() {

	drawMap();

	snake_t* head = initSnake();
	drawSnake(head);

	while (1) {
		keyControl();
		
		moveSnake(head);
		drawSnakeMove(head);

		if (isHitWall(head)) {
			break;
		}

		Sleep(sleepTime);
	}

	gotoXY(20,0);
	printf("game over : hit wall\n");
	return 0;
}




