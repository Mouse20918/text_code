#include "game.h"

//��ʼ������
void initBoard(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0; i < row; i++)
	{
		for (j=0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void displayBoard(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j=0;j<col;j++)
		{
			printf(" %c ",board[i][j]);
			if (j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if(i<col-1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}		
	}
}

//����ƶ�
void playerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����: \n");
	while (1)
	{
		printf("�������� ->");
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�����Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("������������������룡\n");
			
		}
	}
}

//�����ƶ�
void computerMove(char board[Row][Col], int row, int col)
{
	
	printf("�����ƶ���\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//�ж�ռ��
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж�ƽ��
int isFull(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//�ж���Ӯ
char isWin(char board[Row][Col], int row, int col)
{
	int i = 0;  //X��
	int j = 0;  //Y��
	int count_Xy = 0;
	int count_xY = 0;

	//int while_x = 0;
	//while (while_x < row)
	//{
	//	int count_x = 0;
	//	for (i = 0; i < row; i++)
	//	{
	//		if ((board[i][while_x] != ' ' && board[i][1] == board[i][1] && (board[i][1] == '*' || board[i][1] == '#')))
	//		{
	//			count_x++;
	//		}
	//		if (count_x >= row)
	//			return board[i][while_x];  //�ж�x���Ƿ����
	//	}
	//	while_x++;
	//}

	//int while_y = 0;
	//while (while_y < col)
	//{
	//	int count_y = 0;
	//	for (j = 0; j < col; j++)
	//	{
	//		if ((board[while_y][j] != ' ' && board[1][j] == board[1][j] && (board[1][j] == '*' || board[1][j] == '#')))
	//		{
	//			count_y++;		
	//		}
	//		if (count_y >= col)
	//			return board[while_y][j];  //�ж�y���Ƿ����
	//	}
	//	while_y++;
	//}


	//for (i = 0; i < row; i++)
	//{
	//	for (j = 0; j < col; j++)
	//	{
	//		if (i == j)
	//		{
	//			if (board[i][j] != ' ' && board[i][j] == board[0][0])
	//			{
	//				count_Xy++;
	//				if (count_Xy == col)
	//					return board[i][j]; //�ж�����(0.0)��(row.col)�Ƿ����
	//			}
	//		}
	//	}

		//	if(board[i][col-i] != ' '&& board[i][col-i] == board[row][0])
		//	{
		//		count_xY++; //(0.col)��(row.0)����board[row][0]����
		//		if (count_xY == col)
		//			return board[i][col-i]; //�ж�����(0.col)��(row.0)�Ƿ����
		//	}
		//}


		//������
	for (i = 0; i < row; i++)
	{
		if (board[i][1] != ' ' && board[i][1] == board[i][0] && board[i][2] == board[i][0])
			return board[i][1];
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j])
			return board[0][j];
	}

	if (board[0][2] != ' ' && board[1][1] == board[0][2] && board[2][0] == board[1][1])
		return board[1][1];
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[1][1];
	
	//�ж�ƽ��
		//����������˷���1����������0
	int ret = isFull(board, row, col);
	if (ret == 1)
		return '!';
	else
	{
		return 'J';
	}
}




