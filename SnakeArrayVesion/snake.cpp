#include "snake.h"
#include <stdlib.h>
//外部链接
extern int fangXiang ;//方向： 0 右 1 上 2 左 3 下
extern int appleLie ;//苹果所在列
extern int appleHang  ;//苹果所在行
extern int snakeHang[100] ;//蛇的所有节的行
extern int snakeLie[100]  ;//蛇的所有节的列
extern int snakeLength ;//蛇当前长度
/*蛇 爬行*/
void snakeMove()
{
	for (int jie = snakeLength - 1; jie > 0; jie--)
	{
		snakeHang[jie] = snakeHang[jie - 1];
		snakeLie[jie] = snakeLie[jie - 1];
	}
	//蛇头动  : 根据方向 多选一
	switch (fangXiang)
	{
	case 0:
		snakeLie[0]++;
		break;
	case 1:
		snakeHang[0]--;
		break;
	case 2:
		snakeLie[0]--;
		break;
	case 3:
		snakeHang[0]++;
		break;
	}
}
/*能吃到 苹果
返回值：1 能 0 不能 */
int enabledEatApple()
{
	return appleHang == *snakeHang
		&& appleLie == *snakeLie;
}
/*蛇 长个了*/
void grow()
{
	snakeLength++;
}
/*创建 新苹果*/
void createApple()
{
	appleLie = rand() % 16 + 2;
	appleHang = rand() % 16 + 2;
}

/*能咬自己
返回值：1 能 0 不能 */
int enabledEatSelf()
{
	int enabledDie = 0;//0代表假
	for (int i = 1; i < snakeLength; i++)
	{
		if (snakeHang[0] == snakeHang[i]
			&& snakeLie[0] == snakeLie[i])
		{
			enabledDie = 1;//非0代表真
			return 1;
		}
	}
	return 0;
}


/*能出界
返回值：1 能 0 不能 */
int enabledOut()
{
	return *snakeHang == 0 || *snakeHang == 19
		|| *snakeLie == 0 || *snakeLie == 19;
}
/*游戏结束*/
void gameover()
{
	extern int stop;
	stop = 1;
}

/*转向 */
void turnLeft()
{
	if (fangXiang != 0)
	{
		fangXiang = 2;
	}
}
void turnRight()
{
	if (fangXiang != 2)
	{
		fangXiang = 0;
	}
}
void turnTop()
{
	if (fangXiang != 3)
	{
		fangXiang = 1;
	}
}
void turnBottom()
{
	if (fangXiang != 1)
	{
		fangXiang = 3;
	}
}