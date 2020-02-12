// PG2-SayiYazdirma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;
	cout << "0-9 arasýnda bir sayý giriniz: ";
	cin >> sayi;
	switch (sayi)
	{
	case 0:cout << "Sýfýr" << endl; break;
	case 1:cout << "Bir" << endl; break;
	case 2:cout << "Ýki" << endl; break;
	case 3:cout << "Üç" << endl; break;
	case 4:cout << "Dört" << endl; break;
	case 5:cout << "Beþ" << endl; break;
	case 6:cout << "Altý" << endl; break;
	case 7:cout << "Yedi" << endl; break;
	case 8:cout << "Sekiz" << endl; break;
	case 9:cout << "Dokuz" << endl; break;
	}

	system("PAUSE");
	return 0;
}

