#include "map.h"
#include "snake.h"

/*ײǽ�ж�
*����ֵ��0����δײǽ��1������ײǽ
*/
int isHitWall(snake_t *head) {
	if (isWall(head->y, head->x)) {
		return 1;
	}
	else {
		return 0;
	}
}