#include <iostream>
#include <string>
using namespace std;

void Degistir(char *karakter, int *sayi)
{
	*karakter = 'C';
	*sayi = 40;
}

void Degistir2(char *dizi, char *ydizi, int otele)
{
	int i = 0;
	for (; *(dizi + i) != '\0'; i++)
		*(ydizi + i) = *(dizi + i) + otele;
	*(ydizi + 6) = *(ydizi + 6);
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	char Harf = 'A';
	int Sayi1 = 5;
	double Sayi2 = 5.0;
	Degistir(&Harf, &Sayi1);
	cout << "Harf: " << Harf << endl;
	cout << "Sayi1: " << Sayi1 << endl;

	char isim[6];
	cout << "�sim: ";
	cin >> isim;
	cout << isim << endl; //Metin dizilerde de�eri yazar. Di�er veri t�rlerinde dizi ad� adresi yazar.
	for (int i = 0; i < 5; i++)
		cout << isim[i] << endl;

	for (int i = 0; i < 5; i++)
		cout << *(isim + i) << endl;

	for (int i = 0; i < 5; i++)
	{
		char k = *(isim + i) + 2;
		cout << k << endl;
	}

	//Sezar �ifreleme Y�ntemi
	cout << "�sim: ";
	cin >> isim;
	char sifreli[6];
	Degistir2(isim, sifreli, 5);
	cout << sifreli << endl;


	system("PAUSE");
	return 0;
}