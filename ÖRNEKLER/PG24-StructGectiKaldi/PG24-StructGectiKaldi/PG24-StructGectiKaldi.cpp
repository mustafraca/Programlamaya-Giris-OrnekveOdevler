// PG24-StructGectiKaldi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct ogrenci
{
	char ad[10];
	char soyad[10];
	int vize;
	int final;
	double ort;
};

int main()
{
	setlocale(LC_ALL, "Turkish");

	ogrenci ogr1;
	cout << "��rencinin ad�: "; cin >> ogr1.ad;
	cout << "��rencinin soyad�: "; cin >> ogr1.soyad;
	cout << "��rencinin vizesi: "; cin >> ogr1.vize;
	cout << "��rencinin finali: "; cin >> ogr1.final;

	/*
	strcpy_s(ogr1.ad, "Ali");
	strcpy_s(ogr1.soyad, "Gelge�");
	ogr1.vize = 60;
	ogr1.finali = 70;
	*/

	ogr1.ort = (ogr1.vize + ogr1.final) / 2.0;
	if (ogr1.ort >= 50) cout << ogr1.ad << " " << ogr1.soyad << " Ge�ti." << endl;
	else cout << ogr1.ad << " " << ogr1.soyad << " Kald�." << endl;

	system("PAUSE");
    return 0;
}

