#define _CRT_SECURE_NO_WARINGS 1
#include<iostream>
using namespace std;
#include "game.h"


void game()
{
	//�׵���Ϣ����
	//cout << "ɨ��" << endl;
	// 1�����úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	// 2���Ų���׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS,'*');
	//��ӡ����
	Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);
	//������
	setmine(mine,ROW,COL);
	Displayboard(mine, ROW, COL);//������
	//ɨ��
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
		cout << "��ѡ��>";
		cin >> input;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			cout << "�˳���Ϸ" << endl; break;
		default:
			cout << "ѡ���������ѡ��" << endl; break;
		}
	} while (input);
}

int main()
{
	test();



	return 0;
}
