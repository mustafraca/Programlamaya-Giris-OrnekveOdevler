// PG31-ClassTan�mlamas�2.cpp : Defines the entry point for the console application.
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
	/*cout << "Araban�n Markas�: " << araba.getMarka() << endl;
	cout << "Araban�n Modeli: " << araba.getModel() << endl;
	cout << "Araban�n Max H�z�: " << araba.getmaxHiz() << endl;
	cout << "Araban�n H�z�: " << araba.getHiz() << endl;*/

	int secim, hiz;
	do
	{
		system("CLS");
		cout << "-��lemler-" << endl;
		cout << "1-Araban�n Markas�: " << endl;
		cout << "2-Araban�n Modeli: " << endl;
		cout << "3-Araban�n Max H�z�: " << endl;
		cout << "4-Araban�n H�z�: " << endl;
		cout << "5-Gaza Bas: " << endl;
		cout << "6-Frene Bas: " << endl;
		cout << "99-��k�� " << endl;
		cout << "Se�iminiz: ";
		cin >> secim;
		system("CLS");
		try
		{
			if (secim == 1) cout << "Araban�n Markas�: " << araba.getMarka() << endl;
			else if (secim == 2) cout << "Araban�n Modeli: " << araba.getModel() << endl;
			else if (secim == 3) cout << "Araban�n Max H�z�: " << araba.getmaxHiz() << endl;
			else if (secim == 4) cout << "Araban�n H�z�: " << araba.getHiz() << endl;
			else if (secim == 5)
			{
				cout << "Ne kadar h�zlanacaks�n�z: ";
				cin >> hiz;
				araba.Hizlan(hiz);
			}
			else if (secim == 6)
			{
				cout << "Ne kadar yava�layacaks�n�z: ";
				cin >> hiz;
				araba.Yavasla(hiz);
			}
			else if (secim == 99) {}
			else cout << "Hatal� Se�im" << endl;
		}
		catch (int hata)
		{
			if (hata == 1) cout << araba.getmaxHiz() << " Km h�z� ge�emezsiniz.";
			if (hata == 2) cout << "Araba durdu" << endl;
		}
		system("PAUSE");
	} while (secim != 99);

    return 0;
}

