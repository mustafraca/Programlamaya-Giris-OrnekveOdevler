// PG3-OnHaneliSayiYazdirma.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi;
	cout << "0-99 arasýnda bir sayý giriniz: ";
	cin >> sayi;
	if (sayi == 0) cout << "Sýfýr";
	else if (sayi < 0 || sayi> 99) cout << "Aralýk Dýþýnda! ";
	else {
		int birler, onlar;
		onlar = sayi / 10;
		birler = sayi % 10;
		if (onlar == 1)cout << "On ";
		else if (onlar == 2)cout << "Yirmi ";
		else if (onlar == 3)cout << "Otuz ";
		else if (onlar == 4)cout << "Kýrk ";
		else if (onlar == 5)cout << "Elli ";
		else if (onlar == 6)cout << "Altmýþ ";
		else if (onlar == 7)cout << "Yetmiþ ";
		else if (onlar == 8)cout << "Seksen ";
		else if (onlar == 9)cout << "Doksan ";
		switch (birler)
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
}

