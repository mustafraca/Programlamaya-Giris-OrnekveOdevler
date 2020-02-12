#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	char Harf = 'A';
	int Sayi1 = 5;
	double Sayi2 = 5.0;
	cout << "Harf: " << Harf << endl;
	cout << "Sayi1: " << Sayi1 << endl;
	cout << "Sayi2: " << Sayi2 << endl;
	cout << "Harf Adres: " << &Harf << endl;
	cout << "Sayi1 Adres: " << &Sayi1 << endl;
	cout << "Sayi2 Adres: " << &Sayi2 << endl;
	int *Adres1 = &Sayi1;
	cout << "Adres1: " << Adres1 << endl;
	cout << "Adres1'in Adresi: " << &Adres1 << endl;
	cout << "Adresin1'in Adresindeki Deðer: " << *Adres1 << endl;

	*Adres1 += 5;
	cout << "Sayi1: " << Sayi1 << endl;
	*Adres1 *= 2;
	cout << "Sayi1: " << Sayi1 << endl;

	
	return 0;
}