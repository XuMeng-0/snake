#include "util.h"
#include <stdio.h>

int mapLength = 20;

/*判断某个坐标是否在墙上
*参数：x代表行，y代表列
*返回值：0表示不在墙上，1表示在
*/
int isWall(int x, int y) {
	if (0 == x || mapLength - 1 == x) {
		return 1;
	}
	if (0 == y || (mapLength - 1) * 2 == y) {
		return 1;
	}
	return 0;
}

/*绘制地图*/
int drawMap() {	
	for (int i = 0; i < mapLength; i++) {
		for (int j = 0; j < mapLength * 2; j += 2) {
			if (0 == i || mapLength - 1 == i) {
				gotoXY(i, j);
				setColor(5);
				printf("□");
			}
			else if (0 == j || (mapLength - 1) * 2 == j) {
				gotoXY(i, j);
				setColor(5);
				printf("□");
			}
			else {
				setColor(3);
				printf("■");
			}
		}
	}
	return 0;
}