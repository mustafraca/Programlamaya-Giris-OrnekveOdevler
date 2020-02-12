// PG28-StructMaxKiloHesabi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
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

	Kisi kisi[100];
	int ks=0;
	int secim;
	do
	{
		system("CLS");
		cout << "1 - Ki�i Ekle" << endl;
		cout << "2 - Listele" << endl;
		cout << "3 - Kilo Vermesi Gerekenleri Listele" << endl;
		cout << "4 - Kilo Almas� Gerekenleri Listele" << endl;
		cout << "5 - �deal Kilodakileri Listele" << endl;
		cout << "6 - �sminin �lk Harfine G�re Listele" << endl;
		cout << "9 - ��k��" << endl;
		cout << "Se�iminiz: "; cin >> secim;
		switch (secim)
		{
		case 1:
			system("CLS");
			cout << "Ki�inin Ad�: "; cin >> kisi[ks].ad;
			cout << "Ki�inin Soyad�: "; cin >> kisi[ks].soyad;
			cout << "Ki�inin Boyu: "; cin >> kisi[ks].boy;
			cout << "Ki�inin Ya��: "; cin >> kisi[ks].yas;
			cout << "Ki�inin Cinsiyeti (0-Kad�n 1-Erkek): "; cin >> kisi[ks].cinsiyet;
			cout << "Ki�inin Kilosu: "; cin >> kisi[ks].kilo;

			if (kisi[ks].cinsiyet == 0) kisi[ks].ikilo = round((kisi[ks].boy - 100)*0.8 + (kisi[ks].yas / 10));
			else kisi[ks].ikilo = round((kisi[ks].boy - 100)*0.9 + (kisi[ks].yas / 10));
			ks++;
			break;
		case 2:
			system("CLS");
			cout << "Ad " << setw(8) << "Soyad" << setw(5) << "Cinsiyet" << setw(3) << "�deal Kilo" << setw(2) << "Durum" << endl;
			cout << "-----------------------------------------------------------------------" << endl;

			for (int i = 0;i < ks;i++)
			{
				int fark = kisi[i].kilo - kisi[i].ikilo;
				cout << kisi[i].ad << setw(7);
				cout << kisi[i].soyad << setw(7);
				cout << Cinsiyet[kisi[i].cinsiyet] << setw(5);
				cout << kisi[i].ikilo << setw(10);
				if (fark > 0) cout << fark << " kilo vermelisiniz." << endl;
				else if (fark < 0) cout << abs(fark) << " kilo almal�s�n�z." << endl;
				else cout << "Tebrikler" << endl;
			}
			break;
		}
		cout << "Devam Etmek ��in Bir Tu�a Bas�n�z.";
		_getch();
	} while (secim != 9);
	return 0;
}

