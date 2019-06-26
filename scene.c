#include "map.h"
#include "snake.h"

/*×²Ç½ÅĞ¶Ï
*·µ»ØÖµ£º0´ú±íÎ´×²Ç½£¬1´ú±íÒÑ×²Ç½
*/
int hitWall(snake_t *head) {
	if (isWall(head->y, head->x)) {
		return 1;
	}
	else {
		return 0;
	}
}