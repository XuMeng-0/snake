#pragma once

//�߽ڵ���������
typedef struct _snake_t {
	int x;
	int y;
	struct _snake_t* next;
}snake_t;

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


//��ʼ����
snake_t* initSnake(void);

//������
int drawSnake(snake_t* head);

//������-�ƶ�
int drawSnakeMove(snake_t* head);

//���ƶ�
int moveSnake(snake_t* head);

//���·�����ı��ߵ��ƶ�����
int keyControl(void);

//����
int testSnake(void);