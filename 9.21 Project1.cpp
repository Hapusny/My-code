#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	int ch = 0;
	char scan[100001] = { 0 };
	while (ch != '\n')
	{
		ch = getchar();
		scan[i] = ch;
		if (i > 0 && scan[i] == scan[i - 1])
		{
			i--;
		}
		else
		{
			i++;
		}
	}
	for (i = 0;scan[i] != '\0';i++)
	{
		if (scan[i] == '\n')
		{
			scan[i] = '\0';
		}
	}
	printf("%s", scan);
	return 0;
}