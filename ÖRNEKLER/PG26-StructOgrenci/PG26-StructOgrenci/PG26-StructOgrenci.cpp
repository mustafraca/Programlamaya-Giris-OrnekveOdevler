// PG26-StructOgrenci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

struct Ogrenci
{
	char ad[10];
	char soyad[10];
	int vize;
	int finali;
	double ort;
};
int main()
{
	setlocale(LC_ALL, "Turkish");

	int os;
	cout << "Öðrenci Sayýsý: ";
	cin >> os;
	Ogrenci ogrenciler[100];
	for (int i = 0; i < os;i++)
	{
		system("CLS");
		cout << i + 1 << ". öðrencinin: " << endl;
		cout << "Adý: "; cin >> ogrenciler[i].ad;
		cout << "Soyadý: ";cin >> ogrenciler[i].soyad;
		cout << "Vize: ";cin >> ogrenciler[i].vize;
		cout << "Final: ";cin >> ogrenciler[i].finali;
	}
	for (int i = 0; i < os; i++)
	{
		ogrenciler[i].ort = (ogrenciler[i].vize + ogrenciler[i].finali) / 2.0;
	}
	system("CLS");
	cout << "Dersi Geçenler" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Ad" << setw(15) << "Soyad" << setw(25) << "Ortalamasý" << endl;
	for (int i = 0;i < os;i++)
	{
		if (ogrenciler[i].ort > 50)
		{
			cout << ogrenciler[i].ad;
			cout << setw(10) << ogrenciler[i].soyad;
			cout << setw(20) << setprecision(4) << ogrenciler[i].ort;
			cout << endl;
		}
	}

	system("PAUSE");
	return 0;
}



