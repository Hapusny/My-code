#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void calculate(char* arr)
{
	int i = 0;
	char a = *arr;
	char b = *(arr + 1);
	if (b != '\0')
	{
		while (b != '\0')
		{
			if (a < b)
			{
				char store = 0;
				store = *arr;
				*arr = *(arr + 1 + i);
				*(arr + 1 + i) = store;
			}
			i++;
			a = *arr;
			b = *(arr + 1 + i);
		}
		calculate(arr + 1);
	}
}

int main()
{
	char arr[21]={ 0 };
	printf("请输入你要排序的数组（上限为20个数字）\n");
	scanf("%s",arr);
	calculate(arr);
	printf("\n按从大到小的顺序排列后的结果为\n%s\n", arr);
	return 0;
}