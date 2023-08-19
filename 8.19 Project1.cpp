#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void change(int* p)
{
	if (0 == *p)
	{
		*p = 1;
	}
	else
	{
		*p = 0;
	}
}

int main()
{
	int choice = 0;
	int p[9] = { 0 };
	int i = 0;
	int j = 0;
select:
	for (i = 0;i < 3; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	for (i = 3;i < 6; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	for (i = 6;i < 9; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	printf("请输入你要翻转的方格\n(方格对应的位置为小数字键的1-9)\n");
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:
		change(&p[3]);
		change(&p[6]);
		change(&p[7]);
		break;
	case 2:
		change(&p[4]);
		change(&p[6]);
		change(&p[7]);
		change(&p[8]);
		break;
	case 3:
		change(&p[7]);
		change(&p[8]);
		change(&p[5]);
		break;
	case 4:
		change(&p[0]);
		change(&p[6]);
		change(&p[3]);
		change(&p[4]);
		break;
	case 5:
		change(&p[3]);
		change(&p[4]);
		change(&p[1]);
		change(&p[5]);
		change(&p[7]);
		break;
	case 6:
		change(&p[2]);
		change(&p[4]);
		change(&p[5]);
		change(&p[8]);
		break;
	case 7:
		change(&p[0]);
		change(&p[1]);
		change(&p[3]);
		break;
	case 8:
		change(&p[0]);
		change(&p[1]);
		change(&p[2]);
		change(&p[4]);
		break;
	case 9:
		change(&p[1]);
		change(&p[2]);
		change(&p[5]);
		break;
	}
	for (i = 1;i <= 9; i++)
	{
		if (0 == p[i])
		{
			Sleep(2000);
			system("cls");
			goto select;
		}
	}
	Sleep(2000);
	system("cls");
	for (i = 0;i < 3; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	for (i = 3;i < 6; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	for (i = 6;i < 9; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	printf("恭喜你成功翻转了所有方格\n");
	return 0;
}
