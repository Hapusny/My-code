#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <time.h>

void screen1()
{
	printf("-----------------------------------------------------------\n");
	printf("---                         归位                        ---\n");
	printf("---                       (1.play)                      ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

void Switch(int* num1, int* num2)
{
	int num3 = 0;
	num3 = *num2;
	*num2 = *num1;
	*num1 = num3;
}

void RAND(int place[12])
{
	int i = 0;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 6; i++)
	{
		int num1 = rand() % 12;
		int num2 = rand() % 12;
		if (num1 != num2)
		{
			Switch(place + num1, place + num2);
		}
		else
		{
			continue;
		}
	}
}

void screen2(int place[12])
{
	int i = 0;
	int j = 0;
	printf(" /  1  2  3\n");
	for (i = 0;i < 4;i++)
	{
		printf("%2d ", i + 1);
		for (j = 0;j < 3;j++)
		{
			printf("%02d ", place[3 * i + j]);
		}
		printf("\n");
	}
}

int judge(int place[12],int answer[12])
{
	int i = 0;
	for (i = 0;i < 12;i++)
	{
		if (place[i] != answer[i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int choice1 = 0;
	int TIME = 0;
	int Place[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	int Answer[12] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	screen1();
	printf("请输入你的选择\n");
	scanf("%d", &choice1);
	system("cls");
	if (1 == choice1)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		int end = 0;
		RAND(Place);
		for (TIME = 0;TIME < 6;TIME++)
		{
			printf("换位次数为:%d\n", TIME);
			printf("最后目标:\n");
			screen2(Answer);
			printf("当前情况:\n");
			screen2(Place);
			printf("请输入你要交换的两个数字的坐标\n(先输入行，在输入列，每个数之间用空格隔开)\n");
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			Switch(Place + 3 * (x1 - 1) + y1 - 1, Place + 3 * (x2 - 1) + y2 - 1);
			Sleep(1500);
			system("cls");
			end = judge(Answer, Place);
			if (1 == end)
			{
				break;
			}
		}
		printf("换位次数为:%d\n", TIME);
		printf("最后目标:\n");
		screen2(Answer);
		printf("当前情况:\n");
		screen2(Place);
		switch (end)
		{
		case 0:
			printf("归位失败，未在6次换位内成功归位\n");
			break;
		case 1:
			printf("恭喜，在6次换位内成功归位\n");
			break;
		}
	}
 	return 0;
}