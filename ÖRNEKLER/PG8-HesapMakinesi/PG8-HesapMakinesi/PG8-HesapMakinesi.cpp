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
		cout << "1- Toplama \n2- ��karma \n3- �arpma \n4- B�lme\n";
		cout << "H-h ��k��" << endl;
		cout << "Se�iminiz: ";
		cin >> secim;
		system("CLS");
		if (secim == '1' || secim == '2' || secim == '3' || secim == '4')
		{
			cout << "Birinci Say�: "; cin >> s1;
			cout << "�kinci Say�: "; cin >> s2;
		}
		switch (secim)
		{
		case '1':cout << "Toplam�: " << s1 + s2 << endl; break;
		case '2':cout << "Fark�: " << s1 - s2 << endl; break;
		case '3':cout << "�arp�m�: " << s1 * s2 << endl; break;
		case '4':cout << "B�l�m�: " << s1 / s2 << endl; break;
		case 'h':
		case 'H': break;
		default: cout << "Hatal� se�im yapt�n�z. Tekrar deneyiniz.."; break;
		}
		if (!(secim == 'h' || secim == 'H'))
		{
			cout << "Devam etmek i�in bir tu�a bas�n�z...";
			_getch();
		}
	} while (!(secim == 'h' || secim == 'H'));

	system("PAUSE");
    return 0;
}

