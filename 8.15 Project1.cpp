#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"8.15 module1.h"

#pragma comment (lib,"8.15 project1.lib")

int main()
{
	int n = 0;
	int answer = 0;
	printf("----쳲���������----\n");
	printf("����������Ҫ�������\n");
	scanf("%d", &n);
	answer = Fib_seq(n);
	printf("쳲��������еĵ�%d��Ϊ%d", n, answer);
	return 0;
}