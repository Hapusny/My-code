#define _CRT_SECURE_NO_WARNINGS 

#define FOOD 1
#define WALL 2
#define FPS (1000 / 30.0f)

#include <easyx.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#pragma comment(lib,"winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int Start()
{
	int starttime,flashtime;
	IMAGE snake;
	loadimage(&snake, _T("./res/greedy_snake.png"), 200, 200);
	mciSendString(L"open ./res/kada.mp3 alias music1", 0, 0, 0);
	TCHAR s0[5] = _T("开始游戏");
	TCHAR s1[5] = _T("结束游戏");
	TCHAR s2[4] = _T("贪吃蛇");
	ExMessage message;
	starttime = clock();
	setbkmode(TRANSPARENT);
	while(TRUE)
	{
		flashtime = clock() - starttime;
		if (flashtime >= FPS)
		{
			cleardevice();
			putimage(390, 100, &snake);
			rectangle(390, 400, 590, 450);
			rectangle(390, 500, 590, 550);
			settextstyle(16, 0, _T("宋体"));
			outtextxy(460, 416, s0);
			outtextxy(460, 516, s1);
			settextstyle(32, 0, _T("宋体"));
			outtextxy(440, 310, s2);
			FlushBatchDraw();
			if (message.x >= 390 && message.x <= 590)
			{
				if (message.y >= 400 && message.y <= 450)
				{
					solidrectangle(390, 400, 590, 450);
					FlushBatchDraw();
					clearrectangle(390, 400, 590, 450);
					if (message.lbutton)
					{
						mciSendString(L"play music1", 0, 0, 0);
						return 1;
					}
				}
				if (message.y >= 500 && message.y <= 550)
				{
					solidrectangle(390, 500, 590, 550);
					FlushBatchDraw();
					clearrectangle(390, 500, 590, 550);
					if (message.lbutton)
					{
						mciSendString(L"play music1", 0, 0, 0);
						return 0;
					}
				}
			}
			starttime = clock();
		}
		peekmessage(&message, EX_MOUSE);
	}
}

void Show(int arr[45][75],int x,int y,int direction,int begin,int count,int speed_up,int end)
{
	int i, j;
	IMAGE door[2];
	loadimage(&door[0], _T("./res/door1.png"),56,56);
	loadimage(&door[1], _T("./res/door2.png"),56,56);
	TCHAR s1[4] = _T("得分：");
	TCHAR s2[3];
	_stprintf(s2, _T("%d"), count);
	settextstyle(16, 0, _T("宋体"));
	setlinecolor(WHITE);
	rectangle(100, 50, 875, 515);
	setfillcolor(RGB(127, 127, 127));
	outtextxy(890, 70, s1);
	outtextxy(940, 70, s2);
	for (i = 0;i < 15;i++)line(100, 81 + 31 * i, 875, 81 + 31 * i);
	for (i = 0;i < 25;i++)line(131 + 31 * i, 50, 131 + 31 * i, 515);
	if (begin <= 3)
	{
		putimage(90 + 31 * ((37 - 1) / 3), 40 + 31 * ((22 - 1) / 3), &door[0], SRCAND);
		putimage(90 + 31 * ((37 - 1) / 3), 40 + 31 * ((22 - 1) / 3), &door[1], SRCPAINT);
		setfillcolor(RGB(127, 127, 127));
		solidcircle(116 + 31 * ((37 - 1) / 3), 66 + 31 * ((22 - 1) / 3), 14);
	}
	for (i = 1;i < 45;i+=3)
	{
		for (j = 1;j < 75;j+=3)
		{
			if (arr[i][j] == 1)
			{
				setfillcolor(RGB(127, 127, 127));
				solidcircle(116 + 31 * ((j - 1) / 3), 66 + 31 * ((i - 1) / 3), 14);
			}
			if (arr[i][j] == 5)
			{
				setfillcolor(RGB(133, 140, 255));
				solidcircle(116 + 31 * ((j - 1) / 3), 66 + 31 * ((i - 1) / 3), 10);
			}
			if (arr[i][j] == 8)
			{
				setfillcolor(WHITE);
				solidrectangle(100 + 31 * ((j - 1) / 3), 50 + 31 * ((i - 1) / 3), 131 + 31 * ((j - 1) / 3), 81 + 31 * ((i - 1) / 3));
			}
		}
	}
	switch (direction)
	{
	case 1:
		setfillcolor(WHITE);
		solidcircle(110 + 31 * ((x - 2) / 3), 61 + 31 * ((y - 2) / 3), 5);
		solidcircle(122 + 31 * ((x - 2) / 3), 61 + 31 * ((y - 2) / 3), 5);
		setfillcolor(BLACK);
		solidcircle(110 + 31 * ((x - 2) / 3), 61 + 31 * ((y - 2) / 3), 3);
		solidcircle(122 + 31 * ((x - 2) / 3), 61 + 31 * ((y - 2) / 3), 3);
		break;
	case 2:
		setfillcolor(WHITE);
		solidcircle(111 + 31 * ((x - 2) / 3), 60 + 31 * ((y - 2) / 3), 5);
		solidcircle(111 + 31 * ((x - 2) / 3), 72 + 31 * ((y - 2) / 3), 5);
		setfillcolor(BLACK);
		solidcircle(111 + 31 * ((x - 2) / 3), 60 + 31 * ((y - 2) / 3), 3);
		solidcircle(111 + 31 * ((x - 2) / 3), 72 + 31 * ((y - 2) / 3), 3);
		break;
	case 3:
		setfillcolor(WHITE);
		solidcircle(108 + 31 * ((x - 2) / 3), 71 + 31 * ((y - 2) / 3), 5);
		solidcircle(122 + 31 * ((x - 2) / 3), 71 + 31 * ((y - 2) / 3), 5);
		setfillcolor(BLACK);
		solidcircle(108 + 31 * ((x - 2) / 3), 71 + 31 * ((y - 2) / 3), 3);
		solidcircle(122 + 31 * ((x - 2) / 3), 71 + 31 * ((y - 2) / 3), 3);
		break;
	case 4:
		setfillcolor(WHITE);
		solidcircle(121 + 31 * ((x - 2) / 3), 60 + 31 * ((y - 2) / 3), 5);
		solidcircle(121 + 31 * ((x - 2) / 3), 72 + 31 * ((y - 2) / 3), 5);
		setfillcolor(BLACK);
		solidcircle(121 + 31 * ((x - 2) / 3), 60 + 31 * ((y - 2) / 3), 3);
		solidcircle(121 + 31 * ((x - 2) / 3), 72 + 31 * ((y - 2) / 3), 3);
		break;
	}
	if (speed_up)
	{
		setlinecolor(BLUE);
		rectangle(102, 52, 873, 513);
	}
	if (end)
	{
		setlinecolor(RED);
		rectangle(102, 52, 873, 513);
	}
	FlushBatchDraw();
	cleardevice();
}

void Link(int arr[45][75],int direction,int x,int y)
{
	switch (direction)
	{
	case 1:
		if (arr[y + 2][x - 1] == 1)
		{
			arr[y + 1][x - 1] = 1;
			arr[y][x - 1] = 1;
		}
		else
		{
			if (arr[y - 1][x + 2] == 1)
			{
				arr[y - 1][x + 1] = 1;
				arr[y - 1][x] = 1;
			}
			if (arr[y - 1][x - 4] == 1)
			{
				arr[y - 1][x - 3] = 1;
				arr[y - 1][x - 2] = 1;
			}
		}
		break;
	case 2:
		if (arr[y - 1][x + 2] == 1)
		{
			arr[y - 1][x + 1] = 1;
			arr[y - 1][x] = 1;
		}
		else
		{
			if (arr[y + 2][x - 1] == 1)
			{
				arr[y + 1][x - 1] = 1;
				arr[y][x - 1] = 1;
			}
			if (arr[y - 4][x - 1] == 1)
			{
				arr[y - 2][x - 1] = 1;
				arr[y - 3][x - 1] = 1;
			}
		}
		break;
	case 3:
		if (arr[y - 4][x - 1] == 1)
		{
			arr[y - 2][x - 1] = 1;
			arr[y - 3][x - 1] = 1;
		}
		else
		{
			if (arr[y - 1][x + 2] == 1)
			{
				arr[y - 1][x + 1] = 1;
				arr[y - 1][x] = 1;
			}
			if (arr[y - 1][x - 4] == 1)
			{
				arr[y - 1][x - 3] = 1;
				arr[y - 1][x - 2] = 1;
			}
		}
		break;
	case 4:
		if (arr[y - 1][x - 4] == 1)
		{
			arr[y - 1][x - 3] = 1;
			arr[y - 1][x - 2] = 1;
		}
		else 
		{
			if (arr[y + 2][x - 1] == 1)
			{
				arr[y + 1][x - 1] = 1;
				arr[y][x - 1] = 1;
			}
			if (arr[y - 4][x - 1] == 1)
			{
				arr[y - 2][x - 1] = 1;
				arr[y - 3][x - 1] = 1;
			}
		}
		break;
	}
}

void Save(int arr[45][75], int Length,int x,int y)
{
	if (Length > 0)
	{
		arr[y - 1][x - 1] = 2;
		if (arr[y][x - 1] == 1)Save(arr, Length - 1, x, y + 1);
		if (arr[y - 1][x] == 1)Save(arr, Length - 1, x + 1, y);
		if (arr[y - 2][x - 1] == 1)Save(arr, Length - 1, x, y - 1);
		if (arr[y - 1][x - 2] == 1)Save(arr, Length - 1, x - 1, y);
	}
}

void Delete(int arr[45][75])
{
	int i, j;
	for (i = 0;i < 45; i++)
	{
		for (j = 0;j < 75;j++)
		{
			if (arr[i][j] == 1)arr[i][j] = 0;
		}
	}
	for (i = 0;i < 45; i++)
	{
		for (j = 0;j < 75;j++)
		{
			if (arr[i][j] == 2)arr[i][j] = 1;
		}
	}
}

void Generate(int arr[45][75],int thing)
{
	int x,y,success = 0;
	srand((unsigned int)time(NULL));
	while (!success)
	{
		x = rand() % 15;
		y = rand() % 25;
		if (arr[3 * x + 1][3 * y + 1] == 0)
		{
			if (arr[3 * x + 4][3 * y + 1] == 0 && arr[3 * x - 2][3 * y + 1] == 0)
			{
				if (arr[3 * x + 1][3 * y + 4] == 0 && arr[3 * x + 1][3 * y  - 2] == 0)
				{
					switch (thing)
					{
					case FOOD:arr[3 * x + 1][3 * y + 1] = 5;break;
					case WALL:arr[3 * x + 1][3 * y + 1] = 8;break;
					}
					success = 1;
				}
			}
		}
	}
}

int Judge(int arr[45][75],int x,int y,int *length,int *count)
{
	int num = 0,i;
	if (y - 1 >= 45 || y - 1 < 0 || x - 1 >= 75 || x - 1 < 0)return 0;
	if (arr[y - 1][x - 1] == 8)return 0;
	if (arr[y - 1][x - 1] == 5)
	{
		*length = *length + 1;
		*count = *count + 1;
		Generate(arr,FOOD);
	}
	if (arr[y - 1][x - 1] == 1)
	{
		if (arr[y + 2][x - 1] == 1)num++;
		if (arr[y - 1][x + 2] == 1)num++;
		if (arr[y - 4][x - 1] == 1)num++;
		if (arr[y - 1][x - 4] == 1)num++;
		if (num >= 3)return 0;
		else
		{
			for (i = 1;i <= 2;i++)
			{
				arr[y - 1 - i][x - 1] = 0;
				arr[y - 1 + i][x - 1] = 0;
				arr[y - 1][x - 1 - i] = 0;
				arr[y - 1][x - 1 + i] = 0;
			}
		}
	}
	return 1;
}

int Game(int game)
{
	int Length = 3,starttime[4], flashtime[4],i;
	int length = 0, begin = 1, result = 1, start = 1,end = 0;
	int head[2] = { 38 , 23 },direction = 1,aim = 1;
	int dx = 0, dy = -3,SPEED = 500,speed_up = 0;
	int arr[45][75] = { 0 },count = 0;
	TCHAR s_start[6] = _T("按R键开始");
	TCHAR s_end[6] = _T("按R键结束");
	TCHAR s_game[17] = _T("WASD控制移动，空格控制加速");
	ExMessage message;
	for(i = 0;i < 4;i++)starttime[i] = clock();
	Generate(arr,FOOD);
	mciSendString(L"open ./res/Candy_Wind.mp3 alias music", 0, 0, 0);
	if (!game)return 0;
	while (start)
	{
		flashtime[0] = clock() - starttime[0];
		if (flashtime[0] >= FPS)
		{
			Show(arr, head[0], head[1], direction, begin, count, speed_up,end);
			settextstyle(16, 0, _T("宋体"));
			outtextxy(18,70,s_start);
			starttime[0] = clock();
		}
		peekmessage(&message, EX_CHAR);
		if (message.ch == 'r')
		{
			start = 0;
			mciSendString(L"play music from 6000", 0, 0, 0);
		} 
	}
	while (result)
	{
		for (i = 0;i < 4;i++)flashtime[i] = clock() - starttime[i];
		if (flashtime[0] >= FPS)
		{
			Show(arr,head[0],head[1],direction,begin,count,speed_up,end);
			settextstyle(16, 0, _T("宋体"));
			outtextxy(388, 530, s_game);
			starttime[0] = clock();
		}
		if (flashtime[1] >= SPEED)
		{
			if (aim + direction != 4 && aim + direction != 6)direction = aim;
			switch (direction)
			{
			case 1:dx = 0;dy = -3;break;
			case 2:dx = -3;dy = 0;break;
			case 3:dx = 0;dy = 3;break;
			case 4:dx = 3;dy = 0;break;
			}
			head[0] = head[0] + dx;
			head[1] = head[1] + dy;
			result = Judge(arr,head[0],head[1],&Length,&count);
			if (!result)
			{
				head[0] = head[0] - dx;
				head[1] = head[1] - dy;
				end = 1;
				mciSendString(L"close music", 0, 0, 0);
				break;
			}
			arr[head[1] - 1][head[0] - 1] = 1;
			Link(arr, direction, head[0], head[1]);
			length++;
			begin++;
			if (length > Length)
			{
				Save(arr,3 * Length - 2,head[0],head[1]);
				Delete(arr);
				length--;
				if (!speed_up)SPEED = 220;
				else SPEED = 110;
			}
			starttime[1] = clock();
		}
		if (flashtime[2] >= 5000)
		{
			Generate(arr,WALL);
			starttime[2] = clock();
		}
		if (flashtime[3] >= 1000)speed_up = 0;
		peekmessage(&message, EX_CHAR);
		switch (message.ch)
		{
		case 'w':aim = 1;break;
		case 'a':aim = 2;break;
		case 's':aim = 3;break;
		case 'd':aim = 4;break;
		case ' ':speed_up = 1;starttime[3] = clock();break;
		}
	}
	while (end)
	{
		flashtime[0] = clock() - starttime[0];
		if (flashtime[0] >= FPS)
		{
			Show(arr, head[0], head[1], direction, begin, count, speed_up,end);
			settextstyle(16, 0, _T("宋体"));
			outtextxy(18, 70, s_end);
			starttime[0] = clock();
		}
		peekmessage(&message, EX_CHAR);
		if (message.ch == 'r')end = 0;
	}
	return count;
}

int End(int game, int count)
{
	int starttime, flashtime;
	mciSendString(L"close music1", 0, 0, 0);
	mciSendString(L"open ./res/kada.mp3 alias music1", 0, 0, 0);
	TCHAR s0[5] = _T("再来一次");
	TCHAR s1[5] = _T("结束游戏");
	TCHAR s2[4] = _T("得分：");
	TCHAR s3[4];
	_stprintf(s3, _T("%d"), count);
	ExMessage message;
	starttime = clock();
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	while (game)
	{
		flashtime = clock() - starttime;
		if (flashtime >= FPS)
		{
			cleardevice();
			rectangle(390, 400, 590, 450);
			rectangle(390, 500, 590, 550);
			settextstyle(16, 0, _T("宋体"));
			outtextxy(460, 416, s0);
			outtextxy(460, 516, s1);
			settextstyle(32, 0, _T("宋体"));
			outtextxy(435, 220, s2);
			outtextxy(520, 220, s3);
			FlushBatchDraw();
			if (message.x >= 390 && message.x <= 590)
			{
				if (message.y >= 400 && message.y <= 450)
				{
					solidrectangle(390, 400, 590, 450);
					FlushBatchDraw();
					clearrectangle(390, 400, 590, 450);
					if (message.lbutton)
					{
						mciSendString(L"play music1", 0, 0, 0);
						return 1;
					}
				}
				if (message.y >= 500 && message.y <= 550)
				{
					solidrectangle(390, 500, 590, 550);
					FlushBatchDraw();
					clearrectangle(390, 500, 590, 550);
					if (message.lbutton)
					{
						mciSendString(L"play music1", 0, 0, 0);
						Sleep(500);
						return 0;
					}
				}
			}
			starttime = clock();
		}
		peekmessage(&message, EX_MOUSE);
	}
}

int main()
{
	int game,count,result;
	initgraph(981, 600);
	BeginBatchDraw();
	setbkcolor(RGB(192, 192, 192));
	game = Start();
again:
	count = Game(game);
	result = End(game, count);
	if (result)goto again;
	EndBatchDraw();
	closegraph();
	return 0;
}