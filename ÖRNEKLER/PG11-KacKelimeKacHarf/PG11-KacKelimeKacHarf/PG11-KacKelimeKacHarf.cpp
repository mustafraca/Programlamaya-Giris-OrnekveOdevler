// PG11-KacKelimeKacHarf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	char karakter;
	int harf = 0, kelime = 0;
	cout << "Cümle Giriniz: ";
	do
	{
		karakter = _getche();
		if (karakter == ' ') kelime++;
		else harf++;
	} while (karakter != '\r');
	system("CLS");
	cout << harf - 1 << " harf" << endl;
	cout << kelime + 1 << " kelime" << endl;

	system("PAUSE");
    return 0;
}

