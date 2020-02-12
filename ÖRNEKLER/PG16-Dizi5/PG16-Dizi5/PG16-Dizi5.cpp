// PG16-Dizi5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayilar[5];
	for (int K = 0; K < 5; K++)
	{
		sayilar[K] = 3 + rand() % 8;
	}
	system("CLS");
	for (int i = 0; i < 5; i++)
	{
		cout << setw(4) << i + 1;
		cout << setw(4) << sayilar[i];
		cout << "     ";
		for (int j = 0; j <= sayilar[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}

