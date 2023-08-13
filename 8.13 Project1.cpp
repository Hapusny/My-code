#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int C1, C2, C3;

void Switch (int* pA,int* pB)
{
	int pC = *pA;
	*pA = *pB;
	*pB = pC;
}

void screen1()
{
	printf("-----------------------------------------------------------\n");
	printf("---                     猜杯盖球游戏                    ---\n");
	printf("---                       (1.play)                      ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

void screen2()
{
	printf("-----------------------------------------------------------\n");
	printf("---                       进行选择                      ---\n");
	printf("---                      (1.位置 1)                     ---\n");
	printf("---                      (2.位置 2)                     ---\n");
	printf("---                      (3.位置 3)                     ---\n");
	printf("-----------------------------------------------------------\n");
}

void screen3()
{
	printf("-----------------------------------------------------------\n");
	printf("---                     猜杯盖球游戏                    ---\n");
	printf("---                    (1.play again)                   ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

int change()
{
	int c = rand() % 3;
	return c;
}

int main()
{
game:
	int choice1 = 0;
	srand((unsigned int)time(NULL));
	screen1();
	printf("请选择:>");
	scanf("%d", &choice1);
	system("cls");
	if (1 == choice1)
	{
		int i = 0;
		int p1 = 1;
		int p2 = 2;
		int p3 = 3;
		int C1 = 0;
		int C2 = 0;
		int C3 = 0;
		int choice2 = 0;
		int choice3 = 0;
		int f = rand() % 3;
		switch (f)
		{
		case 0:C1++;printf("小球放到了杯 1中");break;
		case 1:C2++;printf("小球放到了杯 2中");break;
		case 2:C3++;printf("小球放到了杯 3中");break;
		}
		srand((unsigned int)time(NULL));
		Sleep(2000);
		system("cls");
		for (i = 0;i < 4;i++)
		{
			int n = change();
			switch (n)
			{
			case 0:printf("杯 1与杯 2交换位置\n");Switch(&p1, &p2);break;
			case 1:printf("杯 2与杯 3交换位置\n");Switch(&p2, &p3);break;
			case 2:printf("杯 1与杯 3交换位置\n");Switch(&p1, &p3);break;
			}
			Sleep(2000);
			system("cls");
			Sleep(1000);
		}
		screen2();
		scanf("%d", &choice2);
		system("cls");
		switch (choice2)
		{
		case 1:
			if ((1 == C1&&1 == p1)|| (1 == C2 && 1 == p2)|| (1 == C3 && 1 == p3))
			{
				printf("恭喜你，猜中了\n");
			}
			else
			{
				printf("真遗憾，没猜中\n");
			}
			break;
		case 2:
			if ((1 == C1 && 2 == p1) || (1 == C2 && 2 == p2) || (1 == C3 && 2 == p3))
			{
				printf("恭喜你，猜中了\n");
			}
			else
			{
				printf("真遗憾，没猜中\n");
			}
			break;
		case 3:
			if ((1 == C1 && 3 == p1) || (1 == C2 && 3 == p2) || (1 == C3 && 3 == p3))
			{
				printf("恭喜你，猜中了\n");
			}
			else
			{
				printf("真遗憾，没猜中\n");
			}
			break;
		}
		screen3();
		scanf("%d", &choice3);
		system("cls");
		switch (choice3)
		{
		case 1:goto game;
		case 2:goto end;
		}
	}
	else
	{
		goto end;
	}
end:
	return 0;
}