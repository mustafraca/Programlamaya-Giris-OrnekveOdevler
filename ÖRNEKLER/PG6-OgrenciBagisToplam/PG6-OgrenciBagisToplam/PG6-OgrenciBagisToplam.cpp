// PG6-OgrenciBagisToplam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int os;
	cout << "S�n�ftaki ��renci Say�s�: ";
	cin >> os;
	int kasa = 0;
	int bagis;

	for (int i = 1; i <= os; i++)
	{
		cout << i << ". ��renci Ba����: ";
		cin >> bagis;
		kasa += bagis;
	}
	cout << "Toplam Ba���: " << kasa << endl;

	system("PAUSE");
	return 0;
}

