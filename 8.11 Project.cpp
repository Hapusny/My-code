#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int time = 2;
	char choice[4] = { 0 };
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	printf("Are you ready?(Yes or No)");
	Sleep(1000);
	system("cls");
	scanf("%s", choice);
	if (strcmp(choice,"Yes") == 0)
	{
		system("cls");
		for (time = 3; time > 0; time--)
		{
			printf("%d",time);
			Sleep(1000);
			system("cls");
		}
		printf("����������Ҫ����ĸ\n");
		scanf("%s", arr1);
		system("cls");
		printf("�����ղ��������ĸ\n");
		scanf("%s", arr2);
		if (strcmp(arr1, arr2) == 0)
		{
			printf("�ɹ�");
		}
		else
		{
			printf("ʧ��");
		}
	}
	else
	{
		printf("\n�ǲ����治��");
	}
	return 0;
}