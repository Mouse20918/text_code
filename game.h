#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define Row 3
#define Col 3

//初始化函数
void initBoard(char board[Row][Col], int row, int col);

//打印函数
void displayBoard(char board[Row][Col], int row, int col);

//玩家移动
void playerMove(char board[Row][Col], int row, int col);

//电脑移动
void computerMove(char board[Row][Col], int row, int col);

//判断输赢
char isWin(char board[Row][Col], int row, int col);

//判断平局
int isFull(char board[Row][Col], int row, int col);




//int while_x = 0;
//while (while_x < row)
//{
//	for (i = 0; i < row; i++)
//	{
//		if ((board[i][while_x] != ' ' && board[i][1] == board[i][1] && (board[i][1] == '*' || board[i][1] == '#')))
//		{
//			count_x++;
//			if (count_x == row)
//				return board[i][1];  //判断x轴是否相等
//		}
//	}
//	while_x++;
//}



//int while_y = 0;
//while (while_y < col)
//{
//	for (j = 0; j < col; j++)
//	{
//		if ((board[while_y][j] != ' ' && board[1][j] == board[1][j] && (board[1][j] == '*' || board[1][j] == '#')))
//		{
//			count_y++;
//			if (count_y == col)
//				return board[1][j];  //判断y轴是否相等
//		}
//	}
//	while_y++;
//}