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
	printf("��ʼ������һ�����֣��㽫����3��ȥ���䣬�Ƿ�ʼ��Ϸ������1��ʼ��\n");
	scanf("%d", &start);
	if (1 == start)
	{
		printf("%s\n", number);
		for (time = 3;time > 0;time--)
		{
			Sleep(1000);
		}
		system("cls");
		printf("��������ȷ����\n");
		scanf("%s", answer);
		switch (strcmp(number, answer))
		{
		case 0:printf("��ȷ\n");break;
		default:printf("����\n");break;
		}
	}
	else
	{
		return 0;
	}
	return 0;
}