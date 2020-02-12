// PG31-ClassTanýmlamasý2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Araba.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	Araba araba("Toyota", "Corolla", 300);
	/*cout << "Arabanýn Markasý: " << araba.getMarka() << endl;
	cout << "Arabanýn Modeli: " << araba.getModel() << endl;
	cout << "Arabanýn Max Hýzý: " << araba.getmaxHiz() << endl;
	cout << "Arabanýn Hýzý: " << araba.getHiz() << endl;*/

	int secim, hiz;
	do
	{
		system("CLS");
		cout << "-Ýþlemler-" << endl;
		cout << "1-Arabanýn Markasý: " << endl;
		cout << "2-Arabanýn Modeli: " << endl;
		cout << "3-Arabanýn Max Hýzý: " << endl;
		cout << "4-Arabanýn Hýzý: " << endl;
		cout << "5-Gaza Bas: " << endl;
		cout << "6-Frene Bas: " << endl;
		cout << "99-Çýkýþ " << endl;
		cout << "Seçiminiz: ";
		cin >> secim;
		system("CLS");
		try
		{
			if (secim == 1) cout << "Arabanýn Markasý: " << araba.getMarka() << endl;
			else if (secim == 2) cout << "Arabanýn Modeli: " << araba.getModel() << endl;
			else if (secim == 3) cout << "Arabanýn Max Hýzý: " << araba.getmaxHiz() << endl;
			else if (secim == 4) cout << "Arabanýn Hýzý: " << araba.getHiz() << endl;
			else if (secim == 5)
			{
				cout << "Ne kadar hýzlanacaksýnýz: ";
				cin >> hiz;
				araba.Hizlan(hiz);
			}
			else if (secim == 6)
			{
				cout << "Ne kadar yavaþlayacaksýnýz: ";
				cin >> hiz;
				araba.Yavasla(hiz);
			}
			else if (secim == 99) {}
			else cout << "Hatalý Seçim" << endl;
		}
		catch (int hata)
		{
			if (hata == 1) cout << araba.getmaxHiz() << " Km hýzý geçemezsiniz.";
			if (hata == 2) cout << "Araba durdu" << endl;
		}
		system("PAUSE");
	} while (secim != 99);

    return 0;
}

