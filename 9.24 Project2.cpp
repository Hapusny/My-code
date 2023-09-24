#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0;
	int i = 0,j = 0,k = 0;
	int arr[9][9] = {0};
	printf("请输入幻方的阶数(仅限奇数且最大为9)\n");
	scanf("%d", &num);
	arr[num - 1][num / 2] = 1;
	for (i = 2;i <= num * num;i++)
	{
		for (j = 0;j < num;j++)
		{
			for (k = 0;k < num;k++)
			{
				if (arr[j][k] == i - 1)
				{
					if (arr[(j + 1) % num][(k + 1) % num] == 0)
					{
						arr[(j + 1) % num][(k + 1) % num] = i;
					}
					else
					{
						arr[j - 1][k] = i;
					}
				}
			}
		}
	}
	system("cls");
	printf("生成的幻方为\n");
	for (j = 0;j < num;j++)
	{
		for (k = 0;k < num;k++)
		{
			printf("%02d ", arr[j][k]);
		}
		printf("\n");
	}
	return 0;
}