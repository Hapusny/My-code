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
	printf("��������Ҫ��������飨����Ϊ20�����֣�\n");
	scanf("%s",arr);
	calculate(arr);
	printf("\n���Ӵ�С��˳�����к�Ľ��Ϊ\n%s\n", arr);
	return 0;
}