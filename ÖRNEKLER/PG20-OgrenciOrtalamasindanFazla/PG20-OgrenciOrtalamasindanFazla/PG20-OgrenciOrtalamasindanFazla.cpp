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
	cout << "��renci Say�s�: ";
	cin >> os;
	cout << endl;
	for (int i = 0; i < os; i++)
	{
		cout << i + 1 << ". ��rencinin ismi: ";
		cin >> isim[i];
		cout << i + 1 << ". ��rencinin ya��: ";
		cin >> yas[i];
	}
	int toplam = 0;
	for (int i = 0; i < os; i++)toplam += yas[i];
	double ortalama = toplam / os;
	cout << "Ya� Ortalamas�: " << ortalama << endl;
	for (int i = 0; i < os; i++)
	{
		if (yas[i] > ortalama)
		{
			cout << "�smi: " << isim[i] << " ya�: " << yas[i] << endl;
		}
	}

	system("PAUSE");
	return 0;
}

