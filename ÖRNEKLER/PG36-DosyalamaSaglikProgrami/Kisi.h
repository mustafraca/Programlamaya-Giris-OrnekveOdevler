#ifndef KISI_H
#define	KISI_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;
class Kisi {
public:
	string isim;
	int boy;
	int yas;
	int cinsiyet;
	int kilo;
	string tarih;
	void bilgiGir() {
		system("cls");
		cout << "Kay�t ��lemi: " << endl;
		cout << "Ki�inin �smi:"; cin >> isim;
		cout << "Ki�inin Boyu: "; cin >> boy;
		cout << "Ki�inin Ya��: "; cin >> yas;
		do {
			cout << "Ki�inin Cinsiyeti (1-Kad�n/2-Erkek): ";
			cin >> cinsiyet;
		} while (!(cinsiyet == 1 || cinsiyet == 2));

		cout << "Ki�inin Kilosu: "; cin >> kilo;
	}
	long ikilo() {
		if (cinsiyet == 1)
			return llround((boy - 100)*0.8 + (yas / 10.0));
		return llround((boy - 100)*0.9 + (yas / 10.0));
	}
	void bilgiYaz() {
		cout << isim << "      " << boy;
		cout << "      " << yas;
		cout << "      ";
		if (cinsiyet == 1) cout << "Kad�n";
		else cout << "Erkek";
		cout << "      " << cinsiyet;
		cout << "      " << kilo;
		cout << "      " << ikilo();
		cout << endl;
	}
	void ayrintiliYaz() {
		cout << "�sim: " << isim << endl;
		cout << "Boy: " << boy << endl;
		cout << "Ya�: " << yas << endl;
		cout << "Cinsiyet: ";
		if (cinsiyet == 1) cout << "Kad�n";
		else cout << "Erkek";
		cout << "Kilosu: " << kilo << endl;
		cout << "�deal Kilosu: " << ikilo() << endl;
		cout << endl;
	}
};
#endif // !KISI_H


