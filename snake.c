#include "util.h"
#include "snake.h"
#include <stdlib.h>
#include <stdio.h>

snake_t *head = NULL;//蛇的头结点

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
int drawSnake() {
	snake_t* head = initSnake();
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