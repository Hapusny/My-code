
#include<stdio.h>

int calculate(int a, int b, int c)
{
	int d = (a * a * a) + (b * b * b) +( c * c * c);
	return d;
}

int main()
{
	int num = 0;
	printf("����λ�ϵ��������η����Ϊ�䱾�����λ����:\n");
	for (num = 100;num < 1000;num++)
	{
		int num1 = num / 100;
		int num1p = num % 100;
		int num2 = num1p / 10;
		int num3 = num1p % 10;
		if (calculate(num1,num2,num3) == num)
		{
			printf("%d\n", num);
		}
	}
	return 0;
}