
#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void screen1()
{
	printf("-----------------------------------------------------------\n");
	printf("---                         迷宫                        ---\n");
	printf("---                       (1.play)                      ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

void screen2(char maze[6][6])
{
	int i = 0;
	int j = 0;
	for (i = 0;i < 6;i++)
	{
		for (j = 0;j < 6;j++)
		{
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
	printf("(“#”为墙壁不可跨越，“i”为人物，“O”为终点)\n");
}

int move(char maze[6][6],int choice,int M)
{
	int i = M / 10;
	int j = M % 10;
	char tmp = ' ';
	switch (choice)
	{
	case 8:
		if ((0 <= i - 1 <= 5) && maze[i - 1][j] != '#')
		{
			if (maze[i - 1][j] == 'O')
			{
				return 5;
			}
			tmp = maze[i][j];
			maze[i][j] = maze[i - 1][j];
			maze[i - 1][j] = tmp;
			return (i - 1) * 10 + j;
		}
		printf("无法进行该移动\n");
		return M;
	case 2:
		if ((0 <= i + 1 <= 5) && maze[i + 1][j] != '#')
		{
			if (maze[i + 1][j] == 'O')
			{
				return 5;
			}
			tmp = maze[i][j];
			maze[i][j] = maze[i + 1][j];
			maze[i + 1][j] = tmp;
			return (i + 1) * 10 + j;
		}
		printf("无法进行该移动\n");
		return M;
	case 4:
		if ((0 <= j - 1 <= 5) && maze[i][j - 1] != '#')
		{
			if (maze[i][j - 1] == 'O')
			{
				return 5;
			}
			tmp = maze[i][j];
			maze[i][j] = maze[i][j - 1];
			maze[i][j - 1] = tmp;
			return i * 10 + j - 1;
		}
		printf("无法进行该移动\n");
		return M;
	case 6:
		if ((0 <= j + 1 <= 5) && maze[i][j + 1] != '#')
		{
			if (maze[i][j + 1] == 'O')
			{
				return 5;
			}
			tmp = maze[i][j];
			maze[i][j] = maze[i][j + 1];
			maze[i][j + 1] = tmp;
			return i * 10 + j + 1;
		}
		printf("无法进行该移动\n");
		return M;
	}
}

int main()
{
	char Maze[6][6] = {'#', '#', '#', '#','O', '#',
			    	   '#', '  ', '  ', '#','  ', '#',
			     	   '#', '  ', '#', '#','  ', '#',
	                   'i', '  ', '#', '  ','  ', '#',
		               '#', '  ', '  ', '  ','  ', '#',
	                   '#', '#', '#', '#', '#', '#',};
	int choice1 = 0;
	int choice2 = 0;
	int m = 30;
	screen1();
	printf("请选择：");
	scanf("%d", &choice1);
	Sleep(1500);
	system("cls");
	if (1 == choice1)
	{
		while (m != 5)
		{
			screen2(Maze);
			printf("\n请输入你的移动方式\n(8为向上移动，2为向下移动，4为向左移动，6为向右移动)\n");
			scanf("%d", &choice2);
			m = move(Maze, choice2, m);
			Sleep(500);
			system("cls");
		}
		printf("恭喜你，成功通过迷宫\n");
	}
	return 0;
}