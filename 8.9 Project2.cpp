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
	printf("�������ʼֵ���������\n");
	scanf("%d%d", &num, &time);
	int answer = calculate(num, time);
	printf("���Ϊ%d\n", answer);
	answer < time ? min = answer : min = time;
	printf("�����������������Ľ�СֵΪ%d\n",min );
	printf("�����������ֽڴ�СΪ%d", sizeof(answer));
	return 0;
}