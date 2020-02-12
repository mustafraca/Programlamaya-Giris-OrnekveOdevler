#ifndef SP_H
#define SP_H
#include <iostream>
#include <string>
#include <fstream>
#include "Kisi.h"
using namespace std;

class SP {
private:
	string dosya;
	int secim;
	string isim;
	void Menu() {
		system("cls");
		cout << "..:: ��LEMLER ::.." << endl;
		cout << "------------------" << endl;
		cout << "1 - Kay�t Ekle" << endl;
		cout << "2 - Kay�t Listele" << endl;
		cout << "3 - Kay�t Ara" << endl;
		cout << "4 - Ki�i Ayr�nt� Kaydet" << endl;
		cout << "5 - Ki�i Ayr�nt� Listele" << endl;
		cout << "99 - ��k��" << endl;
		cout << "------------------" << endl;
		cout << "Se�iminiz: ";
		cin >> secim;
	}


	void Calistir(int secim) {
		switch (secim) {
		case 1:KayitEkle(); break;
		case 2:KayitListele(); break;
		case 3:KayitAra(); break;
		case 4:kisiAyrintiKaydet(); break;
		case 99:break;
		default:
			cout << "Hatal� ��lem Se�imi" << endl;
			break;
		}
	}
	void kisiAyrintiKaydet() {
		Kisi kisi;
		ifstream dosyaOku(dosya, ios::in);
		system("cls");
		cout << "Ayr�nt� Kay�t ��lemi: " << endl;
		cout << "Aranacak �sim: " << endl;
		cin >> isim;

		int bayrak = 1;
		while (!dosyaOku.eof()) {
			dosyaOku >> kisi.isim;
			dosyaOku >> kisi.boy;
			dosyaOku >> kisi.yas;
			dosyaOku >> kisi.cinsiyet;
			dosyaOku >> kisi.kilo;
			if (kisi.isim == isim) {
				bayrak = 0;
				break;
			}
		}
		if (bayrak) cout << "Aranan kay�t bulunumad�." << endl;
		{
			cout << "Ki�inin yeni kilosu: ";
			cin >> kisi.kilo;
			cout << "Kay�t Tarihi:";
			cin >> kisi.tarih;
			ofstream dosyaYaz(kisi.isim + ".txt", ios::app);
			dosyaYaz << kisi.tarih << "\t" << kisi.kilo << "\n";
			dosyaYaz.close();
		}
		dosyaOku.close();
	}
	void KayitEkle() {
		Kisi kisi;
		ofstream dosyaYaz(dosya, ios::app);
		kisi.bilgiGir();
		dosyaYaz << kisi.isim << "\t";
		dosyaYaz << kisi.boy << "\t";
		dosyaYaz << kisi.yas << "\t";
		dosyaYaz << kisi.cinsiyet << "\t";
		dosyaYaz << kisi.kilo << "\t";


		dosyaYaz << kisi.isim << "\t" << kisi.boy << "\n";
		dosyaYaz.close();
	}
	void KayitListele() {
		Kisi kisi;
		ifstream dosyaOku(dosya, ios::in);
		system("cls");
		cout << "Listeleme ��lemi: " << endl;
		cout << "�sim                 Boy" << endl;
		while (!dosyaOku.eof()) {
			dosyaOku >> kisi.isim;
			dosyaOku >> kisi.boy;
			dosyaOku >> kisi.yas;
			dosyaOku >> kisi.cinsiyet;
			dosyaOku >> kisi.kilo;
			kisi.bilgiYaz();

		}
		dosyaOku.close();
	}
	void KayitAra() {
		Kisi kisi;

		ifstream dosyaOku(dosya, ios::in);
		system("cls");
		cout << "Arama ��lemi: " << endl;
		cout << "Aranacak �sim: " << endl;
		cin >> isim;

		int bayrak = 1;
		while (!dosyaOku.eof()) {
			dosyaOku >> kisi.isim;
			dosyaOku >> kisi.boy;
			dosyaOku >> kisi.yas;
			dosyaOku >> kisi.cinsiyet;
			dosyaOku >> kisi.kilo;
			if (kisi.isim == isim) {
				bayrak = 0;
				kisi.ayrintiliYaz();
			}
		}
		if (bayrak) cout << "Aranan kay�t bulunumad�." << endl;
		dosyaOku.close();
	}
public:
	SP() {
		dosya = "kayits.txt";
	}
	void Islem() {
		do {
			Menu();

			Calistir(secim);
			system("PAUSE");
		} while (secim != 99);
	}
};
#endif // !SP_H

