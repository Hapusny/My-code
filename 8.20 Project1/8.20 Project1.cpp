
#include"8.20 game1.h"

int main()
{
	char Pieces[ROW][COL] = { '  ','  ', '  ', '  ', '  ', '  ', '  ', '  ', '  ' };
	int choice1 = 0;
	int choice2 = 0;
	int check = 0;
	int end = 0;
	screen1();
	printf("��ѡ��");
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
				printf("\n��������Ҫ�µ�λ��\n(λ����С�����ϵ�1-9���Ӧ)\n");
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
		case 1:printf("��ϲ�㣬ȡ��ʤ��\n");break;
		case 2:printf("���ź���û�ܻ�ʤ\n");break;
		case 3:printf("����û�ܾ���ʤ��\n");break;
		}
	}
	return 0;
}