// PG27-StructKiloHesab�.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
char Cinsiyet[2][6] = { "Kad�n","Erkek" };

struct Kisi
{
	char ad[10];
	char soyad[15];
	int boy;
	int yas;
	int kilo;
	int cinsiyet;
	int ikilo;
};
int main()
{
	setlocale(LC_ALL, "Turkish");

	Kisi kisi;
	system("CLS");
	cout << "Ki�inin Ad�: "; cin >> kisi.ad;
	system("CLS");
	cout << "Ki�inin Soyad�: "; cin >> kisi.soyad;
	system("CLS");
	cout << "Ki�inin Boyu: "; cin >> kisi.boy;
	system("CLS");
	cout << "Ki�inin Ya��: "; cin >> kisi.yas;
	system("CLS");
	cout << "Ki�inin Cinsiyeti (0-Kad�n 1-Erkek): "; cin >> kisi.cinsiyet;
	system("CLS");
	cout << "Ki�inin Kilosu: "; cin >> kisi.kilo;

	if (kisi.cinsiyet == 0) kisi.ikilo = round((kisi.boy - 100)*0.8 + (kisi.yas / 10));
	else kisi.ikilo = round((kisi.boy - 100)*0.9 + (kisi.yas / 10));

	int fark = kisi.kilo - kisi.ikilo;
	system("CLS");
	cout << "�deal kilonuz: " << kisi.ikilo << endl;
	if (fark > 0) cout << fark << " kilo vermelisiniz." << endl;
	else if (fark < 0) cout << abs(fark) << " kilo almal�s�n�z." << endl;
	else cout << "Tebrikler" << endl;

	system("PAUSE");
    return 0;
}

