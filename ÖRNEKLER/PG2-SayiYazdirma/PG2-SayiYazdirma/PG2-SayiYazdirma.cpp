// PG2-SayiYazdirma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;
	cout << "0-9 aras�nda bir say� giriniz: ";
	cin >> sayi;
	switch (sayi)
	{
	case 0:cout << "S�f�r" << endl; break;
	case 1:cout << "Bir" << endl; break;
	case 2:cout << "�ki" << endl; break;
	case 3:cout << "��" << endl; break;
	case 4:cout << "D�rt" << endl; break;
	case 5:cout << "Be�" << endl; break;
	case 6:cout << "Alt�" << endl; break;
	case 7:cout << "Yedi" << endl; break;
	case 8:cout << "Sekiz" << endl; break;
	case 9:cout << "Dokuz" << endl; break;
	}

	system("PAUSE");
	return 0;
}

