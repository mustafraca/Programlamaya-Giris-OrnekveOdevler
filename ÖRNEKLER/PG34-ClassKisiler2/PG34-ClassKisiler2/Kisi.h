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
	static int adet;
	void KisiSayisi()
	{
		cout << "Ki�i Say�s�: " << adet << endl;
	}
	Kisi(string ad, string soyad, int yas)
	{
		adet++;
		this->ad = ad;
		this->soyad = soyad;
		this->yas = yas;
	}
	Kisi() { adet++; }
	Kisi(string ad)
	{
		adet++;
		this->ad = ad;
	}
	Kisi(int yas)
	{
		adet++;
		this->yas;
	}
	void BilgiGir()
	{
		cout << "Ad: "; cin >> ad;
		cout << "Soyad: "; cin >> soyad;
		cout << "Ya�: "; cin >> yas;
	}
	void BilgiYaz()
	{
		cout << "Ad: " << ad << endl;
		cout << "Soyad: " << soyad << endl;
		cout << "Ya�: " << yas << endl;
	}
	~Kisi() {} // Y�k�c� Method
};
int Kisi::adet = 0;

#endif // !KISI_H
