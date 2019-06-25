#pragma once

//蛇节点类型声明
typedef struct _snake_t {
	int x;
	int y;
	struct _snake_t* next;
}snake_t;



//初始化蛇
snake_t* initSnake(void);

//绘制蛇
int drawSnake();