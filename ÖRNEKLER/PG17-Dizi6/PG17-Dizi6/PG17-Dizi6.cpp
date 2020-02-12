// PG17-Dizi6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	srand(time(0));
	int sayilar[10];
	for (int i = 0; i < 10; i++)
		sayilar[i] = 3 + rand() % 7;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(3) << i + 1 << ": ";
		cout << setw(5) << sayilar[i] << ": ";
		for (int j = 0; j <= sayilar[i]; j++)
			cout << "*";
		cout << endl;
	}

	system("PAUSE");
	return 0;
}

