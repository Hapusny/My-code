#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int start = 0;
	int time = 0;
	char number[12] = "18379212253";
	char answer[12] = { 0 };
	printf("开始后会出现一串数字，你将会有3秒去记忆，是否开始游戏（输入1开始）\n");
	scanf("%d", &start);
	if (1 == start)
	{
		printf("%s\n", number);
		for (time = 3;time > 0;time--)
		{
			Sleep(1000);
		}
		system("cls");
		printf("请输入正确数字\n");
		scanf("%s", answer);
		switch (strcmp(number, answer))
		{
		case 0:printf("正确\n");break;
		default:printf("错误\n");break;
		}
	}
	else
	{
		return 0;
	}
	return 0;
}