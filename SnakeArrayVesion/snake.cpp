#include "snake.h"
#include <stdlib.h>
//�ⲿ����
extern int fangXiang ;//���� 0 �� 1 �� 2 �� 3 ��
extern int appleLie ;//ƻ��������
extern int appleHang  ;//ƻ��������
extern int snakeHang[100] ;//�ߵ����нڵ���
extern int snakeLie[100]  ;//�ߵ����нڵ���
extern int snakeLength ;//�ߵ�ǰ����
/*�� ����*/
void snakeMove()
{
	for (int jie = snakeLength - 1; jie > 0; jie--)
	{
		snakeHang[jie] = snakeHang[jie - 1];
		snakeLie[jie] = snakeLie[jie - 1];
	}
	//��ͷ��  : ���ݷ��� ��ѡһ
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
/*�ܳԵ� ƻ��
����ֵ��1 �� 0 ���� */
int enabledEatApple()
{
	return appleHang == *snakeHang
		&& appleLie == *snakeLie;
}
/*�� ������*/
void grow()
{
	snakeLength++;
}
/*���� ��ƻ��*/
void createApple()
{
	appleLie = rand() % 16 + 2;
	appleHang = rand() % 16 + 2;
}

/*��ҧ�Լ�
����ֵ��1 �� 0 ���� */
int enabledEatSelf()
{
	int enabledDie = 0;//0�����
	for (int i = 1; i < snakeLength; i++)
	{
		if (snakeHang[0] == snakeHang[i]
			&& snakeLie[0] == snakeLie[i])
		{
			enabledDie = 1;//��0������
			return 1;
		}
	}
	return 0;
}


/*�ܳ���
����ֵ��1 �� 0 ���� */
int enabledOut()
{
	return *snakeHang == 0 || *snakeHang == 19
		|| *snakeLie == 0 || *snakeLie == 19;
}
/*��Ϸ����*/
void gameover()
{
	extern int stop;
	stop = 1;
}

/*ת�� */
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