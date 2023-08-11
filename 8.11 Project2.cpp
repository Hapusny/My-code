#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int time = 2;
	char choice[4] = { 0 };
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	printf("Are you ready?(Yes or No)");
	Sleep(1000);
	system("cls");
	scanf("%s", choice);
	if (strcmp(choice,"Yes") == 0)
	{
		system("cls");
		for (time = 3; time > 0; time--)
		{
			printf("%d",time);
			Sleep(1000);
			system("cls");
		}
		printf("请输入你想要的字母\n");
		scanf("%s", arr1);
		system("cls");
		printf("输出你刚才输入的字母\n");
		scanf("%s", arr2);
		if (strcmp(arr1, arr2) == 0)
		{
			printf("成功");
		}
		else
		{
			printf("失败");
		}
	}
	else
	{
		printf("\n是不是玩不起");
	}
	return 0;
}
