#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void Hanoi_T_S(int n);
void Hanoi_T_M(int n);

void Hanoi_T_S(int n)
{
	if (n == 1)
	{
		printf("��C�����˵Ļ��ƶ���A��\n");
	}
	else
	{
		Hanoi_T_S(n - 1);
		printf("��C�����˵Ļ��ƶ���B��\n");
		Hanoi_T_M(n - 1);
		printf("��B�����˵Ļ��ƶ���A��\n");
		Hanoi_T_S(n - 1);
	}

}

void Hanoi_T_M(int n)
{
	if (n == 1)
	{
		printf("��A�����˵Ļ��ƶ���C��\n");
	}
	else
	{
		Hanoi_T_M(n - 1);
		printf("��A�����˵Ļ��ƶ���B��\n");
		Hanoi_T_S(n - 1);
		printf("��B�����˵Ļ��ƶ���C��\n");
		Hanoi_T_M(n - 1);
	}
}

int main()
{
	int num = 0;
	printf("----��ŵ������---\n");
	printf("�����ҷֱ�ΪA��B��C�������ӣ�������A���ϵĻ���\n");
	scanf("%d", &num);
	Hanoi_T_M(num);
	return 0;
}

