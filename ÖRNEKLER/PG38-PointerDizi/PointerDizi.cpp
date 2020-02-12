#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	char Harf = 'A';
	int Sayi1 = 5;
	double Sayi2 = 5.0;
	int Sayilar[5] = { 5,10,15,20,25 };
	cout << "Sayilar Dizisinin 1. Eleman Adresi: " << Sayilar << endl;
	cout << "Sayilar Dizisinin 2. Eleman Adresi: " << Sayilar + 1 << endl;
	cout << "Sayilar Dizisinin 3. Eleman Adresi: " << Sayilar + 2 << endl;

	cout << "Sayilar Dizisinin 1. Eleman Adresi: " << &Sayilar[0] << endl;
	cout << "Sayilar Dizisinin 2. Eleman Adresi: " << &Sayilar[1] << endl;
	cout << "Sayilar Dizisinin 3. Eleman Adresi: " << &Sayilar[2] << endl;

	cout << "Sayilar Dizisinin 1. Eleman Deðeri: " << Sayilar[0] << endl;
	cout << "Sayilar Dizisinin 2. Eleman Deðeri: " << Sayilar[1] << endl;
	cout << "Sayilar Dizisinin 3. Eleman Deðeri: " << Sayilar[2] << endl;

	cout << "Sayilar Dizisinin 1. Eleman Deðeri: " << *Sayilar<< endl;
	cout << "Sayilar Dizisinin 2. Eleman Deðeri: " << *(Sayilar + 1) << endl;
	cout << "Sayilar Dizisinin 3. Eleman Deðeri: " << *(Sayilar + 2) << endl;

	for (int i = 0; i < 5; i++)
		cout << *(Sayilar + i) << " " << (Sayilar + i) << " " << &Sayilar[i] << endl;
	int *diziAdres = Sayilar;
	cout << "Dizi Adres: " << diziAdres << endl;

	for (int i = 0; i < 5; i++)
		cout << *(Sayilar + i) << " " << diziAdres << endl;
	cout << "Dizi Adres: " << diziAdres << endl;

	for (int i = 0; i < 5; i++)
		cout << *(Sayilar + i) + 2 << " " << diziAdres << endl;
	cout << "Dizi Adres: " << diziAdres << endl;



	system("PAUSE");
	return 0;
}