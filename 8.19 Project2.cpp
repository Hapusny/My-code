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
	printf("����������a�ľŸ�����:\n");
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	printf("����aΪ:\n");
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
	printf("����bΪ:\n");
	for (j = 0;j < 3;j++)
	{
		printf("%0.2lf ", arr2[j]);
	}
	return 0;
}