
#include"8.20 game1.h"

void screen1()
{
	printf("-----------------------------------------------------------\n");
	printf("---                        井字棋                       ---\n");
	printf("---                       (1.play)                      ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

void board(char pieces[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i ++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ",pieces[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		if (i < row - 1)
		{
			printf("\n");
			for (j = 0;j < col;j++)
			{
				printf("---", pieces[i][j]);
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

int place_p(char pieces[ROW][COL],int choice)
{
	int x = 0;
	int y = 0;
	switch (choice)
	{
	case 1:x = 2;y = 0;break;
	case 2:x = 2;y = 1;break;
	case 3:x = 2;y = 2;break;
	case 4:x = 1;y = 0;break;
	case 5:x = 1;y = 1;break;
	case 6:x = 1;y = 2;break;
	case 7:x = 0;y = 0;break;
	case 8:x = 0;y = 1;break;
	case 9:x = 0;y = 2;break;
	}
	if (pieces[x][y] != '*'&&pieces[x][y] != '#')
	{
		pieces[x][y] ='*';
		return 1;
	}
	else
	{
		printf("此处无法下棋\n");
		return 0;
	}
}

void place_c(char pieces[ROW][COL])
{
start:
	srand((unsigned int)time(NULL));
	int choice = rand() % 9 + 1;
	int x = 0;
	int y = 0;
	switch (choice)
	{
	case 1:x = 2;y = 0;break;
	case 2:x = 2;y = 1;break;
	case 3:x = 2;y = 2;break;
	case 4:x = 1;y = 0;break;
	case 5:x = 1;y = 1;break;
	case 6:x = 1;y = 2;break;
	case 7:x = 0;y = 0;break;
	case 8:x = 0;y = 1;break;
	case 9:x = 0;y = 2;break;
	}
	if (pieces[x][y] != '*'&&pieces[x][y] != '#')
	{
		pieces[x][y] = '#';
	}
	else
	{
		goto start;
	}
}

int judge_p(char pieces[ROW][COL])
{
	if ((pieces[0][0] == '*'
		&& pieces[1][1] == '*'
		&& pieces[2][2] == '*') ||
		(pieces[0][2] == '*'
			&& pieces[1][1] == '*'
			&& pieces[2][0] == '*') ||
		(pieces[0][0] == '*'
			&& pieces[0][1] == '*'
			&& pieces[0][2] == '*') ||
		(pieces[1][0] == '*'
			&& pieces[1][1] == '*'
			&& pieces[1][2] == '*') ||
		(pieces[2][0] == '*'
			&& pieces[2][1] == '*'
			&& pieces[2][2] == '*') ||
		(pieces[0][0] == '*'
			&& pieces[1][0] == '*'
			&& pieces[2][0] == '*') ||
		(pieces[0][1] == '*'
			&& pieces[1][1]== '*'
			&& pieces[2][1] == '*') ||
		(pieces[0][2] == '*'
			&& pieces[1][2] == '*'
			&& pieces[2][2] == '*'))
	{
		return 1;
	}
	return 0;
}

int judge(char pieces[ROW][COL])
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			if (pieces[i][j] == '*' || pieces[i][j] == '#')
			{
				count + 1;
			}
		}
	}
	if (9 == count)
	{
		return 3;
	}
	return 0;
}

int judge_c(char pieces[ROW][COL])
{
	if ((pieces[0][0] == '#'
		&& pieces[1][1] == '#'
		&& pieces[2][2] == '#') ||
		(pieces[0][2] == '#'
			&& pieces[1][1] == '#'
			&& pieces[2][0] == '#')||
		(pieces[0][0] == '#'
			&& pieces[0][1] == '#'
			&& pieces[0][2] == '#')||
		(pieces[1][0] == '#'
			&& pieces[1][1] == '#'
			&& pieces[1][2] == '#')|| 
		(pieces[2][0] == '#'
			&& pieces[2][1] == '#'
			&& pieces[2][2] == '#')|| 
		(pieces[0][0] == '#'
			&& pieces[1][0] == '#'
			&& pieces[2][0] == '#')|| 
		(pieces[0][1] == '#'
			&& pieces[1][1] == '#'
			&& pieces[2][1] == '#')|| 
		(pieces[0][2] == '#'
			&& pieces[1][2] == '#'
			&& pieces[2][2] == '#'))
	{
		return 2;
	}
	return 0;
}