
#include"8.20 game1.h"

int main()
{
	char Pieces[ROW][COL] = { '  ','  ', '  ', '  ', '  ', '  ', '  ', '  ', '  ' };
	int choice1 = 0;
	int choice2 = 0;
	int check = 0;
	int end = 0;
	screen1();
	printf("请选择：");
	scanf("%d", &choice1);
	Sleep(1500);
	system("cls");
	if (1 == choice1)
	{
		board(Pieces, ROW, COL);
		while (0 == end)
		{
			do
			{
				printf("\n请输入你要下的位置\n(位置与小键盘上的1-9相对应)\n");
				scanf("%d", &choice2);
				check = place_p(Pieces, choice2);
			} while (0 == check);
			board(Pieces, ROW, COL);
			printf("\n");
			Sleep(1500);
			system("cls");
			end = judge_p(Pieces);
			if (end != 0)
			{
				break;
			}
			end = judge(Pieces);
			if (end != 0)
			{
				break;
			}
			place_c(Pieces);
			board(Pieces, ROW, COL);
			printf("\n");
			end = judge_c(Pieces);
		}
		switch (end)
		{
		case 1:printf("恭喜你，取得胜利\n");break;
		case 2:printf("很遗憾，没能获胜\n");break;
		case 3:printf("你们没能决出胜负\n");break;
		}
	}
	return 0;
}