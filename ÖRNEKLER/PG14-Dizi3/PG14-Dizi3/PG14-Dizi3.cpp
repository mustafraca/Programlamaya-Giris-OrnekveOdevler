// PG14-Dizi3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayilar[5] = { 1,6,2,9,17 };
	for (int i = 0; i < 5; i++)
	{
		cout << setw(4) << i + 1;
		cout << setw(4) << sayilar[i];
		cout << "     ";
		for (int j = 1; j <= sayilar[i]; j++)
			cout << "*";
		cout << endl;
	}

	system("PAUSE");
    return 0;
}

