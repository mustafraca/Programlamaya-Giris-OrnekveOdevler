#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct rehber
{
	string ad;
	string tel;
};

void KayitEkle()
{
	ofstream dosyaYaz;
	dosyaYaz.open("Rehber.txt", ios::app);
	rehber kisi;
	system("CLS");
	cout << "Kiþinin Adý: "; cin >> kisi.ad;
	cout << "Kiþinin Telefonu: "; cin >> kisi.tel;
	dosyaYaz << kisi.ad << "\t" << kisi.tel << "\n";
	dosyaYaz.close();
}

void KayitListele()
{
	ifstream dosyaOku;
	dosyaOku.open("Rehber.txt");
	system("CLS");
	rehber kisi;
	cout << "Ýsim            Tel\n----------------------------\n";
	while (!dosyaOku.eof())
	{
		dosyaOku >> kisi.ad >> setw(15) >> kisi.tel;
		cout << kisi.ad << setw(15) << kisi.tel << endl;
	}
	dosyaOku.close();
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	rehber rehberim;
	int secim;

	do
	{
		system("CLS");
		cout << "..:ÝÞLEMLER:.." << endl;
		cout << "1-Kayýt Ekle" << endl;
		cout << "2-Kayýt Listele" << endl;
		cout << "99-Çýkýþ" << endl;
		cout << "Seçiminiz: "; cin >> secim;

		switch (secim)
		{
		case 1:KayitEkle(); break;
		case 2:KayitListele(); break;
		case 99: break;
		default: cout << "Hatalý Seçim!"; break;
		}
		system("PAUSE");
	} while (secim != 99);

	return 0;
}

