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
	printf("��Ԥ��𰸣�4�����ּ��ÿո������\n");
	scanf("%d%d%d%d", &answer[0], &answer[1], &answer[2], &answer[3]);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	do
	{
		printf("��������²�Ĵ𰸣�4�����ּ��ÿո������\n");
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
		printf("��ȷ��������%d��\n��ȷ��λ����ͬ��������%d��\n", a, b);
		switch (b)
		{
		case 4:
			printf("��ȷ\n\n\n");
			break;
		default:
			printf("����\n\n\n");
			a = 0;
			b = 0;
			break;
		}
		x++;
	} 
	while (b != 4);
	printf("������%d��\n", x);
	return 0;
}