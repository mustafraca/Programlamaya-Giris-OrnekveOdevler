#ifndef KISI_H
#define KISI_H
#include <iostream>
#include <string>
using namespace std;

class Kisi
{
private:
	string ad;
	string soyad;
	int yas;
public:
	Kisi(string ad, string soyad, int yas)
	{
		this->ad = ad;
		this->soyad = soyad;
		this->yas = yas;
	}
	Kisi () {}
	Kisi(string ad)
	{
		this->ad = ad;
	}
	Kisi(int yas)
	{
		this->yas;
	}
	void BilgiGir()
	{
		cout << "Ad: "; cin >> ad;
		cout << "Soyad: "; cin >> soyad;
		cout << "Yaþ: "; cin >> yas;
	}
	void BilgiYaz()
	{
		cout << "Ad: " << ad << endl;
		cout << "Soyad: " << soyad << endl;
		cout << "Yaþ: " << yas << endl;
	}
};

#endif // !KISI_H
