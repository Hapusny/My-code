#define _CRT_SECURE_NO_WARNINGS 1

#define SPEED 10

#include <easyx.h>
#include <time.h>
#include <Windows.h>

void hidewindow()
{
	HWND hwnd = GetForegroundWindow();
	if (hwnd)ShowWindow(hwnd, SW_HIDE);
}

int Start()
{
	int game = 1;
	int starttime = 0;
	int flashtime;
	TCHAR s0[5] = _T("开始游戏");
	TCHAR s1[5] = _T("结束游戏");
	TCHAR s2[6] = _T("弹球小游戏");
	ExMessage message;
	float fps = 1000 / 60.0;
	starttime = clock();
	setfillcolor(WHITE);
	while (game)
	{
		flashtime = clock() - starttime;
		if (flashtime >= fps)
		{
			rectangle(300, 400, 500, 450);
			rectangle(300, 500, 500, 550);
			solidcircle(300, 200, 50);
			solidrectangle(260, 250, 550, 280);
			settextstyle(16, 0, _T("黑体"));
			outtextxy(370, 416, s0);
			outtextxy(370, 516, s1);
			settextstyle(32, 0, _T("黑体"));
			outtextxy(336, 220, s2);
			FlushBatchDraw();
			cleardevice();
			if (message.x >= 300 && message.x <= 500)
			{
				rectangle(300, 400, 500, 450);
				rectangle(300, 500, 500, 550);
				solidcircle(300, 200, 50);
				solidrectangle(260, 250, 550, 280);
				settextstyle(16, 0, _T("黑体"));
				outtextxy(370, 416, s0);
				outtextxy(370, 516, s1);
				settextstyle(32, 0, _T("黑体"));
				outtextxy(336, 220, s2);
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

int Game(int game)
{
	int x = 400, y = 0;
	int count = 0;
	int LENGTH = 300;
	int dx = SPEED, dy = SPEED;
	int starttime = 0;
	int flashtime;
	int ad = (800 - LENGTH) / 2;
	TCHAR s[5];
	TCHAR s0[5] = _T("得分：");
	ExMessage message;
	float fps = 1000 / 60.0;
	starttime = clock();
	setfillcolor(WHITE);
	settextstyle(16, 0, _T("黑体"));
	while (game)
	{
		flashtime = clock() - starttime;
		if (flashtime >= fps)
		{
			solidcircle(x, y, 50);
			solidrectangle(ad, 590, ad + LENGTH, 600);
			_stprintf(s, _T("%d"), count);
			outtextxy(725, 14, s0);
			outtextxy(765, 14, s);
			FlushBatchDraw();
			cleardevice();
			if (x + 50 >= 800) dx = -SPEED;
			if (x - 50 <= 0) dx = SPEED;
			if (y + 50 >= 600)
			{
				if (x >= ad && x <= (ad + LENGTH))
				{
					dy = -SPEED;
					count++;
					LENGTH = LENGTH - 5;
				}
				else
				{
					return count;
				}
			}
			if (y - 50 <= 0) dy = SPEED;
			x = x + dx;
			y = y + dy;
			starttime = clock();
		}
		peekmessage(&message, EX_MOUSE);
		if (message.x >= (LENGTH / 2) && message.x <= 800 - (LENGTH / 2))
		{
			ad = message.x - (LENGTH / 2);
		}
	}
}

int End(int game, int count)
{
	if (game)
	{
		int game = 1;
		int starttime = 0;
		int flashtime;
		TCHAR s0[5] = _T("再来一次");
		TCHAR s1[5] = _T("结束游戏");
		TCHAR s2[5] = _T("得分为：");
		TCHAR s3[5];
		ExMessage message;
		float fps = 1000 / 60.0;
		starttime = clock();
		setfillcolor(WHITE);
		while (game)
		{
			flashtime = clock() - starttime;
			if (flashtime >= fps)
			{
				rectangle(300, 400, 500, 450);
				rectangle(300, 500, 500, 550);
				_stprintf(s3, _T("%d"), count);
				settextstyle(16, 0, _T("黑体"));
				outtextxy(370, 416, s0);
				outtextxy(370, 516, s1);
				settextstyle(32, 0, _T("黑体"));
				outtextxy(330, 220, s2);
				outtextxy(450, 220, s3);
				FlushBatchDraw();
				cleardevice();
				if (message.x >= 300 && message.x <= 500)
				{
					rectangle(300, 400, 500, 450);
					rectangle(300, 500, 500, 550);
					_stprintf(s3, _T("%d"), count);
					settextstyle(16, 0, _T("黑体"));
					outtextxy(370, 416, s0);
					outtextxy(370, 516, s1);
					settextstyle(32, 0, _T("黑体"));
					outtextxy(330, 220, s2);
					outtextxy(450, 220, s3);
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
	int count, game, end = 0;
	hidewindow();
	initgraph(800, 600);
	BeginBatchDraw();
	setbkcolor(RGB(185, 235, 185));
	cleardevice();
	game = Start();
again:
	count = Game(game);
	end = End(game, count);
	if (end)goto again;
	EndBatchDraw();
	closegraph();
	return 0;
}