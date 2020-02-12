// PG13-Dizi2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int yaslar[4];
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << ". öðrencinin yaþý: " << endl;
		cin >> yaslar[i];
	}
	int toplam = 0;
	for (int i = 0; i < 4; i++)
	{
		toplam += yaslar[i];
	}
	cout << "Ortalama: " << 1.0*toplam / 4 << endl;

	system("PAUSE");
    return 0;
}

