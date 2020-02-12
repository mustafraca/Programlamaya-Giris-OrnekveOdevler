// PG25-EnumTarihSaatAy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct sure {
	int saniye;
	int dakika;
	int saat;
};
struct tarih {
	int gun;
	int ay;
	int yil;
};
struct tarihSure {
	sure Sure;
	tarih Tarih;
};
int main()
{
	setlocale(LC_ALL, "Turkish");

	tarihSure tarih1;
	cout << "Gün: "; cin >> tarih1.Tarih.gun;
	cout << "Ay: "; cin >> tarih1.Tarih.ay;
	cout << "Yýl: "; cin >> tarih1.Tarih.yil;
	cout << "Saat: "; cin >> tarih1.Sure.saat;
	cout << "Dakika: "; cin >> tarih1.Sure.dakika;
	cout << "Saniye: "; cin >> tarih1.Sure.saniye;
	cout << "Tarihimiz: " << tarih1.Tarih.gun << "/" <<
		tarih1.Tarih.ay << "/" << tarih1.Tarih.yil << " " <<
		tarih1.Sure.saat << ":" << tarih1.Sure.dakika << ":" << 
		tarih1.Sure.saniye << endl;

	system("PAUSE");
    return 0;
}

