// PG5-Faktoriyel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;
	cout << "Sayý: ";
	cin >> sayi;
	int toplam = 1;
	for (int i = 1; i <= sayi; i++)
	{
		toplam *= i;
	}
	cout << "Sonuç: " << toplam << endl;

	system("PAUSE");
	return 0;
}

