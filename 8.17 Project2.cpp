#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int max(int num1, int num2)
{
	int num3 = num1 % num2;
	int num4 = 0;
	while (num3 != 0)
	{
		num4 = num2 % num3;
		num2 = num3;
		num3 = num4;
	}
	return num2;
}

int min(int num1, int num2)
{
	int num3 = max(num1, num2);
	num3 = (num1 * num2) / num3;
	return num3;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("��������Ҫ�����Լ������С����������������\n");
	scanf("%d%d", &num1, &num2);
	int answer1 = max(num1, num2);
	int answer2 = min(num1, num2);
	printf("���Լ��Ϊ%d\n", answer1);
	printf("��С������Ϊ%d\n", answer2);
	return 0;
}

