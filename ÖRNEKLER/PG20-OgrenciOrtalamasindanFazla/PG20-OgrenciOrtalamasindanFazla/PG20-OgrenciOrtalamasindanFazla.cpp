// PG20-OgrenciOrtalamasindanFazla.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	string isim[100];
	int yas[100];
	int os;
	cout << "Öðrenci Sayýsý: ";
	cin >> os;
	cout << endl;
	for (int i = 0; i < os; i++)
	{
		cout << i + 1 << ". öðrencinin ismi: ";
		cin >> isim[i];
		cout << i + 1 << ". öðrencinin yaþý: ";
		cin >> yas[i];
	}
	int toplam = 0;
	for (int i = 0; i < os; i++)toplam += yas[i];
	double ortalama = toplam / os;
	cout << "Yaþ Ortalamasý: " << ortalama << endl;
	for (int i = 0; i < os; i++)
	{
		if (yas[i] > ortalama)
		{
			cout << "Ýsmi: " << isim[i] << " yaþ: " << yas[i] << endl;
		}
	}

	system("PAUSE");
	return 0;
}

