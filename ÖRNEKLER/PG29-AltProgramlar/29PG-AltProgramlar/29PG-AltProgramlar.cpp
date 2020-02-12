// 29PG-AltProgramlar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int sayi;

//void mesaj() (1)
//{
//	cout << "Merhaba Nasýlsýnýz?" <<endl;
//}

int ustAl()
{
	return sayi*sayi;
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	/*mesaj(); (1)*/
	cout << "Bir Sayý Giriniz: "; cin >> sayi;
	cout << "Sonuç: " << ustAl() << endl;

	system("PAUSE");
    return 0;
}

