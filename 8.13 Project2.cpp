#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>

void Switch(int* pA, int* pB)
{
	int pC = *pA;
	*pA = *pB;
	*pB = pC;
}

void test(int x, int y, int z)
{
	int m = 0;
	int num = 0;
	for (m = 2;m <=x -1;m++)
	{
		if (x % m ==0)
		{
			goto second;
		}
	}
	printf("a为素数%d\n", x);
	num++;
second:
	m = 0;
	for (m = 2;m <= y - 1;m++)
	{
		if (y % m ==0)
		{
			goto third;
		}
	}
	printf("b为素数%d\n", y);
	num++;
third:
	m = 0;
	for (m = 2;m <= z -1;m++)
	{
		if (z % m ==0)
		{
			goto end;
		}
	}
	printf("c为素数%d\n", z);
	num++;
end:
	printf("素数共有的个数为%d", num);
}

int main()
{
	srand((unsigned int)time(NULL));
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int a, b, c;
	int i = 0;
	printf("请输入三个数字（中间用空格隔开）\n");
	scanf("%d%d%d", &num1, &num2, &num3);
	system("cls");
	for (i = 0;i < 3;i++)
	{
		int n = rand() % 3;
		switch (n)
		{
		case 0:Switch(&num1, &num2);printf("%d %d %d", num1, num2, num3);break;
		case 1:Switch(&num2, &num3);printf("%d %d %d", num1, num2, num3);break;
		case 2:Switch(&num1, &num3);printf("%d %d %d", num1, num2, num3);break;
		}
		Sleep(2000);
		system("cls");
	}
	printf("请输入交换后的数字（用空格隔开）\n");
	scanf("%d%d%d", &a, &b, &c);
	if (a == num1 && b == num2 && c == num3)
	{
		printf("恭喜你，回答正确\n");
	}
	else
	{
		printf("回答错误\n");
	}
	test(a, b, c);
	return 0;
}