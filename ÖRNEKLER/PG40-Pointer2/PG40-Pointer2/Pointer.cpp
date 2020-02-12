#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int sayi = 22;
	int *adres = &sayi;
	int **adresinadresi = &adres;

	cout << "Sayi  =  *Adres" << endl;
	cout << sayi << " = " << *adres << endl;
	cout << "&Sayi = Adres" << endl;
	cout << &sayi << " = " << adres << endl;
	cout << "Sayi = *Adres = **AdresinAdresi" << endl;
	cout << sayi << " = " << *adres << " = " << **adresinadresi << endl;
	cout << "&Sayi = Adres = *AdresinAdresi" << endl;
	cout << &sayi << " = " << adres << " = " << *adresinadresi << endl;
	cout << "&Adres = AdresinAdresi" << endl;
	cout << &adres << " = " << adresinadresi << endl;
	

	system("PAUSE");
	return 0;
}