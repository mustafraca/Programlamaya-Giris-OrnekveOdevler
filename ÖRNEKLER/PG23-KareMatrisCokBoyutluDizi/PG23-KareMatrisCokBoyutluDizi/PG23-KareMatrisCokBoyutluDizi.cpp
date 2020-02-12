// PG23-KareMatrisCokBoyutluDizi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Turkish");

	int sayilar[6][6];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			sayilar[i][j] = 3 + rand() % 7;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << setw(2) << sayilar[i][j];
		cout << endl;
	}
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if (i == (5 - j)) sayilar[i][j] = 1;
	for (int i = 0; i < 6; i++)
	{
		sayilar[5][i] = 1;
		sayilar[i][5] = 1;
	}
	cout << "----------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << setw(2) << sayilar[i][j];
		cout << endl;
	}

	system("PAUSE");
	return 0;
}

