#pragma once

//�߽ڵ���������
typedef struct _snake_t {
	int x;
	int y;
	struct _snake_t* next;
}snake_t;



//��ʼ����
snake_t* initSnake(void);

//������
int drawSnake();