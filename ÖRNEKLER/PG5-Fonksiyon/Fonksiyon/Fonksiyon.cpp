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
	cout << "Ad�: "; cin >> kayit[ks].ad;
	cout << "Soyad�: "; cin >> kayit[ks].soyad;
	cout << "Sicil Numaras�: "; cin >> kayit[ks].sicilNo;
	cout << "�cret : "; cin >> kayit[ks].ucret; 
	ks++;
}

void Listele()
{
	cout << "Ad�" << setw(15) << "Soyad�" << setw(30) << "Sicil Numaras�" << setw(20) << "�cret" << endl;
	for (int i = 0; i < ks; i++)
	{
		cout << i + 1 << ". " << kayit[i].ad << setw(15) << kayit[i].soyad << setw(25) << kayit[i].sicilNo << setw(25) << kayit[i].ucret << endl;
	}
}

void Sil()
{
	Listele();
	cout << "Silinecek ki�inin numaras�n�: ";
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
		cout << "1- Kay�t Ekle" << endl;
		cout << "2- Kay�t Sil" << endl;
		cout << "3- Kay�tlar� Listele" << endl;
		cout << "Se�iminiz: "; cin >> secim;
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
		default: cout << "Hatal� bir se�im yapt�n�z:"; break;
		}
		cout << "Devam etmek i�in bir tu�a bas�n�z.";
		_getch();
	}
	return 0;
}


