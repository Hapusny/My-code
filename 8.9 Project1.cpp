#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char arr1[11] = { 0 };
	char arr2[11] = {"0000000000"};
	char max = 0;
	int i = -1;
	int x = 0;
	int choice = 0;
	printf("请输入要筛选出数字的字符（不超过10个）\n");
	scanf("%s", arr1);
	while (i <= 9)
	{
		i++;
		if (arr1[i] < '0' || arr1[i]>'9')
		{
			continue;
		}
		printf("%c", arr1[i]);
		arr2[i] = arr1[i];
	}
	printf("\n是否要得出其中最大的数字（是则输入1，反之输入0）\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1 :
		max = arr2[0];
		while (x <= 9)
		{
			x++;
			if (max < arr2[x])
			{
				max = arr2[x];
			}
		}
		printf("其中最大的数字为%c\n", max);
		break;
	default :
		printf("结束\n");
	}
	return 0;
}