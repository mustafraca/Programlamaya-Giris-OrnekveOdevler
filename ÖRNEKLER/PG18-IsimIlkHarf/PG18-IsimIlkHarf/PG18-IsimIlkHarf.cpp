// PG18-IsimIlkHarf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	char ad[10];
	cout << "Ad�n�z: ";
	cin >> ad;
	int uzunluk = 0;
	for (; ad[uzunluk] != '\0';) uzunluk++;
	if (ad[0] == 'a')
	{
		cout << "Ad�n�z: " << ad << endl;
		cout << "Uzunluk: " << uzunluk << endl;
	}
	system("PAUSE");
	return 0;
}

