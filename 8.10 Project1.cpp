#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int answer[4] = { 0 };
	int arr[4] = { 0 };
	int i = 0;
	int x = 0;
	int a = 0;
	int b = 0;
	printf("请预设答案（4个数字间用空格隔开）\n");
	scanf("%d%d%d%d", &answer[0], &answer[1], &answer[2], &answer[3]);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	do
	{
		printf("请输入你猜测的答案（4个数字间用空格隔开）\n");
		scanf("%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3]);
		for (i = 0; i <= 3; i++)
		{
			if (arr[i] == answer[0] || arr[i] == answer[1] || arr[i] == answer[2] || arr[i] == answer[3])
			{
				a++;
			}
		}
		for (i = 0; i <= 3; i++)
		{
			if (arr[i] == answer[i])
			{
				b++;
			}
		}
		printf("正确的数字有%d个\n正确且位置相同的数字有%d个\n", a, b);
		switch (b)
		{
		case 4:
			printf("正确\n\n\n");
			break;
		default:
			printf("错误\n\n\n");
			a = 0;
			b = 0;
			break;
		}
		x++;
	} 
	while (b != 4);
	printf("共尝试%d次\n", x);
	return 0;
}