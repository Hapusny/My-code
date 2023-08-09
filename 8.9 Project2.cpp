#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int calculate(int a, int x)
{
	int i = 0;
	int d = 0;
	while (i < x)
	{
		int c = 2;
		static int b = 1;
		b++;
		d = a + b - c;
		i++;
	}
	return d;
}

int main()
{
	int num = 0;
	int time = 0;
	int min = 0;
	printf("请输入初始值及运算次数\n");
	scanf("%d%d", &num, &time);
	int answer = calculate(num, time);
	printf("结果为%d\n", answer);
	answer < time ? min = answer : min = time;
	printf("运算结果与运算次数间的较小值为%d\n",min );
	printf("且运算结果的字节大小为%d", sizeof(answer));
	return 0;
}