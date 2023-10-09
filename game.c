#include "game.h"

//初始化函数
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

//打印函数
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

//玩家移动
void playerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走: \n");
	while (1)
	{
		printf("输入坐标 ->");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("坐标输入错误，重新输入！\n");
			
		}
	}
}

//电脑移动
void computerMove(char board[Row][Col], int row, int col)
{
	
	printf("电脑移动：\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//判断占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断平局
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

//判断输赢
char isWin(char board[Row][Col], int row, int col)
{
	int i = 0;  //X轴
	int j = 0;  //Y轴
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
	//			return board[i][while_x];  //判断x轴是否相等
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
	//			return board[while_y][j];  //判断y轴是否相等
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
	//					return board[i][j]; //判断坐标(0.0)到(row.col)是否相等
	//			}
	//		}
	//	}

		//	if(board[i][col-i] != ' '&& board[i][col-i] == board[row][0])
		//	{
		//		count_xY++; //(0.col)到(row.0)等于board[row][0]次数
		//		if (count_xY == col)
		//			return board[i][col-i]; //判断坐标(0.col)到(row.0)是否相等
		//	}
		//}


		//死程序
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
	
	//判断平局
		//如果棋盘满了返回1，不满返回0
	int ret = isFull(board, row, col);
	if (ret == 1)
		return '!';
	else
	{
		return 'J';
	}
}




