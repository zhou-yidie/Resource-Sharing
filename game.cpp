#define _CRT_SECURE_NO_WARINGS 1
#include"game.h"
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>

void Initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			board[i][j] = set;
		}
	}

}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <= row; i++)
	{
		cout << i << ' ';
	}
	cout << endl;
	for (int i = 1; i <= row; i++)
	{
		cout << i << ' ';
		for (int j = 1; j <= col; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;
	while (win < row * col -EASY_COUNT)
	{
		cout << "�������Ų��׵����꣺>";
		cin >> x >> y;
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				cout << "���ź����㱻ը����" << endl;
				Displayboard(mine, row, col);
				break;
			}
			else
			{
				// ����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				Displayboard(show, row, col);
				win++;
			}
		}
		else
		{
			cout << "��������Ƿ������������룡" << endl;
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		cout << "��ϲ�㣬���׳ɹ���" << endl;
		Displayboard(mine, row, col);

	}
}