#define _CRT_SECURE_NO_WARINGS 1
#include<iostream>
using namespace std;
#include "game.h"


void game()
{
	//雷的信息储存
	//cout << "扫雷" << endl;
	// 1、布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	// 2、排查出雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS,'*');
	//打印棋盘
	Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	//布置雷
	setmine(mine,ROW,COL);
	Displayboard(mine, ROW, COL);//布置雷
	//扫雷
	findmine(mine,show,ROW,COL);
}

void menu()
{
	cout << "****************************" << endl;
	cout << "*******   1.play   *********" << endl;
	cout << "*******   0.exit   *********" << endl;
	cout << "****************************" << endl;
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		cout << "请选择：>";
		cin >> input;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			cout << "退出游戏" << endl; break;
		default:
			cout << "选择错误，重新选择！" << endl; break;
		}
	} while (input);
}

int main()
{
	test();



	return 0;
}
