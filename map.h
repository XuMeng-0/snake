#pragma once

/*绘制地图*/
int drawMap();

/*判断某个坐标是否在墙上
*返回值：0表示不在墙上，1表示在
*/
int isWall(int x, int y);