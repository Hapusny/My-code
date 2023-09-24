#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void screen1()
{
	printf("-----------------------------------------------------------\n");
	printf("---                         Ëõ¼õ                        ---\n");
	printf("---                       (1.play)                      ---\n");
	printf("---                       (2.exit)                      ---\n");
	printf("-----------------------------------------------------------\n");
}

int judge(char* arr1, char* arr2)
{
	int i = 0,j = 0;
	for (i = 0;i < 19;i++)
	{
		if (*(arr1 + i) == '\0')
		{
			break;
		}
	}
	for (j = 0;j < 15;j++)
	{
		if (*(arr2 + j) == '\0')
		{
			break;
		}
	}
	if (i > j)
	{
		return 0;
	}
	return i;
}

int cut(char* arr,int length)
{
	int num = rand() % 3;
	if ((length - num) < 0)
	{
		return 0;
	}
	*(arr + length - num) = '\0';
	return 1;
}

int main()
{
	srand((unsigned int)time(NULL));
	int length = 1;
	int choice = 0;
	int i = 0;
	int end = 1;
	char start[16] = "###############";
	char scan[100] = { 0 };
	screen1();
	printf("ÇëÊäÈëÄãµÄÑ¡Ôñ\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		while (length != 0&&end != 0)
		{
			system("cls");
			printf("%s\n", start);
			Sleep(2000 - i * 50);
			system("cls");
			printf("ÇëÊäÈë×Ö·û´®(ÄÚÈÝÔªËØÎª1,Èç1111)\n");
			scanf("%s", scan);
			length = judge(scan, start);
			end = cut(start, length);
			i += 2;
		}
		printf("ÓÎÏ·½áÊø£¬×Ö·û´®¹²Ëõ¼õ%d´Î", i - 2);
	}
	return 0;
}