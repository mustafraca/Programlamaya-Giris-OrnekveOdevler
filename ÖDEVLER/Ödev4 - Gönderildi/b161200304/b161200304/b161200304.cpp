/****************************************************************************
**							      SAKARYA �N�VERS�TES�
**					    B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**						 B�L���M S�STEMLER� M�HEND�SL��� B�L�M�
**							 PROGRAMLAMAYA G�R�� DERS�
**							   2017-2018 G�Z D�NEM�
**
**							�DEV NUMARASI..........: 4
**							��RENC� ADI............: Mustafa ACAR
**							��RENC� NUMARASI.......: B161200304
**                          DERS�N ALINDI�I GRUP...: A
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
		cout << "..:: String ��lemleri ::.." << endl;
		cout << "��lem Yap�lacak Stringi giriniz: ";
		cin >> kelime;
		cout << "�stenen Harf: ";
		cin >> istenenharf;
		// Aranan harf uzunlu�unu bulur.
		for (; istenenharf[uzunluk] != '\0';) uzunluk++;
		// Aranan harf uzunlu�u birden fazla harf i�eriyor mu?
		if (uzunluk == 1)
		{
			uzunluk = 0;
			// Kelimenin uzunlu�unu bulur.
			for (; kelime[uzunluk] != '\0';) uzunluk++;
			//Aranan harfin, kelime i�erisinde ka� adet oldu�unu bulur. E�er iki adet bulunursa d�ng�den ��kar.
			for (int i = 0;i < uzunluk;i++)
			{
				if (istenenharf[0] == kelime[i])
				{
					adet++;
					if (adet >= 2) break;
				}
			}
			if (adet < 2) cout << "C�mle i�erisinde aranan harf bulunamam��t�r." << endl;
			else
			{
				cout << "1-Ara Metni Tersten Yaz" << endl;
				cout << "2-Ara Metni Tekrarl� Yaz" << endl;
				cout << "Se�iminiz: ";
				cin >> secim;
				switch (secim)
				{
				case 1:	
					// Aranan harf aras�ndaki kelimeyi tersine �evirerek araters dizisine aktar�r.
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
					//Aranan harf aral���ndaki kelimeyi bulur ve 5 kez ekrana yazd�r�r.
					for (int i = 0; i < 5; i++)
					{
						for (int i = 0; i < uzunluk;i++)
						{
							//Aranan harf aras�ndaki kelimeyi bulur.
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
					cout << "Hatal� Se�im Yapt�n�z." << endl; break;
				}
			}
		}
		else cout << "Birden fazla harf giri�i yapt�n�z." << endl;
		cout << "Devam etmek i�in bir tu�a bas�n�z.";
		_getch();
	}
	return 0;
}

