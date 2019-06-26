#include "map.h"
#include "snake.h"
#include "scene.h"
#include "util.h"
#include <Windows.h>
#include <stdio.h>

#define HIT_WALL 1
#define BITE_SELF 2

int sleepTime = 500;    //单位：ms
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
			endState = HIT_WALL;
			break;
		}

		if (isBiteSelf(head)) {
			endState = BITE_SELF;
			break;
		}

		Sleep(sleepTime);
	}

	gotoXY(20,0);
	switch (endState){
		case HIT_WALL: {
			printf("game over : hit wall\n");
		};
		break;
		case BITE_SELF: {
			printf("game over : bite self\n");
		};
		break;
		default:
			break;
	}
	return 0;
}




