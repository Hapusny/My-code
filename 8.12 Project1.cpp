#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void screen1()
{
	printf("-----------------------------------------------------------\n");
	printf("---                       猜拳游戏                      ---\n");
	printf("---                       (1.play)                      ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

void screen2()
{
	printf("-----------------------------------------------------------\n");
	printf("---                       进行选择                      ---\n");
	printf("---                       (1.石头)                      ---\n");
	printf("---                       (2.剪刀)                      ---\n");
	printf("---                       (3. 布 )                      ---\n");
	printf("-----------------------------------------------------------\n");
}

void screen3()
{
	printf("-----------------------------------------------------------\n");
	printf("---                       猜拳游戏                      ---\n");
	printf("---                    (1.play again)                   ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

int opponent()
{
again:
	int a = rand() % 10;
	int b = 0;
	if (9 == a)
	{
		goto again;
	}
	else
	{
		b = a / 3 + 1;
	}
	return b;
}

int judge(int x, int y)
{
	int z = 0;
	if ((x == 1&&y == 2)||(x == 2&&y == 3)||(x == 3&&y == 1))
	{
		z = 0;
	}
	else if ((x == 1 && y == 3) || (x == 2 && y == 1) || (x == 3 && y == 2))
	{
		z = 1;
	}
	else
	{
		z = 2;
	}
	return z;
}

void transform(int num)
{
	switch (num)
	{
	case 1:printf("使用了石头\n");break;
	case 2:printf("使用了剪刀\n");break;
	case 3:printf("使用了 布 \n");break;
	}
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
		int n1 = 0;
		int n2 = 0;
		int choice2 = 0;
		int choice3 = 0;
		for (i = 1;i <= 3;i++)
		{
			int mode = opponent();
			screen2();
			scanf("%d", &choice2);
			system("cls");
			int result = judge(choice2, mode);
			switch (result)
			{
			case 0:printf(" 你 ");
				transform(choice2);
				printf("对手");
				transform(mode);
				printf("第%d轮交锋，你取得了优势\n", i);
				Sleep(3000);
				system("cls");
				n1++;
				break;
			case 1:printf(" 你 ");
				transform(choice2);
				printf("对手");
				transform(mode);
				printf("第%d轮交锋，对手取得了优势\n", i);
				Sleep(3000);
				system("cls");
				n2++;
				break;
			case 2:printf(" 你 ");
				transform(choice2);
				printf("对手");
				transform(mode);
				printf("第%d轮交锋，你们打了个平手\n", i);
				Sleep(3000);
				system("cls");
				break;
			}
		}
		if (n1 > n2)
		{
			printf("三轮交锋，你共取得%d次胜利，而你的对手共取得%d次胜利\n", n1, n2);
			printf("恭喜你取得了最终的胜利！\n");
		}
		if (n1 < n2)
		{
			printf("三轮交锋，你共取得%d次胜利，而你的对手共取得%d次胜利\n", n1, n2);
			printf("遗憾，你没能战胜你的对手\n");
		}
		if (n1 == n2)
		{
			printf("三轮交锋，你共取得%d次胜利，而你的对手共取得%d次胜利\n", n1, n2);
			printf("势均力敌，你们没能决出最终的胜利者\n");
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