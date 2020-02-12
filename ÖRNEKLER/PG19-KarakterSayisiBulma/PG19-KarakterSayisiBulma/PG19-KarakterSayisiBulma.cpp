// PG19-KarakterSayisiBulma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	char ad[10];
	cout << "Adýnýz: ";
	cin >> ad;
	cout << "Adýnýz: " << ad << endl;
	int uzunluk = 0;
	for (; ad[uzunluk] != '\0';) uzunluk++;
	cout << "Uzunluk: " << uzunluk << endl;

	system("PAUSE");
	return 0;
}

