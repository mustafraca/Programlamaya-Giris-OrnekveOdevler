/****************************************************************************
**							      SAKARYA ÜNÝVERSÝTESÝ
**					    BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**						 BÝLÝÞÝM SÝSTEMLERÝ MÜHENDÝSLÝÐÝ BÖLÜMÜ
**							 PROGRAMLAMAYA GÝRÝÞ DERSÝ
**							   2017-2018 GÜZ DÖNEMÝ
**
**							ÖDEV NUMARASI..........: 3
**							ÖÐRENCÝ ADI............: Mustafa ACAR
**							ÖÐRENCÝ NUMARASI.......: B161200304
**                          DERSÝN ALINDIÐI GRUP...: A
****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	while (true)
	{
		char kelime[100], istenenharf[100];
		int uzunluk = 0, adet = 0, bayrak = 0;
		system("CLS");
		cout << "..:: String Ýþlemleri ::.." << endl;
		cout << "Ýþlem Yapýlacak Stringi giriniz: ";
		cin >> kelime;
		cout << "Ýstenen Harf: ";
		cin >> istenenharf;
		// Aranan harf uzunluðunu bulur.
		for (; istenenharf[uzunluk] != '\0';) uzunluk++;
		// Aranan harf uzunluðu birden fazla harf içeriyor mu?
		if (uzunluk == 1)
		{
			uzunluk = 0;
			// Kelimenin uzunluðunu bulur.
			for (; kelime[uzunluk] != '\0';) uzunluk++;
			//Aranan harfin, kelime içerisinde kaç adet olduðunu bulur. Eðer iki adet bulunursa döngüden çýkar.
			for (int i = 0;i < uzunluk;i++)
			{
				if (istenenharf[0] == kelime[i])
				{
					adet++;
					if (adet >= 2) break;
				}
			}
			if (adet < 2) cout << "Cümle içerisinde aranan harf bulunamamýþtýr." << endl;
			else
			{
				for (int i = 0; i < uzunluk;i++)
				{
					// Aranan harf arasýndaki kelimeyi bulur.
					if (kelime[i] == istenenharf[0])
					{
						bayrak += 1;
						if (bayrak == 2)
						{
							cout << endl; break;
						}
					}
					else if (bayrak == 1)
						cout << kelime[i];
				}
			}
		}
		else cout << "Birden fazla harf giriþi yaptýnýz." << endl;
		cout << "Devam etmek için bir tuþa basýnýz.";
		_getche();
	}
	return 0;
}



