#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	char love1[37] = "lovelovelovelovelovelovelovelovelove";
	char love2[37] = "lovelovelovelovelovelovelovelovelove";
	int i = 0;
	for (i = 0;i < 6;i++)
	{
		love1[i] = ' ';
	}
	for (i = 35;i >= 30;i--)
	{
		love1[i] = ' ';
	}
	for (i = 12;i <= 23; i++)
	{
		love1[i] = ' ';
	}
	printf("%s\n", love1);
	for (i = 0;i < 6;i++)
	{
		love1[5 - i] = love2[5 - i];
		love1[23 - i] = love2[23 - i];
		love1[12 + i] = love2[12 + i];
		love1[30 + i] = love2[30 + i];
		if (i >= 3)
		{
			printf("%s\n", love1);
		}
	}
	for (i = 0;i < 18;i+=2)
	{
		love1[i] = ' ';
		love1[i + 1] = ' ';
		love1[35 - i] = ' ';
		love1[34 - i] = ' ';
		printf("%s\n", love1);
	}
	return 0;
}