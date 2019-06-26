#include "map.h"
#include "snake.h"
#include <stdlib.h>

/*�ж��Ƿ�ײǽ
*�������ߵ�ͷ���
*����ֵ��0����δײǽ��1������ײǽ
*�㷨�����õ�ͼ���isWall��������������Ϊ�ߵ�ͷ������꣬����ֵΪ1������ײǽ��0����δײǽ
*/
int isHitWall(snake_t *head) {
	if (isWall(head->y, head->x)) {
		return 1;
	}
	else {
		return 0;
	}
}

/*�ж��Ƿ�ҧ���Լ�
*�������ߵ�ͷ���
*����ֵ��0�����1������
*�㷨����ͷ���������������������Ƚϣ��������ͬ����ҧ���Լ�������δҧ���Լ�
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