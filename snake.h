#pragma once

//蛇节点类型声明
typedef struct _snake_t {
	int x;//列坐标
	int y;//行坐标
	struct _snake_t* next;
}snake_t;

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


//初始化蛇
snake_t* initSnake(void);

//绘制蛇
int drawSnake(snake_t* head);

//绘制蛇-移动
int drawSnakeMove(snake_t* head);

//蛇移动
int moveSnake(snake_t* head);

//按下方向键改变蛇的移动方向
int keyControl(void);