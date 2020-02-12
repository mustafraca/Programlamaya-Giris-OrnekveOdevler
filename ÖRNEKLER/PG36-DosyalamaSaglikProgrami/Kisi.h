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
		cout << "Kayýt Ýþlemi: " << endl;
		cout << "Kiþinin Ýsmi:"; cin >> isim;
		cout << "Kiþinin Boyu: "; cin >> boy;
		cout << "Kiþinin Yaþý: "; cin >> yas;
		do {
			cout << "Kiþinin Cinsiyeti (1-Kadýn/2-Erkek): ";
			cin >> cinsiyet;
		} while (!(cinsiyet == 1 || cinsiyet == 2));

		cout << "Kiþinin Kilosu: "; cin >> kilo;
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
		if (cinsiyet == 1) cout << "Kadýn";
		else cout << "Erkek";
		cout << "      " << cinsiyet;
		cout << "      " << kilo;
		cout << "      " << ikilo();
		cout << endl;
	}
	void ayrintiliYaz() {
		cout << "Ýsim: " << isim << endl;
		cout << "Boy: " << boy << endl;
		cout << "Yaþ: " << yas << endl;
		cout << "Cinsiyet: ";
		if (cinsiyet == 1) cout << "Kadýn";
		else cout << "Erkek";
		cout << "Kilosu: " << kilo << endl;
		cout << "Ýdeal Kilosu: " << ikilo() << endl;
		cout << endl;
	}
};
#endif // !KISI_H


