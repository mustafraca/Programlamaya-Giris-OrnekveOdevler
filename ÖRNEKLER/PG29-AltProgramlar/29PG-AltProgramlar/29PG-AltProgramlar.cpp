// 29PG-AltProgramlar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int sayi;

//void mesaj() (1)
//{
//	cout << "Merhaba Nas�ls�n�z?" <<endl;
//}

int ustAl()
{
	return sayi*sayi;
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	/*mesaj(); (1)*/
	cout << "Bir Say� Giriniz: "; cin >> sayi;
	cout << "Sonu�: " << ustAl() << endl;

	system("PAUSE");
    return 0;
}

