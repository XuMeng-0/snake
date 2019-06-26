#include "util.h"
#include <stdio.h>

int mapLength = 20;

/*�ж�ĳ�������Ƿ���ǽ��
*������x�����У�y������
*����ֵ��0��ʾ����ǽ�ϣ�1��ʾ��
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

/*���Ƶ�ͼ*/
int drawMap() {	
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
	return 0;
}