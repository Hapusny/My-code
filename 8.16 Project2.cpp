#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Frog_J(int n)
{
	int answer = 0;
	if (1 == n)
	{
		answer = 1;
	}
	else if (2 == n)
	{
		answer = 2;
	}
	else
	{
		answer = Frog_J(n - 1) + Frog_J(n - 2);
	}
	return answer;
}

int main()
{
	int num = 0;
	printf("---������̨������---\n");
	printf("��������̨����Ŀ\n");
	scanf("%d", &num);
	int answer = Frog_J(num);
	printf("�������������ĿΪ%d��", answer);
	return 0;
}