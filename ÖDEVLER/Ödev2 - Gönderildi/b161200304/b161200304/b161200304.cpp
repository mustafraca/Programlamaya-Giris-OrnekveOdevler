/****************************************************************************
**							      SAKARYA �N�VERS�TES� 
**					    B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES� 
**						 B�L���M S�STEMLER� M�HEND�SL��� B�L�M� 
**							 PROGRAMLAMAYA G�R�� DERS� 
**							   2017-2018 G�Z D�NEM� 
**  
**							�DEV NUMARASI..........: 2
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
		system("CLS");
		int matris[10][10];
		int satirsayisi;
		int secim;
		int satirenbuyuk = 0;
		int satirtoplam = 0;
		cout << "..::Matris ��lemleri ::.." << endl;
		cout << "Matrisin sat�r say�s�n� giriniz(1-10 Aras�nda): ";
		cin >> satirsayisi;
		if (satirsayisi >= 1 && satirsayisi <= 10)
		{
			// Kullan�c� taraf�ndan girilen say� b�y�kl���nde kare matris olu�turma. De�erler kullan�c� taraf�ndan girilir.
			for (int i = 0; i < satirsayisi; i++)
				for (int j = 0; j < satirsayisi; j++)
				{
					cout << "[" << i + 1 << "," << j + 1 << "]=";
					cin >> matris[i][j];
				}
			// Olu�turulan matrisi listeleme.
			for (int i = 0; i < satirsayisi;i++)
				for (int j = 0; j < satirsayisi; j++)
				{
					cout << matris[i][j] << " ";
					if (j == satirsayisi - 1)
						cout << endl;
				}
			cout << "1-Sat�r En B�y�k" << endl << "2-Sat�r Toplam" << endl << "Se�iminiz: ";
			cin >> secim;
			if (secim == 1 || secim == 2)
			{
				if (secim == 1)
				{
					//Kullan�c� se�imi 1 ise her sat�rdaki en b�y�k de�eri bulur.
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
					//Kullan�c� se�imi 2 ise her sat�r�n toplam�n� hesaplar.
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
				cout << "Hatal� Se�im.";
		}
		else
			cout << "Aral�k d���nda say� giri�i yapt�n�z.";
		cout << endl << "Devam etmek i�in bir tu�a bas�n�z...";
		_getch();
	}
	return 0;
}

