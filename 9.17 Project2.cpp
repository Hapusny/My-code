#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int calculate(char* arr)
{
	if (*arr != '\0')
	{
		if (*arr >= 48 && *arr <= 57)
		{
			return 100 + calculate(arr + 1);
		}
		else if (*arr >= 65 && *arr <= 90)
		{
			return 10000 + calculate(arr + 1);
		}
		else if (*arr >= 97 && *arr <= 122)
		{
			return 1000000 + calculate(arr + 1);
		}
		else
		{
			return 1 + calculate(arr + 1);
		}
	}
	return 0;
}

int main()
{
	int answer = 0;
	int x1, x2, x3, x4;
	char arr[21] = { 0 };
	printf("请输入要分检的字符串(共20个字符,即与*对齐)\n********************\n");
	scanf("%s", arr);
	answer = calculate(arr);
	x1 = answer % 100;
	x2 = answer / 100 % 100;
	x3 = answer / 10000 % 100;
	x4 = answer / 1000000;
	printf("字符数目为%02d\n数字数目为%02d\n大写字母数目为%02d\n小写字母数目为%02d\n", x1, x2, x3, x4);
	return 0;
}