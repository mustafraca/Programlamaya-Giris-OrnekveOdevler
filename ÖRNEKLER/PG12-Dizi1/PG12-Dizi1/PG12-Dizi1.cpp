// PG12-Dizi1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayilar[5] = { -1,6,2,-9,17 };
	for (int i = 0; i < 5; i++)
	{
		cout << sayilar[i] << endl;
	}
	system("PAUSE");
    return 0;
}

