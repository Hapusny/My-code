#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void screen1()
{
	printf("-----------------------------------------------------------\n");
	printf("---                         扫雷                        ---\n");
	printf("---                       (1.play)                      ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

void start(char out[11][11],char in[11][11])
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	for (i = 0;i <= 10;i++)
	{
		for (j = 0;j <= 10;j++)
		{
			out[i][j] = '*';
		}
	}
	for (i = 0;i <= 10;i++)
	{
		for (j = 0;j <= 10;j++)
		{
			in[i][j] = '0';
		}
	}
	i = 0;
	srand((unsigned int)time(NULL));
	while (i < 10)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (in[x][y] == '0')
		{
			in[x][y] = '1';
		}
		else
		{
			continue;
		}
		i++;
	}
}

void screen2(char out[11][11])
{
	int i = 0;
	int j = 0;
	for (i = 0;i <= 9;i++)
	{
		for (j = 0;j <= 9;j++)
		{
			printf("%c ", out[i][j]);
		}
		printf("\n");
	}
}

void screen3(char in[11][11])
{
	int i = 0;
	int j = 0;
	printf("0 1 2 3 4 5 6 7 8 9\n");
	for (i = 1;i <= 9;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= 9;j++)
		{
			printf("%c ", in[i][j]);
		}
		printf("\n");
	}
}

void coordinate(char out[11][11])
{
	int i = 0;
	int j = 0;
	for (i = 0;i < 11;i++)
	{
		out[i][0] = i + '0';
	}
	for (j = 0;j < 11;j++)
	{
		out[0][j] = j + '0';
	}
}

int sweep(char out[11][11], char in[11][11], int x, int y)
{
	if (out[x][y] == '*')
	{
		int count = 0;
		int i = 0;
		int j = 0;
		if (in[x][y] == '1')
		{
			return 0;
		}
		else
		{
			for (i = x - 1;i <= x + 1;i++)
			{
				for (j = y - 1;j <= y + 1;j++)
				{
					if (in[i][j] == '1')
					{
						count++;
					}
				}
			}
			out[x][y] = count + '0';
			return 2;
		}
	}
	else
	{
		printf("无法选择此处\n");
		Sleep(500);
		system("cls");
		return 2;
	}
}

int mark(char out[11][11], int x, int y)
{
	if (out[x][y] == '*')
	{
		out[x][y] = 'M';
		printf("成功标记地雷\n");
		Sleep(500);
		system("cls");
		return 2;
	}
	if (out[x][y] == 'M')
	{
		out[x][y] = '*';
		printf("成功取消标记\n");
		Sleep(500);
		system("cls");
		return 2;
	}
}

int result(char out[11][11], char in[11][11],int x,int y)
{
	if (in[x][y] == '1')
	{
		return 0;
	}
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1;i <= 9;i++)
	{
		for (j = 1;j <= 9;j++)
		{
			if (out[i][j] == 'M'|| out[i][j] == '*')
			{
				count++;
			}
		}
	}
	if (count == 10)
	{
		return 1;
	}
	return 2;
}

void spread(char out[11][11], char in[11][11], int x, int y)
{
	if (out[x][y] == '0'&&(1 <= x)&&(x <= 9)&&(1 <= y) && (y <= 9))
	{
		int i = 0;
		int j = 0;
		for (i = x - 1;i <= x + 1;i++)
		{
			for (j = y - 1;j <= y + 1;j++)
			{
				if (out[i][j] == '*')
				{
					sweep(out,in,i,j);
					spread(out, in, i, j);
				}
			}
		}
	}
}

int main()
{
	int choice1 = 0;
	int choice2 = 0;
	int x = 0;
	int y = 0;
	int count = 0;
	int end = 0;
	char out[11][11] = { 0 };
	char in[11][11] = { 0 };
	screen1();
	printf("请选择：");
	scanf("%d", &choice1);
	Sleep(1500);
	system("cls");
	if (1 == choice1)
	{
		start(out, in);
		coordinate(out);
	choose:
		screen2(out);
		printf("请输入你选择的方式及坐标(先行后列)\n(扫除为0，标记为1，数字之间用空格隔开)\n");
		scanf("%d %d %d", &choice2,&x,&y);
		if (choice2)
		{
			end = mark(out, x, y);
		}
		else
		{
			end = sweep(out, in, x, y);
			end = result(out, in, x, y);
			spread(out, in, x, y);
		}
		Sleep(1000);
		system("cls");
		switch (end)
		{
		case 0:
			printf("很遗憾，你扫雷失败\n");
			screen3(in);
			return 0;
		case 1:
			break;
		case 2:
			goto choose;
		}
		printf("恭喜你，扫雷成功\n");
	}
	return 0;
}