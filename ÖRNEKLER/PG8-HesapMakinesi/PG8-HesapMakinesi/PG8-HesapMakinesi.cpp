// PG8-HesapMakinesi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int s1, s2;
	char secim;
	do
	{
		system("CLS");
		cout << "1- Toplama \n2- Çýkarma \n3- Çarpma \n4- Bölme\n";
		cout << "H-h Çýkýþ" << endl;
		cout << "Seçiminiz: ";
		cin >> secim;
		system("CLS");
		if (secim == '1' || secim == '2' || secim == '3' || secim == '4')
		{
			cout << "Birinci Sayý: "; cin >> s1;
			cout << "Ýkinci Sayý: "; cin >> s2;
		}
		switch (secim)
		{
		case '1':cout << "Toplamý: " << s1 + s2 << endl; break;
		case '2':cout << "Farký: " << s1 - s2 << endl; break;
		case '3':cout << "Çarpýmý: " << s1 * s2 << endl; break;
		case '4':cout << "Bölümü: " << s1 / s2 << endl; break;
		case 'h':
		case 'H': break;
		default: cout << "Hatalý seçim yaptýnýz. Tekrar deneyiniz.."; break;
		}
		if (!(secim == 'h' || secim == 'H'))
		{
			cout << "Devam etmek için bir tuþa basýnýz...";
			_getch();
		}
	} while (!(secim == 'h' || secim == 'H'));

	system("PAUSE");
    return 0;
}

