#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void Hanoi_T_S(int n);
void Hanoi_T_M(int n);

void Hanoi_T_S(int n)
{
	if (n == 1)
	{
		printf("将C柱顶端的环移动到A环\n");
	}
	else
	{
		Hanoi_T_S(n - 1);
		printf("将C柱顶端的环移动到B环\n");
		Hanoi_T_M(n - 1);
		printf("将B柱顶端的环移动到A环\n");
		Hanoi_T_S(n - 1);
	}

}

void Hanoi_T_M(int n)
{
	if (n == 1)
	{
		printf("将A柱顶端的环移动到C环\n");
	}
	else
	{
		Hanoi_T_M(n - 1);
		printf("将A柱顶端的环移动到B环\n");
		Hanoi_T_S(n - 1);
		printf("将B柱顶端的环移动到C环\n");
		Hanoi_T_M(n - 1);
	}
}

int main()
{
	int num = 0;
	printf("----汉诺塔问题---\n");
	printf("从左到右分别为A，B，C三跟柱子，请输入A柱上的环数\n");
	scanf("%d", &num);
	Hanoi_T_M(num);
	return 0;
}

