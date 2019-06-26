#include "map.h"
#include "snake.h"
#include <stdlib.h>

/*判断是否撞墙
*参数：蛇的头结点
*返回值：0代表未撞墙，1代表已撞墙
*算法：调用地图类的isWall（）方法，参数为蛇的头结点坐标，返回值为1代表已撞墙，0代表未撞墙
*/
int isHitWall(snake_t *head) {
	if (isWall(head->y, head->x)) {
		return 1;
	}
	else {
		return 0;
	}
}

/*判断是否咬到自己
*参数：蛇的头结点
*返回值：0代表否，1代表是
*算法：将头结点的坐标依次与其它结点比较，如果有相同，则咬到自己；否则未咬到自己
*/
int isBiteSelf(snake_t* head) {
	snake_t* temp = head->next;
	while (NULL != temp){
		if (temp->x == head->x && temp->y == head->y) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}