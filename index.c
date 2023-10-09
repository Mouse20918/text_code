
#include "game.h"
void menu()
{
	printf("***********************************\n");
	printf("*********     1��play     *********\n");
	printf("*********     0��exit     *********\n");
	printf("***********************************\n");
}

void game()
{
	//�洢���� - ��ά����
	char board[Row][Col];
	//��ʼ������ - ��ʼ���ո�
	initBoard(board, Row, Col);
	//��ӡ���� - �����Ǵ�ӡ���������
	displayBoard(board, Row, Col);
	char ret = 0;  //��Ϸ״̬
	while (1)
	{
		//����ƶ�
		playerMove(board, Row, Col);
		printf("\n");
		displayBoard(board, Row, Col);
		//�ж��Ƿ�Ӯ��
		ret = isWin(board, Row, Col);
		if (ret != 'J')
			break;
		//�����ƶ�
		computerMove(board, Row, Col);
		printf("\n");
		displayBoard(board, Row, Col);
		ret = isWin(board, Row, Col);
		if (ret != 'J')
			break;
	}
	switch (ret)
	{
	case '*':
		printf("���Ӯ�ˣ�����\n\n");
		break;
	case '#':
		printf("����Ӯ�ˣ�����\n\n");
		break;
	default:
		printf("ƽ��\n");
		break;
	}
	printf("��Ϸ����\n");
	displayBoard(board, Row, Col);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��˵���->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}