
#include "game.h"
void menu()
{
	printf("***********************************\n");
	printf("*********     1、play     *********\n");
	printf("*********     0、exit     *********\n");
	printf("***********************************\n");
}

void game()
{
	//存储数据 - 二维数组
	char board[Row][Col];
	//初始化棋盘 - 初始化空格
	initBoard(board, Row, Col);
	//打印棋盘 - 本质是打印数组的内容
	displayBoard(board, Row, Col);
	char ret = 0;  //游戏状态
	while (1)
	{
		//玩家移动
		playerMove(board, Row, Col);
		printf("\n");
		displayBoard(board, Row, Col);
		//判断是否赢了
		ret = isWin(board, Row, Col);
		if (ret != 'J')
			break;
		//电脑移动
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
		printf("玩家赢了！！！\n\n");
		break;
	case '#':
		printf("电脑赢了！！！\n\n");
		break;
	default:
		printf("平局\n");
		break;
	}
	printf("游戏结束\n");
	displayBoard(board, Row, Col);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择菜单：->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("重新选择\n");
			break;
		}
	} while (input);
	return 0;
}