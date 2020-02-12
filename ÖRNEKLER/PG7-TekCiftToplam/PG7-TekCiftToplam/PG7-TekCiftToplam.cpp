// PG7-TekCiftToplam.cpp : Defines the entry point for the console application.
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
	int tektoplam = 0;
	int cifttoplam = 0;

	for (int i = 0; i <= sayi; i++)
	{
		if (i % 2 == 0) cifttoplam += i;
		else tektoplam += i;
	}
	cout << "Çift Toplam: " << cifttoplam << endl;
	cout << "Tek Toplam: " << tektoplam << endl;

	system("PAUSE");
	return 0;
}

