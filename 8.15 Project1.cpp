#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"8.15 module1.h"

#pragma comment (lib,"8.15 project1.lib")

int main()
{
	int n = 0;
	int answer = 0;
	printf("----斐波那契数列----\n");
	printf("请输入你所要求的项数\n");
	scanf("%d", &n);
	answer = Fib_seq(n);
	printf("斐波那契数列的第%d项为%d", n, answer);
	return 0;
}