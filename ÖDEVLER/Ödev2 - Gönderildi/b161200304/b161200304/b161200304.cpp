/****************************************************************************
**							      SAKARYA ÜNÝVERSÝTESÝ 
**					    BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ 
**						 BÝLÝÞÝM SÝSTEMLERÝ MÜHENDÝSLÝÐÝ BÖLÜMÜ 
**							 PROGRAMLAMAYA GÝRÝÞ DERSÝ 
**							   2017-2018 GÜZ DÖNEMÝ 
**  
**							ÖDEV NUMARASI..........: 2
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
		system("CLS");
		int matris[10][10];
		int satirsayisi;
		int secim;
		int satirenbuyuk = 0;
		int satirtoplam = 0;
		cout << "..::Matris Ýþlemleri ::.." << endl;
		cout << "Matrisin satýr sayýsýný giriniz(1-10 Arasýnda): ";
		cin >> satirsayisi;
		if (satirsayisi >= 1 && satirsayisi <= 10)
		{
			// Kullanýcý tarafýndan girilen sayý büyüklüðünde kare matris oluþturma. Deðerler kullanýcý tarafýndan girilir.
			for (int i = 0; i < satirsayisi; i++)
				for (int j = 0; j < satirsayisi; j++)
				{
					cout << "[" << i + 1 << "," << j + 1 << "]=";
					cin >> matris[i][j];
				}
			// Oluþturulan matrisi listeleme.
			for (int i = 0; i < satirsayisi;i++)
				for (int j = 0; j < satirsayisi; j++)
				{
					cout << matris[i][j] << " ";
					if (j == satirsayisi - 1)
						cout << endl;
				}
			cout << "1-Satýr En Büyük" << endl << "2-Satýr Toplam" << endl << "Seçiminiz: ";
			cin >> secim;
			if (secim == 1 || secim == 2)
			{
				if (secim == 1)
				{
					//Kullanýcý seçimi 1 ise her satýrdaki en büyük deðeri bulur.
					for (int i = 0; i < satirsayisi; i++)
					{
						for (int j = 0; j < satirsayisi; j++)
						{
							if (satirenbuyuk < matris[i][j])
								satirenbuyuk = matris[i][j];
						}
						cout << satirenbuyuk << " ";
						satirenbuyuk = 0;
					}
				}
				if (secim == 2)
				{
					//Kullanýcý seçimi 2 ise her satýrýn toplamýný hesaplar.
					for (int i = 0; i < satirsayisi; i++)
					{
						for (int j = 0; j < satirsayisi; j++)
						{
							satirtoplam += matris[i][j];
						}
						cout << satirtoplam << " ";
						satirtoplam = 0;
					}
				}
			}
			else
				cout << "Hatalý Seçim.";
		}
		else
			cout << "Aralýk dýþýnda sayý giriþi yaptýnýz.";
		cout << endl << "Devam etmek için bir tuþa basýnýz...";
		_getch();
	}
	return 0;
}

