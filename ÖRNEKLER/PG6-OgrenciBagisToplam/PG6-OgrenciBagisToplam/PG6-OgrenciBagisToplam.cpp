// PG6-OgrenciBagisToplam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int os;
	cout << "Sýnýftaki Öðrenci Sayýsý: ";
	cin >> os;
	int kasa = 0;
	int bagis;

	for (int i = 1; i <= os; i++)
	{
		cout << i << ". Öðrenci Baðýþý: ";
		cin >> bagis;
		kasa += bagis;
	}
	cout << "Toplam Baðýþ: " << kasa << endl;

	system("PAUSE");
	return 0;
}

