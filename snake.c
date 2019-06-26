#include "util.h"
#include "snake.h"
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

snake_t *head = NULL;//�ߵ�ͷ���

int direction = RIGHT;//��ǰ���ķ���

snake_t* tail = NULL;

//��ʼ����:��ͷ1���ڵ㣬����2���ڵ�
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

//������
int drawSnake(snake_t* head) {
	snake_t* temp = head;

	setColor(14);
	while (NULL != temp) {
		gotoXY(temp->y, temp->x);

		if (temp == head) {//��ͷ
			printf("��");
		}
		else{//����
			printf("��");
		}
		temp = temp->next;
	}
	gotoXY(20, 0);
	return 0;
}


//������-�ƶ�
int drawSnakeMove(snake_t* head) {
	drawSnake(head);
	gotoXY(tail->y, tail->x);
	setColor(3);
	printf("��");
	gotoXY(20, 0);
	return 0;
}


//���ƶ�
int moveSnake(snake_t* head) {
	//β
	snake_t* temp = head;
	tail = (snake_t*)malloc(sizeof(snake_t));
	while (NULL != temp) {
		if (NULL == temp->next) {
			tail->x = temp->x;
			tail->y = temp->y;
		}
		temp = temp->next;
	}

	//��
	snake_t *last = head;
	temp = head->next;

	//�ҵ�β�ڵ�
	while (NULL != temp) {
		if (NULL == temp->next) {
			break;
		}
		last = last->next;
		temp = temp->next;
	}

	//ÿ���ڵ��ֵ����һ���ڵ��ƶ�ǰ��ֵ
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

	//ͷ
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

//���·�����ı��ߵ��ƶ�����
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
