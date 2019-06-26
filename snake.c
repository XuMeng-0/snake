#include "util.h"
#include "snake.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

snake_t *head = NULL;//蛇的头结点

int direction = RIGHT;//蛇前进的方向

snake_t* tail = NULL;

//初始化蛇:蛇头1个节点，蛇身2个节点
snake_t* initSnake(void) {
	snake_t *new = NULL;
	
	for (int i = 0; i < 4; i++) {
		new = (snake_t*)malloc(sizeof(snake_t));

		new->x = 10 + i * 2;
		new->y = 10;
		new->next = NULL;

		new->next = head;
		head = new;
	}
	return head;
}

//绘制蛇
int drawSnake(snake_t* head) {
	snake_t* temp = head;

	setColor(14);
	while (NULL != temp) {
		gotoXY(temp->y, temp->x);

		if (temp == head) {//蛇头
			printf("●");
		}
		else{//蛇身
			printf("★");
		}
		temp = temp->next;
	}
	gotoXY(20, 0);
	return 0;
}


//绘制蛇-移动
int drawSnakeMove(snake_t* head) {
	drawSnake(head);
	gotoXY(tail->y, tail->x);
	setColor(3);
	printf("■");
	gotoXY(20, 0);
	return 0;
}


//蛇移动
int moveSnake(snake_t* head) {
	//尾
	snake_t* temp = head;
	tail = (snake_t*)malloc(sizeof(snake_t));
	while (NULL != temp) {
		if (NULL == temp->next) {
			tail->x = temp->x;
			tail->y = temp->y;
		}
		temp = temp->next;
	}

	//身
	snake_t *last = head;
	temp = head->next;

	//找到尾节点
	while (NULL != temp) {
		if (NULL == temp->next) {
			break;
		}
		last = last->next;
		temp = temp->next;
	}

	//每个节点的值是上一个节点移动前的值
	while (temp != head) {
		temp->x = last->x;
		temp->y = last->y;
		temp = last;
		last = head;
		while (last->next != temp) {
			last = last->next;
			if (temp == head) {
				break;
			}
		}
	}

	//头
	if (direction == RIGHT) {
		head->x += 2;
	}
	if (direction == UP) {
		head->y -= 1;
	}
	if (direction == LEFT) {
		head->x -= 2;
	}
	if (direction == DOWN) {
		head->y += 1;
	}

	return 0;
}

//按下方向键改变蛇的移动方向
int keyControl(void) {
		if (GetAsyncKeyState(VK_UP) && direction != DOWN) {
			direction = UP;
		}
		if (GetAsyncKeyState(VK_DOWN) && direction != UP) {
			direction = DOWN;
		}
		if (GetAsyncKeyState(VK_LEFT) && direction != RIGHT) {
			direction = LEFT;
		}
		if (GetAsyncKeyState(VK_RIGHT) && direction != LEFT) {
			direction = RIGHT;
		}
	return 0;
}
