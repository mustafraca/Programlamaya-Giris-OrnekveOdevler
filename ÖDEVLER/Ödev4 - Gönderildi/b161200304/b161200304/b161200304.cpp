/****************************************************************************
**							      SAKARYA ÜNÝVERSÝTESÝ
**					    BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**						 BÝLÝÞÝM SÝSTEMLERÝ MÜHENDÝSLÝÐÝ BÖLÜMÜ
**							 PROGRAMLAMAYA GÝRÝÞ DERSÝ
**							   2017-2018 GÜZ DÖNEMÝ
**
**							ÖDEV NUMARASI..........: 4
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
		char kelime[100], araters[100], istenenharf[100];
		int uzunluk = 0, adet = 0, bayrak = 0, secim;
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
				cout << "1-Ara Metni Tersten Yaz" << endl;
				cout << "2-Ara Metni Tekrarlý Yaz" << endl;
				cout << "Seçiminiz: ";
				cin >> secim;
				switch (secim)
				{
				case 1:	
					// Aranan harf arasýndaki kelimeyi tersine çevirerek araters dizisine aktarýr.
					for (int i = 0; i < uzunluk; i++)
					{
						if (kelime[i] == istenenharf[0])
						{
							if (bayrak == 0) adet = i;
							bayrak += 1;
							if (bayrak == 2)
							{
								for (int j = uzunluk - i + 1; j < uzunluk - adet; j++)
									cout << araters[j];
								cout << endl;
								break;
							}
						}
						else if (bayrak == 1)
							araters[uzunluk - i] = kelime[i];
					}
					break;
				case 2: 
					//Aranan harf aralýðýndaki kelimeyi bulur ve 5 kez ekrana yazdýrýr.
					for (int i = 0; i < 5; i++)
					{
						for (int i = 0; i < uzunluk;i++)
						{
							//Aranan harf arasýndaki kelimeyi bulur.
							if (kelime[i] == istenenharf[0])
							{
								bayrak += 1;
								if (bayrak == 2)
								{
									cout << endl;
									bayrak = 0;
									break;
								}
							}
							else if (bayrak == 1)
								cout << kelime[i];
						}
					}
					break;
				default: 
					cout << "Hatalý Seçim Yaptýnýz." << endl; break;
				}
			}
		}
		else cout << "Birden fazla harf giriþi yaptýnýz." << endl;
		cout << "Devam etmek için bir tuþa basýnýz.";
		_getch();
	}
	return 0;
}

