#include "util.h"
#include <stdio.h>

/*���Ƶ�ͼ*/
int drawMap() {
	int mapLength = 20;
	for (int i = 0; i < mapLength; i++) {
		for (int j = 0; j < mapLength * 2; j += 2) {
			if (0 == i || mapLength - 1 == i) {
				gotoXY(i, j);
				setColor(5);
				printf("��");
			}
			else if (0 == j || (mapLength - 1) * 2 == j) {
				gotoXY(i, j);
				setColor(5);
				printf("��");
			}
			else {
				setColor(3);
				printf("��");
			}
		}
	}
	//setColor(255);
	return 0;
}