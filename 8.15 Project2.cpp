#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void calculate(int num)
{
	static int n = 0;
	static int answer = 0;
	if (answer < num)
	{
		answer = answer * 10 + 9;
		printf("%d ", answer);
		n++;
		calculate(num);
	}
	else
	{
		printf("\n9����Ŀ�ܹ�Ϊ%d��", (n*(n+1))/2);
	}
}

int main()
{
	printf("������һ������\n");
	int num = 0;
	scanf("%d", &num);
	calculate(num);
	return 0;
}