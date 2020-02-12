// PG27-StructKiloHesabý.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
char Cinsiyet[2][6] = { "Kadýn","Erkek" };

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
	cout << "Kiþinin Adý: "; cin >> kisi.ad;
	system("CLS");
	cout << "Kiþinin Soyadý: "; cin >> kisi.soyad;
	system("CLS");
	cout << "Kiþinin Boyu: "; cin >> kisi.boy;
	system("CLS");
	cout << "Kiþinin Yaþý: "; cin >> kisi.yas;
	system("CLS");
	cout << "Kiþinin Cinsiyeti (0-Kadýn 1-Erkek): "; cin >> kisi.cinsiyet;
	system("CLS");
	cout << "Kiþinin Kilosu: "; cin >> kisi.kilo;

	if (kisi.cinsiyet == 0) kisi.ikilo = round((kisi.boy - 100)*0.8 + (kisi.yas / 10));
	else kisi.ikilo = round((kisi.boy - 100)*0.9 + (kisi.yas / 10));

	int fark = kisi.kilo - kisi.ikilo;
	system("CLS");
	cout << "Ýdeal kilonuz: " << kisi.ikilo << endl;
	if (fark > 0) cout << fark << " kilo vermelisiniz." << endl;
	else if (fark < 0) cout << abs(fark) << " kilo almalýsýnýz." << endl;
	else cout << "Tebrikler" << endl;

	system("PAUSE");
    return 0;
}

