#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

float calculate(int* p1,int* p2,int* p3)
{
	float answer = (*p1 + *p2 + *p3) / 3.00;
	return answer;
}

int main()
{
	int i = 0;
	int j = 0;
	int arr1[3][3] = { 0 };
	float arr2[3] = { 0 };
	printf("请输入数组a的九个数字:\n");
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("数组a为:\n");
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	for (i = 0;i < 3;i++)
	{
		arr2[i] = calculate(&arr1[i][0], &arr1[i][1], &arr1[i][2]);
	}
	printf("数组b为:\n");
	for (j = 0;j < 3;j++)
	{
		printf("%0.2lf ", arr2[j]);
	}
	return 0;
}