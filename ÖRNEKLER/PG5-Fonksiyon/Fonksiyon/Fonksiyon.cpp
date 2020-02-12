// Fonksiyon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
using namespace std;

struct Kayit
{
	string ad;
	string soyad;
	int sicilNo;
	int ucret;
};

Kayit kayit[100];
int ks = 0;
int silinecek;
void Ekle()
{
	cout << "Adý: "; cin >> kayit[ks].ad;
	cout << "Soyadý: "; cin >> kayit[ks].soyad;
	cout << "Sicil Numarasý: "; cin >> kayit[ks].sicilNo;
	cout << "Ücret : "; cin >> kayit[ks].ucret; 
	ks++;
}

void Listele()
{
	cout << "Adý" << setw(15) << "Soyadý" << setw(30) << "Sicil Numarasý" << setw(20) << "Ücret" << endl;
	for (int i = 0; i < ks; i++)
	{
		cout << i + 1 << ". " << kayit[i].ad << setw(15) << kayit[i].soyad << setw(25) << kayit[i].sicilNo << setw(25) << kayit[i].ucret << endl;
	}
}

void Sil()
{
	Listele();
	cout << "Silinecek kiþinin numarasýný: ";
	cin >> silinecek;
	kayit[silinecek].ad.clear();
	kayit[silinecek].soyad.clear();
	kayit[silinecek].sicilNo = NULL;
	kayit[silinecek].ucret = NULL;
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	int secim = 0;
	while (true)
	{
		system("CLS");
		cout << "1- Kayýt Ekle" << endl;
		cout << "2- Kayýt Sil" << endl;
		cout << "3- Kayýtlarý Listele" << endl;
		cout << "Seçiminiz: "; cin >> secim;
		switch (secim)
		{
		case 1:
			Ekle();
			break;
		case 2:
			Sil();
			break;
		case 3:
			Listele();
			break;
		default: cout << "Hatalý bir seçim yaptýnýz:"; break;
		}
		cout << "Devam etmek için bir tuþa basýnýz.";
		_getch();
	}
	return 0;
}


