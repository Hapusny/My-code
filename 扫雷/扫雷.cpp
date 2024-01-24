#define _CRT_SECURE_NO_WARNINGS

#include <easyx.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

void hidewindow()
{
	HWND hwnd = GetForegroundWindow();
	if (hwnd)ShowWindow(hwnd, SW_HIDE);
}

void addmine(int num, int arr[11][11])
{
	int i, j;
	int place, judge;
	int arr_place[10] = { 0 };
	srand((unsigned int)time(NULL));
	place = rand() % 10 * 10 + rand() % 10;
	arr_place[0] = place;
	for (i = 0;i < num;)
	{
		place = rand() % 9 * 10 + rand() % 9;
		judge = 1;
		for (j = 0;j < i;j++)
		{
			if (place == arr_place[j])judge = 0;
		}
		if (judge)
		{
			arr_place[j] = place;
			i++;
		}
	}
	for (i = 0;i < num;i++)
	{
		arr[arr_place[i] / 10 + 1][arr_place[i] % 10 + 1] = 1;
	}
}

int Start()
{
	int game = 1;
	int starttime = 0;
	int flashtime;
	IMAGE mine;
	loadimage(&mine, _T("./res/mine_sweeping.png"), 200, 200);
	TCHAR s0[5] = _T("开始游戏");
	TCHAR s1[5] = _T("结束游戏");
	TCHAR s2[3] = _T("扫雷");
	ExMessage message;
	float fps = 1000 / 30.0f;
	starttime = clock();
	setfillcolor(WHITE);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	while (game)
	{
		flashtime = clock() - starttime;
		if (flashtime >= fps)
		{
			putimage(300,100 , &mine);
			rectangle(300, 400, 500, 450);
			rectangle(300, 500, 500, 550);
			settextstyle(16, 0, _T("黑体"));
			outtextxy(370, 416, s0);
			outtextxy(370, 516, s1);
			settextstyle(32, 0, _T("黑体"));
			outtextxy(362, 310, s2);
			FlushBatchDraw();
			cleardevice();
			if (message.x >= 300 && message.x <= 500)
			{
				putimage(300, 100, &mine);
				rectangle(300, 400, 500, 450);
				rectangle(300, 500, 500, 550);
				settextstyle(16, 0, _T("黑体"));
				outtextxy(370, 416, s0);
				outtextxy(370, 516, s1);
				settextstyle(32, 0, _T("黑体"));
				outtextxy(362, 310, s2);
				if (message.y >= 400 && message.y <= 450)
				{
					solidrectangle(300, 400, 500, 450);
					FlushBatchDraw();
					clearrectangle(300, 400, 500, 450);
					if (message.lbutton)return 1;
				}
				if (message.y >= 500 && message.y <= 550)
				{
					solidrectangle(300, 500, 500, 550);
					FlushBatchDraw();
					clearrectangle(300, 500, 500, 550);
					if (message.lbutton)return 0;
				}
			}
			starttime = clock();
		}
		peekmessage(&message, EX_MOUSE);
	}
}

void Show(int arr[11][11])
{
	int i, j;
	IMAGE flag1, flag2,mine1,mine2;
	loadimage(&flag1, _T("./res/flag1.png"), 58, 58);
	loadimage(&flag2, _T("./res/flag2.png"), 58, 58);
	loadimage(&mine1, _T("./res/mine1.png"), 58, 58);
	loadimage(&mine2, _T("./res/mine2.png"), 58, 58);
	for (i = 1;i < 10;i++)
	{
		for (j = 1;j < 10;j++)
		{
			switch (arr[i][j])
			{
			case 9:
				setfillcolor(RGB(165,235,185));
				solidrectangle(132 + 60 * (i - 1), 32 + 60 * (j - 1), 188 + 60 * (i - 1), 88 + 60 * (j - 1));
				break;
			case 10:
				putimage(132 + 60 * (i - 1), 32 + 60 * (j - 1), &flag1, SRCAND);
				putimage(132 + 60 * (i - 1), 32 + 60 * (j - 1), &flag2, SRCPAINT);
				break;
			case 11:
				putimage(132 + 60 * (i - 1), 32 + 60 * (j - 1), &mine1, SRCAND);
				putimage(132 + 60 * (i - 1), 32 + 60 * (j - 1), &mine2, SRCPAINT);
				break;
			default:
				TCHAR s[2];
				settextstyle(34, 0, _T("黑体"));
				_stprintf(s, _T("%d"), arr[i][j]);
				outtextxy(152 + 60 * (i - 1), 46 + 60 * (j - 1), s);
				break;
			}
		}
	}
}

void search(int arr_in[11][11],int arr_out[11][11],int x,int y)
{
	int i,j,sum;
	if (arr_in[x][y] == 1)arr_out[x][y] = 11;
	else
	{
		sum = 0;
		for (i = -1;i <= 1;i++)
		{
			for (j = -1;j <= 1;j++)
			{
				sum = sum + arr_in[x + i][y + j];
			}
		}
		arr_out[x][y] = sum;
	}
	if (arr_out[x][y] == 0)
	{
		for (i = -1;i <= 1;i++)
		{
			for (j = -1;j <= 1;j++)
			{
				if ((x + i <= 9 && x + i >= 1)&&(y + j <= 9 && y + j >= 1))
				{
					if (arr_out[x + i][y + j] == 9)search(arr_in, arr_out, x + i, y + j);
				}
			}
		}
	}
}

int Judge(int arr_in[11][11], int arr_out[11][11])
{
	int i, j, count = 0;
	for (i = 1;i < 10;i++)
	{
		for (j = 1;j < 10;j++)
		{
			if (arr_out[i][j] == 11)return 0;
			if (arr_out[i][j] == 10 || arr_out[i][j] == 9) count++;
		}
	}
	if (count == 10)return 1;
	return 2;
}

void End_1(int arr_in[11][11], int arr_out[11][11])
{
	int i, j,game = 1;
	int flashtime, starttime;
	IMAGE flag1, flag2, mine1, mine2;
	loadimage(&flag1, _T("./res/flag1.png"), 58, 58);
	loadimage(&flag2, _T("./res/flag2.png"), 58, 58);
	loadimage(&mine1, _T("./res/mine1.png"), 58, 58);
	loadimage(&mine2, _T("./res/mine2.png"), 58, 58);
	float fps = 1000 / 30.0f;
	ExMessage message;
	starttime = clock();
	while (game)
	{
		flashtime = clock() - starttime;
		if (flashtime >= fps)
		{
			rectangle(130, 30, 670, 570);
			for (i = 0;i < 8;i++)
			{
				line(190 + 60 * i, 30, 190 + 60 * i, 570);
				line(130, 90 + 60 * i, 670, 90 + 60 * i);
			}
			Show(arr_out);
			for (i = 1;i < 10;i++)
			{
				for (j = 1;j < 10;j++)
				{
					if (arr_in[i][j] == 1)
					{
						putimage(132 + 60 * (i - 1), 32 + 60 * (j - 1), &mine1, SRCAND);
						putimage(132 + 60 * (i - 1), 32 + 60 * (j - 1), &mine2, SRCPAINT);
					}
					if (arr_out[i][j] == 10)
					{
						putimage(132 + 60 * (i - 1), 32 + 60 * (j - 1), &flag1, SRCAND);
						putimage(132 + 60 * (i - 1), 32 + 60 * (j - 1), &flag2, SRCPAINT);
					}
				}
			}
			FlushBatchDraw();
			cleardevice();
			if (message.message == WM_LBUTTONDOWN)game = 0;
			starttime = clock();
		}
		peekmessage(&message, EX_MOUSE);
	}
}

int Game(int game)
{
	int result = 2, i, j;
	int x, y;
	ExMessage message;
	float fps = 1000 / 10.0f;
	int starttime, flashtime;
	int arr_in[11][11] = { 0 };
	int arr_out[11][11] = { 0 };
	setbkcolor(RGB(185, 235, 185));
	setlinecolor(WHITE);
	cleardevice();
	addmine(10, arr_in);
	starttime = clock();
	for (i = 0;i < 11;i++)
	{
		for (j = 0;j < 11;j++)
		{
			arr_out[i][j] = 9;
		}
	}
	while (game)
	{
		flashtime = clock() - starttime;
		if (flashtime >= fps)
		{
			rectangle(130, 30, 670, 570);
			for (i = 0;i < 8;i++)
			{
				line(190 + 60 * i, 30, 190 + 60 * i, 570);
				line(130, 90 + 60 * i, 670, 90 + 60 * i);
			}
			Show(arr_out);
			if (message.x > 130 && message.x < 670)
			{
				if (message.y > 30 && message.y < 570)
				{
					x = (message.x - 130) / 60 + 1;
					y = (message.y - 30) / 60 + 1;
					if (arr_out[x][y] == 9)
					{
						setfillcolor(RGB(100, 235, 185));
						solidrectangle(132 + 60 * (x - 1), 32 + 60 * (y - 1), 188 + 60 * (x - 1), 88 + 60 * (y - 1));
					}
					if (message.message == WM_LBUTTONDOWN)
						if(arr_out[x][y] == 9)search(arr_in, arr_out, x, y);
					if (message.message == WM_RBUTTONDOWN)
					{
						if(arr_out[x][y] == 9)arr_out[x][y] = 10;
						else if(arr_out[x][y] == 10)arr_out[x][y] = 9;
					}
 				}
			}
			FlushBatchDraw();
			cleardevice();
			result = Judge(arr_in, arr_out);
			if (result != 2)
			{
				End_1(arr_in,arr_out);
				break;
			}
			starttime = clock();
		}
		peekmessage(&message, EX_MOUSE);
	}
	return result;
}

int End_2(int game, int result)
{
	if (game)
	{
		int starttime = 0;
		int flashtime;
		TCHAR s0[5] = _T("再来一次");
		TCHAR s1[5] = _T("结束游戏");
		TCHAR s2[5] = _T("扫雷成功");
		TCHAR s3[5] = _T("扫雷失败");
		ExMessage message;
		float fps = 1000 / 30.0f;
		starttime = clock();
		setfillcolor(WHITE);
		while (game)
		{
			flashtime = clock() - starttime;
			if (flashtime >= fps)
			{
				rectangle(300, 400, 500, 450);
				rectangle(300, 500, 500, 550);
				settextstyle(16, 0, _T("黑体"));
				outtextxy(370, 416, s0);
				outtextxy(370, 516, s1);
				settextstyle(32, 0, _T("黑体"));
				if(result)outtextxy(340, 220, s2);
				else outtextxy(340, 220, s3);
				FlushBatchDraw();
				cleardevice();
				if (message.x >= 300 && message.x <= 500)
				{
					rectangle(300, 400, 500, 450);
					rectangle(300, 500, 500, 550);
					settextstyle(16, 0, _T("黑体"));
					outtextxy(370, 416, s0);
					outtextxy(370, 516, s1);
					settextstyle(32, 0, _T("黑体"));
					if (result)outtextxy(340, 220, s2);
					else outtextxy(340, 220, s3);
					if (message.y >= 400 && message.y <= 450)
					{
						solidrectangle(300, 400, 500, 450);
						FlushBatchDraw();
						clearrectangle(300, 400, 500, 450);
						if (message.lbutton)return 1;
					}
					if (message.y >= 500 && message.y <= 550)
					{
						solidrectangle(300, 500, 500, 550);
						FlushBatchDraw();
						clearrectangle(300, 500, 500, 550);
						if (message.lbutton)return 0;
					}
				}
				starttime = clock();
			}
			peekmessage(&message, EX_MOUSE);
		}
	}
	return 0;
}

int main()
{
	int result, game, end = 0;
	hidewindow();
	initgraph(800, 600);
	BeginBatchDraw();
	setbkcolor(RGB(185, 235, 185));
	cleardevice();
	game = Start();
again:
	result = Game(game);
	end = End_2(game, result);
	if (end)goto again;
	EndBatchDraw();
	closegraph();
	return 0;
}