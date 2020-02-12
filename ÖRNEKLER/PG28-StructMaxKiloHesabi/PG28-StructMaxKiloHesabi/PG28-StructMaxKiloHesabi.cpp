// PG28-StructMaxKiloHesabi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
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

	Kisi kisi[100];
	int ks=0;
	int secim;
	do
	{
		system("CLS");
		cout << "1 - Kiþi Ekle" << endl;
		cout << "2 - Listele" << endl;
		cout << "3 - Kilo Vermesi Gerekenleri Listele" << endl;
		cout << "4 - Kilo Almasý Gerekenleri Listele" << endl;
		cout << "5 - Ýdeal Kilodakileri Listele" << endl;
		cout << "6 - Ýsminin Ýlk Harfine Göre Listele" << endl;
		cout << "9 - Çýkýþ" << endl;
		cout << "Seçiminiz: "; cin >> secim;
		switch (secim)
		{
		case 1:
			system("CLS");
			cout << "Kiþinin Adý: "; cin >> kisi[ks].ad;
			cout << "Kiþinin Soyadý: "; cin >> kisi[ks].soyad;
			cout << "Kiþinin Boyu: "; cin >> kisi[ks].boy;
			cout << "Kiþinin Yaþý: "; cin >> kisi[ks].yas;
			cout << "Kiþinin Cinsiyeti (0-Kadýn 1-Erkek): "; cin >> kisi[ks].cinsiyet;
			cout << "Kiþinin Kilosu: "; cin >> kisi[ks].kilo;

			if (kisi[ks].cinsiyet == 0) kisi[ks].ikilo = round((kisi[ks].boy - 100)*0.8 + (kisi[ks].yas / 10));
			else kisi[ks].ikilo = round((kisi[ks].boy - 100)*0.9 + (kisi[ks].yas / 10));
			ks++;
			break;
		case 2:
			system("CLS");
			cout << "Ad " << setw(8) << "Soyad" << setw(5) << "Cinsiyet" << setw(3) << "Ýdeal Kilo" << setw(2) << "Durum" << endl;
			cout << "-----------------------------------------------------------------------" << endl;

			for (int i = 0;i < ks;i++)
			{
				int fark = kisi[i].kilo - kisi[i].ikilo;
				cout << kisi[i].ad << setw(7);
				cout << kisi[i].soyad << setw(7);
				cout << Cinsiyet[kisi[i].cinsiyet] << setw(5);
				cout << kisi[i].ikilo << setw(10);
				if (fark > 0) cout << fark << " kilo vermelisiniz." << endl;
				else if (fark < 0) cout << abs(fark) << " kilo almalýsýnýz." << endl;
				else cout << "Tebrikler" << endl;
			}
			break;
		}
		cout << "Devam Etmek Ýçin Bir Tuþa Basýnýz.";
		_getch();
	} while (secim != 9);
	return 0;
}

