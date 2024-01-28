#define _CRT_SECURE_NO_WARNINGS 

#define SIZE_BIRD 80
#define FPS (1000 / 20.0f)
#define PI 3.1415

#include <easyx.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#pragma comment(lib,"winmm.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int Show_BK(IMAGE BK, int number, int end)
{
	putimage(-10 * number, 0, &BK);
	if (end)
	{
		setlinecolor(RED);
		setlinestyle(PS_SOLID, 8);
		rectangle(0, 0,999, 599);
		setlinestyle(PS_SOLID, 1);
	}
	if (number < 100) return number + 1;
	else return 0;
}

int Start(IMAGE BK)
{
	int starttime, flashtime,number = 0;
	IMAGE snake;
	loadimage(&snake, _T("./res/flappy_bird.jpg"), 200, 200);
	mciSendString(L"open ./res/kada.mp3 alias music1", 0, 0, 0);
	TCHAR s0[5] = _T("开始游戏");
	TCHAR s1[5] = _T("结束游戏");
	TCHAR s2[5] = _T("笨鸟先飞");
	ExMessage message;
	starttime = clock();
	setbkmode(TRANSPARENT);
	while (TRUE)
	{
		flashtime = clock() - starttime;
		if (flashtime >= FPS)
		{
			cleardevice();
			number = Show_BK(BK, number, 0);
			putimage(390, 100, &snake);
			rectangle(390, 400, 590, 450);
			rectangle(390, 500, 590, 550);
			settextcolor(RGB(0, 162, 234));
			settextstyle(16, 0, _T("宋体"));
			outtextxy(460, 416, s0);
			outtextxy(460, 516, s1);
			settextcolor(WHITE);
			settextstyle(32, 0, _T("宋体"));
			outtextxy(427, 310, s2);
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

void LOAD(IMAGE bird[9][2], IMAGE pipe[2][2],IMAGE *BK)
{
	loadimage(&bird[0][0], _T("./res/bird(1).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[0][1], _T("./res/bird(1).2.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[1][0], _T("./res/bird(2).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[1][1], _T("./res/bird(2).2.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[2][0], _T("./res/bird(3).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[2][1], _T("./res/bird(3).2.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[3][0], _T("./res/bird(4).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[3][1], _T("./res/bird(4).2.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[4][0], _T("./res/bird(5).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[4][1], _T("./res/bird(5).2.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[5][0], _T("./res/bird(6).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[5][1], _T("./res/bird(6).2.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[6][0], _T("./res/bird(7).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[6][1], _T("./res/bird(7).2.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[7][0], _T("./res/bird(8).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[7][1], _T("./res/bird(8).2.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[8][0], _T("./res/bird(9).1.png"), SIZE_BIRD, SIZE_BIRD);
	loadimage(&bird[8][1], _T("./res/bird(9).2.png"), SIZE_BIRD, SIZE_BIRD);

	loadimage(&pipe[0][0], _T("./res/pipe_up.1.png"), 300, 600);
	loadimage(&pipe[0][1], _T("./res/pipe_up.2.png"), 300, 600);
	loadimage(&pipe[1][0], _T("./res/pipe_down.1.png"), 300, 600);
	loadimage(&pipe[1][1], _T("./res/pipe_down.2.png"), 300, 600);

	loadimage(BK, _T("./res/bk.png"), 2000, 600);
}

void Show_Pipe(int arr[60][100],IMAGE pipe[2][2])
{
	int i, j;
	for (i = 0;i < 60;i ++)
	{
		for (j = 0;j < 100;j ++)
		{
			if (arr[i][j] == 1)
			{
				putimage(-150 + 10 * j,-3 + 10 * i, &pipe[0][1], SRCAND);
				putimage(-150 + 10 * j, -3 + 10 * i, &pipe[0][0], SRCPAINT);
			}
			if (arr[i][j] == 2)
			{
				putimage(- 150 + 10 * j, - 593 + 10 * i, &pipe[1][1], SRCAND);
				putimage(-150 + 10 * j, - 593 + 10 * i, &pipe[1][0], SRCPAINT);
			}
		}
	}
}

int Show_Bird(IMAGE bird[9][2], int number, int place[2])
{
	putimage(- 40 + 10 * place[0], -40 + 10 * place[1], &bird[number][1], SRCAND);
	putimage(- 40 + 10 * place[0], -40 + 10 * place[1], &bird[number][0], SRCPAINT);
	FlushBatchDraw();
	cleardevice();
	if (number < 8) return number + 1;
	else return 0;
}

void Move(int arr[60][100])
{
	int i, j;
	for (i = 0;i < 60;i++)
	{
		for (j = 0;j < 100;j++)
		{
			if (arr[i][j] == 1 || arr[i][j] == 2)
			{
				if (j - 1 > 0)arr[i][j - 1] = arr[i][j];
				arr[i][j] = 0;
			}
		}
	}
}

void Generate(int arr[60][100])
{
	int y1, y2, success = 0;
	srand((unsigned int)time(NULL));
	while (!success)
	{
		y1 = rand() % 60;
		y2 = rand() % 60;
		if (y1 - y2 >= 14)
		{
			arr[y1][99] = 1;
			arr[y2][99] = 2;
			success = 1;
		}
	}
}

int Judge(int arr[60][100], int place[2], int* count)
{
	int i, j, fail = 0;
	for (i = place[0] - 3;i <= place[0] + 3;i++)
	{
		if (i >= 0 && i< 100)
		{
			for (j = 0;j <= place[1];j++)if (arr[j][i] == 1)fail = 1;
			for (j = 59;j >= place[1];j--)if (arr[j][i] == 2)fail = 1;
			for (j = place[1] - 2;j <= place[1] +2;j++)
			{
				if (j >= 0 && j < 60)
					if (arr[j][i] != 0)fail = 1;
			}
		}
	} 
	if (fail)return 0;
	for (i = 0;i < 60;i++)if (arr[i][place[0] - 4] == 1)*count = *count + 1;
	return 1;
}

int Game(int game,IMAGE BK,IMAGE bird[9][2],IMAGE pipe[2][2])
{
	int starttime[3], flashtime[3], i;
	int result = 1, start = 1,end = 0;
	int place[2] = { 49 , 29 };
	int down = 1, dy = 1, SPEED = 2000;
	int arr[60][100] = { 0 }, count = 0, number[2] = { 0 };
	TCHAR s_start[6] = _T("按R键开始");
	TCHAR s_end[6] = _T("按R键结束");
	TCHAR s_game[17] = _T("空格控制振翅");
	TCHAR s1[4] = _T("得分：");
	TCHAR s2[3];
	_stprintf(s2, _T("%d"), count);
	ExMessage message;
	for (i = 0;i < 3;i++)starttime[i] = clock();
	mciSendString(L"open ./res/Lonely_Dance.mp3 alias music", 0, 0, 0);
	if (!game)return 0;
	while (start)
	{
		flashtime[0] = clock() - starttime[0];
		if (flashtime[0] >= FPS)
		{
			number[0] = Show_BK(BK, number[0],end);
			Show_Pipe(arr, pipe);
			settextstyle(16, 0, _T("宋体"));
			outtextxy(18, 70, s_start);
			number[1] = Show_Bird(bird, number[1], place);
			starttime[0] = clock();
		}
		peekmessage(&message, EX_CHAR);
		if (message.ch == 'r')
		{
			start = 0;
			mciSendString(L"play music from 9000", 0, 0, 0);
		}
	}
	while (result)
	{
		for (i = 0;i < 3;i++)flashtime[i] = clock() - starttime[i];
		if (flashtime[1] >= SPEED)
		{ 
			Generate(arr);
			if(SPEED > 1000)SPEED = SPEED - 40;
			starttime[1] = clock();
		}
		if (flashtime[2] >= 200)
		{
			if (down) dy = dy + 2;
			else
			{
				dy = 1;
				down = 1;
			}
			if (place[1] + dy < 60)
				place[1] = place[1] + dy;
			else place[1] = 59;
			starttime[2] = clock();
		}
		if (flashtime[0] >= FPS)
		{
			if (place[0] > 20) place[0]--;
			if (message.ch == ' ')
			{
				message.ch = 's';
				if (place[1] - 7 >= 0)
					place[1] = place[1] - 7;
				else place[1] = 0;
				down = 0;
			}
			number[0] = Show_BK(BK, number[0], end);
			Move(arr);
			Show_Pipe(arr, pipe);
			settextstyle(16, 0, _T("宋体"));
			outtextxy(418, 530, s_game);
			outtextxy(890, 70, s1);
			outtextxy(940, 70, s2);
			number[1] = Show_Bird(bird, number[1], place);
			result = Judge(arr, place, &count);
			if (!result)
			{
				end = 1;
				mciSendString(L"close music", 0, 0, 0);
			}
			_stprintf(s2, _T("%d"), count);
			starttime[0] = clock();
		}
		peekmessage(&message, EX_CHAR);
	}
	while (end)
	{
		flashtime[0] = clock() - starttime[0];
		if (flashtime[0] >= FPS)
		{
			number[0] = Show_BK(BK, number[0], end);
			Show_Pipe(arr, pipe);
			settextstyle(16, 0, _T("宋体"));
			outtextxy(18, 70, s_end);
			number[1] = Show_Bird(bird, number[1], place);
			starttime[0] = clock();
		}
		peekmessage(&message, EX_CHAR);
		if (message.ch == 'r')end = 0;
	}
	return count;
}

int End(int game, int count,IMAGE BK)
{
	int starttime, flashtime,number = 0;
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
			number = Show_BK(BK, number, 0);
			rectangle(390, 400, 590, 450);
			rectangle(390, 500, 590, 550);
			settextcolor(RGB(0, 162, 234));
			settextstyle(16, 0, _T("宋体"));
			outtextxy(460, 416, s0);
			outtextxy(460, 516, s1);
			settextcolor(WHITE);
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
	return 0;
}

int main()
{
	int game, count, result;
	IMAGE bird[9][2];
	IMAGE pipe[2][2];
	IMAGE BK;
	LOAD(bird, pipe, &BK);
	initgraph(1000, 600);
	BeginBatchDraw();
	setbkcolor(RGB(192, 192, 192));
	game = Start(BK);
again:
	count = Game(game,BK,bird,pipe);
	result = End(game, count,BK);
	if (result)goto again;
	EndBatchDraw();
	closegraph();
	return 0;
}