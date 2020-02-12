/****************************************************************************
**								   SAKARYA ÜNÝVERSÝTESÝ
**							BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**								BÝLÝÞÝM SÝSTEMLERÝ MÜHENDÝSLÝÐÝ
**							      PROGRAMLAMAYA GÝRÝÞ DERSÝ
**								    2017-2018 GÜZ DÖNEMÝ
**
**							ÖDEV NUMARASI..........: 5
**							ÖÐRENCÝ ADI............: Mustafa ACAR
**							ÖÐRENCÝ NUMARASI.......: b161200304
**                          DERSÝN ALINDIÐI GRUP...: A
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Oda_Islem
{
	string Oda_Numarasi;
	string Oda_Ucret;
}odabilgisi;

struct Musteri_Islem
{
	string Musteri_Numarasi;
	string Musteri_Adi;
	string Musteri_Soyadi;
	string Musteri_TC;
}musteribilgisi;

//Main'deki ana menünün switch yanýt giriþidir.
int secim;
//Main'deki ara menünün switch yanýt giriþidir.
int secim2;
string odanumarasi;
string musterinumarasi;
string dosyadancek;
//Dosyadan istenmeyen veriler buraya atýlýr.
string gecici;
bool bayrak = true;

void Menu()
{
	cout << "Otel Ýþlemleri" << endl;
	cout << "--------------------" << endl;
	cout << "1-Oda Ýþlemleri" << endl;
	cout << "2-Müþteri Ýþlemleri" << endl;
	cout << "3-Oda Kayýt Ýþlemleri" << endl;
	cout << "99-Çýkýþ" << endl;
	cout << "Seçiminiz: ";
	cin >> secim;
}

void Oda_Menu()
{
	cout << "Oda Ýþlemleri" << endl;
	cout << "--------------------" << endl;
	cout << "1-Oda Ekle" << endl;
	cout << "2-Oda Sil" << endl;
	cout << "3-Odalarý Listele" << endl;
	cout << "99-Üst Menü" << endl;
	cout << "Seçiminiz: ";
	cin >> secim2;
}

void Musteri_Menu()
{
	cout << "Müþteri Ýþlemleri" << endl;
	cout << "--------------------" << endl;
	cout << "1-Müþteri Ekle" << endl;
	cout << "2-Müþteri Sil" << endl;
	cout << "3-Müþteri Listele" << endl;
	cout << "99-Üst Menü" << endl;
	cout << "Seçiminiz: ";
	cin >> secim2;
}

void Kayit_Menu()
{
	cout << "Oda Kayýt Ýþlemleri" << endl;
	cout << "--------------------" << endl;
	cout << "1-Odaya Müþteri Ekle" << endl;
	cout << "2-Odadan Müþteri Sil" << endl;
	cout << "3-Oda Kayýtlarý Listele" << endl;
	cout << "99-Üst Menü" << endl;
	cout << "Seçiminiz: ";
	cin >> secim2;
}

void Oda_Ekle()
{
	cout << "Oda Numarasý: "; cin >> odabilgisi.Oda_Numarasi;
	// Eklenecek odayý "Oda.txt" içerisinde arar. Mevcut oda varsa iþlem yapmaz.
	ifstream DosyaOku("Oda.txt", ios::app);
	while (!DosyaOku.eof())
	{
		DosyaOku >> gecici >> dosyadancek >> gecici >> gecici;
		if (dosyadancek == odabilgisi.Oda_Numarasi)
		{
			cout << "Otelde Bu Oda Zaten Mevcut." << endl;
			DosyaOku.close();
			return;
		}
	}
	DosyaOku.close();
	cout << "Oda Ücreti: "; cin >> odabilgisi.Oda_Ucret;
	// Burada sayý harici giriþ kontrolü yapýyor.
	for (int i = 0; i < odabilgisi.Oda_Ucret.length(); i++)
	{
		if ((int)odabilgisi.Oda_Ucret[i] < 44 || (int)odabilgisi.Oda_Ucret[i] > 57 || (int)odabilgisi.Oda_Ucret[i] == 47 || (int)odabilgisi.Oda_Ucret[i] == 45)
		{
			cout << "Oda Ücretinde Harf veya Karakter Kullanýldý.";
			return;
		}
	}
	ofstream DosyaYaz("Oda.txt", ios::app);
	//Sola Yaslama
	DosyaYaz.setf(ios::left);
	DosyaYaz << "Oda_Numarasý: " << odabilgisi.Oda_Numarasi << endl << "Oda_Ücreti: " << odabilgisi.Oda_Ucret << endl << endl;
	cout << "Otele Oda Eklendi." << endl;
	DosyaYaz.close();
}

void Oda_Sil()
{
	bayrak = false;
	//EVET - HAYIR
	char E_H;
	string silinecek;
	//Kayýt dosyasýnda oda numarasý kayýtlý mý?
	ifstream KayitOku("Kayit.txt", ios::app);
	//Silinecek oda hariç temp dosyasýna atar.
	ifstream KayitOku2("Kayit.txt", ios::app);
	//Oda var mý sorusunun yanýtýný verir.
	ifstream OdaOku("Oda.txt");
	//Oda kaydýný silmek için.
	ifstream OdaOku2("Oda.txt");
	//Oda kaydýný silmek için kayýt ile.
	ifstream OdaOku3("Oda.txt");
	ofstream OdaYaz("Oda.tmp", ios::app);
	ofstream KayitYaz("Kayit.tmp", ios::app);
	cout << "Silinecek Oda Numarasýný Giriniz: "; cin >> silinecek;
	//Oda kontrolü.
	while (!OdaOku.eof())
	{
		OdaOku >> gecici >> odabilgisi.Oda_Numarasi >> gecici >> gecici;
		if (silinecek == odabilgisi.Oda_Numarasi)
		{
			bayrak = true;
		}
	}
	if (bayrak == false)
	{
		cout << "Oda Bulunmamaktadýr." << endl;
		KayitOku.close(); KayitOku2.close(); OdaOku.close(); OdaOku2.close(); OdaYaz.close(); KayitYaz.close(); remove("Kayit.tmp"); remove("Oda.tmp");
		return;
	}
	bayrak = false;
	//Kayýt dosyasýnda oda var mý?
	while (!KayitOku.eof())
	{
		KayitOku >> gecici >> odabilgisi.Oda_Numarasi >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici;
		if (odabilgisi.Oda_Numarasi == silinecek)
		{
			if (KayitOku.eof())
			{
				KayitOku.close(); break;
			}
			bayrak = true;
			break;
		}
	}
	//Kayýt dosyasýnda kayýt varsa buraya gir.
	if (bayrak)
	{
		bayrak = false;
		cout << "Silmek Ýstediðiniz Odada Müþteri Kaydý Mevcut." << endl
			<< "Odayý Silmek Ýstiðinize Emin misiniz ? (Evet için 'e' veya 'E'yi, Hayýr Ýçin 'h' veya 'H'yi Seçin)" << endl
			<< "Seçiminiz: "; cin >> E_H;
		if (E_H == 'e' || E_H == 'E')
		{
			//Önce oda.txt den odayý siliyor.
			while (!OdaOku3.eof())
			{
				OdaOku3 >> gecici >> odabilgisi.Oda_Numarasi >> gecici >> odabilgisi.Oda_Ucret;
				if (odabilgisi.Oda_Numarasi == silinecek)
					bayrak = true;
				else
				{
					if (OdaOku3.eof())
					{
						OdaOku3.close(); break;
					}
					OdaYaz << "Oda_Numarasý: " << odabilgisi.Oda_Numarasi << endl << "Oda_Ücreti: " << odabilgisi.Oda_Ucret << endl << endl;
				}
			}
			if (bayrak) { cout << silinecek << " Numaralý Oda Silindi." << endl; }
			bayrak = false;
			//Kayýt.txt içerisinde silincek olan haricindekileri tempe atar.
			while (!KayitOku2.eof())
			{
				KayitOku2 >> gecici >> odabilgisi.Oda_Numarasi >> gecici >> musteribilgisi.Musteri_Numarasi >> gecici >> musteribilgisi.Musteri_Adi
					>> gecici >> musteribilgisi.Musteri_Soyadi >> gecici >> musteribilgisi.Musteri_TC;
				if (odabilgisi.Oda_Numarasi == silinecek)
					bayrak = true;
				else
				{
					if (KayitOku2.eof())
					{
						KayitOku2.close(); break;
					}
					KayitYaz << "Oda_Numarasý: " << odabilgisi.Oda_Numarasi << endl << "Müþteri_Numarasý: " << musteribilgisi.Musteri_Numarasi << endl
						<< "Müþteri_Adý: " << musteribilgisi.Musteri_Adi << endl << "Müþteri_Soyadý: " << musteribilgisi.Musteri_Soyadi << endl
						<< "Müþteri_TC_Numarasý: " << musteribilgisi.Musteri_TC << endl << endl;
				}
			}
			if (bayrak) { cout << silinecek << " Numaralý Odadaki Müþteri Kaydý Silindi." << endl; }
		}
		KayitOku.close(); KayitOku2.close(); OdaOku.close(); OdaOku2.close(); OdaOku3.close(); OdaYaz.close(); KayitYaz.close();
		remove("Oda.txt"); rename("Oda.tmp", "Oda.txt"); remove("Kayit.txt"); rename("Kayit.tmp", "Kayit.txt");
		return;
	}
	////Kayýt dosyasýnda kayýt yoksa buraya gir.
	else
	{
		while (!OdaOku2.eof())
		{
			OdaOku2 >> gecici >> odabilgisi.Oda_Numarasi >> gecici >> odabilgisi.Oda_Ucret;
			if (odabilgisi.Oda_Numarasi == silinecek)
			{
				if (OdaOku2.eof())
				{
					OdaOku2.close(); break;
				}
				bayrak = true;
			}
			else
			{
				if (OdaOku2.eof())
				{
					OdaOku2.close(); break;
				}
				OdaYaz << "Oda_Numarasý: " << odabilgisi.Oda_Numarasi << endl << "Oda_Ücreti: " << odabilgisi.Oda_Ucret << endl << endl;
			}
		}
		if (bayrak)
			cout << silinecek << " Numaralý Oda Silindi." << endl;
	}
	KayitOku.close(); KayitOku2.close(); OdaOku.close(); OdaOku2.close(); OdaOku3.close(); OdaYaz.close(); KayitYaz.close();
	remove("Oda.txt"); rename("Oda.tmp", "Oda.txt");
}

void Oda_Listele()
{
	ifstream DosyaOku("Oda.txt", ios::app);
	system("CLS");
	cout << "Oteldeki Mevcut Oda Listesi: " << endl;
	while (!DosyaOku.eof())
	{
		DosyaOku.setf(ios::left);
		DosyaOku >> odabilgisi.Oda_Numarasi >> odabilgisi.Oda_Numarasi >> odabilgisi.Oda_Ucret >> odabilgisi.Oda_Ucret;
		if (DosyaOku.eof())
		{
			DosyaOku.close(); return;
		}
		cout << "Oda Numarasý: " << setw(30) << left << odabilgisi.Oda_Numarasi << "	Oda Ücreti: " << left << odabilgisi.Oda_Ucret << endl;
	}
}

void Musteri_Ekle()
{
	cout << "Müþteri Numarasý: "; cin >> musteribilgisi.Musteri_Numarasi;
	ifstream DosyaOku("Musteri.txt", ios::app);
	//Müþteri numarasý var mý yok mu?
	while (!DosyaOku.eof())
	{
		DosyaOku >> dosyadancek >> dosyadancek;
		if (dosyadancek == musteribilgisi.Musteri_Numarasi)
		{
			cout << "Otelde Bu Müþteri Zaten Bulunmaktadýr." << endl;
			DosyaOku.close();
			return;
		}
	}
	cout << "Müþteri Adý: "; cin >> musteribilgisi.Musteri_Adi;
	cout << "Müþteri Soyadý: "; cin >> musteribilgisi.Musteri_Soyadi;
	cout << "Müþteri TC Numarasý: "; cin >> musteribilgisi.Musteri_TC;
	if (musteribilgisi.Musteri_TC.length() != 11)
	{
		cout << "TC Numarasý 11 Haneli Olmalýdýr.";
		return;
	}
	//Harf hariç kontrol yapar.
	for (int i = 0; i < 11; i++)
	{
		if ((int)musteribilgisi.Musteri_TC[i] < 48 || (int)musteribilgisi.Musteri_TC[i] > 57)
		{
			cout << "TC Numarasýnda Harf veya Karakter Kullanýldý.";
			return;
		}
	}
	ofstream DosyaYaz("Musteri.txt", ios::app);
	DosyaYaz << "Müþteri_Numarasý: " << musteribilgisi.Musteri_Numarasi << endl
		<< "Müþteri_Adý: " << musteribilgisi.Musteri_Adi << endl
		<< "Müþteri_Soyadý: " << musteribilgisi.Musteri_Soyadi << endl
		<< "Müþteri_TC_Numarasý: " << musteribilgisi.Musteri_TC << endl << endl;
	cout << "Otele Müþteri Eklendi." << endl;
	DosyaYaz.close();
}

void Musteri_Sil()
{
	bayrak = true;
	string silinecek;
	//Müþteri var mý yok mu?
	ifstream MusteriOku("Musteri.txt");
	ofstream MusteriYaz("Musteri.tmp", ios::app);
	//Silinen hariç diðer verileri okur.
	ifstream KayitOku("Kayit.txt");
	ofstream KayitYaz("Kayit.tmp", ios::app);
	//Silinen harici diðer verileri okur.
	ifstream Musteri_Oku("Musteri.txt");
	cout << "Silinecek Müþteri Numarasýný Giriniz: "; cin >> silinecek;
	//Müþteri var mý yok mu?
	while (!MusteriOku.eof())
	{
		MusteriOku >> gecici >> musteribilgisi.Musteri_Numarasi >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici;
		if (silinecek == musteribilgisi.Musteri_Numarasi)
		{
			bayrak = false;
		}
	}
	if (bayrak)
	{
		cout << "Böyle Bir Müþteri Kaydý Bulunmamaktadýr." << endl; 
		MusteriOku.close(); Musteri_Oku.close(); MusteriYaz.close(); KayitOku.close(); KayitYaz.close();
		remove("Musteri.tmp"); remove("Kayit.tmp");
		return;
	}
	else
	{
		//Silinen harici oku ve yaz. müþteri.txt
		while (!Musteri_Oku.eof())
		{
			Musteri_Oku >> musteribilgisi.Musteri_Numarasi >> musteribilgisi.Musteri_Numarasi >> musteribilgisi.Musteri_Adi >> musteribilgisi.Musteri_Adi
				>> musteribilgisi.Musteri_Soyadi >> musteribilgisi.Musteri_Soyadi >> musteribilgisi.Musteri_TC >> musteribilgisi.Musteri_TC;
			if (musteribilgisi.Musteri_Numarasi == silinecek)
			{
				bayrak = true;
			}
			else
			{
				if (Musteri_Oku.eof())
				{
					Musteri_Oku.close(); break;
				}
				MusteriYaz << "Müþteri_Numarasý: " << musteribilgisi.Musteri_Numarasi << endl
					<< "Müþteri_Adý: " << musteribilgisi.Musteri_Adi << endl
					<< "Müþteri_Soyadý: " << musteribilgisi.Musteri_Soyadi << endl
					<< "Müþteri_TC_Numarasý: " << musteribilgisi.Musteri_TC << endl << endl;
			}
		}
		if (bayrak)
			cout << silinecek << " Numaralý Müþteri Silindi." << endl;
		bayrak = false;
		//kayit.txt dosyasýnda silinen müþteri odaya kayýtlý mý?
		while (!KayitOku.eof())
		{
			KayitOku >> gecici >> odabilgisi.Oda_Numarasi >> gecici >> musteribilgisi.Musteri_Numarasi >> gecici >> musteribilgisi.Musteri_Adi
				>> gecici >> musteribilgisi.Musteri_Soyadi >> gecici >> musteribilgisi.Musteri_TC;
			if (musteribilgisi.Musteri_Numarasi == silinecek)
			{
				if (KayitOku.eof())
				{
					KayitOku.close(); break;
				}
				bayrak = true;
			}
			else
			{
				if (KayitOku.eof())
				{
					KayitOku.close(); break;
				}
				KayitYaz << "Oda_Numarasý: " << odabilgisi.Oda_Numarasi << endl
					<< "Müþteri_Numarasý: " << musteribilgisi.Musteri_Numarasi << endl
					<< "Müþteri_Adý: " << musteribilgisi.Musteri_Adi << endl
					<< "Müþteri_Soyadý: " << musteribilgisi.Musteri_Soyadi << endl
					<< "Müþteri_TC_Numarasý: " << musteribilgisi.Musteri_TC << endl << endl;
			}
		}
		if (bayrak)
			cout << silinecek << " Numaralý Müþterinin Oda Kaydý Silindi." << endl;
	}
	MusteriOku.close(); Musteri_Oku.close(); MusteriYaz.close(); KayitOku.close(); KayitYaz.close();
	remove("Musteri.txt"); rename("Musteri.tmp", "Musteri.txt"); remove("Kayit.txt"); rename("Kayit.tmp", "Kayit.txt");
}

void Musteri_Listele()
{
	ifstream DosyaOku("Musteri.txt", ios::app);
	system("CLS");
	cout << "Oteldeki Mevcut Müþteri Listesi: " << endl;
	while (!DosyaOku.eof())
	{
		DosyaOku.setf(ios::left);
		DosyaOku >> musteribilgisi.Musteri_Numarasi >> musteribilgisi.Musteri_Numarasi >> musteribilgisi.Musteri_Adi >> musteribilgisi.Musteri_Adi
			>> musteribilgisi.Musteri_Soyadi >> musteribilgisi.Musteri_Soyadi >> musteribilgisi.Musteri_TC >> musteribilgisi.Musteri_TC;
		if (DosyaOku.eof())
		{
			DosyaOku.close(); return;
		}
		cout << "Müþteri Numarasý: " << setw(25) << left << musteribilgisi.Musteri_Numarasi << "	Müþteri Adý: " << setw(25) << left << musteribilgisi.Musteri_Adi;
		cout << "	Müþteri Soyadý: " << setw(25) << left << musteribilgisi.Musteri_Soyadi << "	Müþteri TC Numarasý: " << left << musteribilgisi.Musteri_TC << endl;
	}
}

void Odaya_Musteri_Ekle()
{
	bayrak = true;
	cout << "Kayýt Yapýlacak Oda Numarasý: ";
	cin >> odanumarasi;
	ifstream MusteriOku("Musteri.txt", ios::app);
	ifstream OdaOku("Oda.txt", ios::app);
	cout << "Kaydý Yapýlacak Müþteri Numarasý: ";
	cin >> musterinumarasi;
	while (!MusteriOku.eof())
	{
		MusteriOku >> gecici >> dosyadancek >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici;
		if (dosyadancek == musterinumarasi)
		{
			bayrak = false; break;
		}
	}
	if (bayrak)
	{
		cout << "Müþteri Numarasý Mevcut Deðil" << endl;
		MusteriOku.close();
		return;
	}
	bayrak = true;
	ifstream KayitOku("Kayit.txt", ios::app);
	while (!KayitOku.eof())
	{
		KayitOku >> gecici >> dosyadancek >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici;
		if (dosyadancek == odanumarasi)
		{
			cout << "Bu Odada Müþteri Bulunmaktadýr." << endl;
			KayitOku.close();
			return;
		}
	}
	KayitOku.close();
	bayrak = false;
	while (!OdaOku.eof())
	{
		OdaOku >> gecici >> dosyadancek >> gecici >> gecici;
		if (dosyadancek == odanumarasi)
		{
			ifstream Musteri_Oku("Musteri.txt");
			ofstream KayitYaz("Kayit.txt", ios::app);
			while (!Musteri_Oku.eof())
			{
				Musteri_Oku >> gecici >> musteribilgisi.Musteri_Numarasi >> gecici >> musteribilgisi.Musteri_Adi >> gecici
					>> musteribilgisi.Musteri_Soyadi >> gecici >> musteribilgisi.Musteri_TC;
				if (musteribilgisi.Musteri_Numarasi == musterinumarasi)
				{
					bayrak = true;
					break;
				}
			}
			KayitYaz << "Oda_Numarasý: " << odanumarasi << endl << "Müþteri_Numarasý: " << musterinumarasi << endl << "Müþteri_Adý: " << musteribilgisi.Musteri_Adi
				<< endl << "Müþteri_Soyadi: " << musteribilgisi.Musteri_Soyadi << endl << "Müþteri_TC_Numarasý: " << musteribilgisi.Musteri_TC << endl << endl;
			OdaOku.close(); MusteriOku.close(); KayitYaz.close(); Musteri_Oku.close();
			KayitYaz.close();
			Musteri_Oku.close();
			if (bayrak) cout << odanumarasi << " Numaralý Odaya " << musterinumarasi << " Numaralý Müþteri Eklendi." << endl;
			bayrak = false;
			break;
		}
	}
	if (bayrak)
		cout << "Oda Numarasý Bulunamadý." << endl;
	OdaOku.close(); MusteriOku.close();
}

void Odadan_Musteri_Sil()
{
	bayrak = true;
	string silinecek;
	ifstream KayitOku("Kayit.txt");
	ifstream Kayit_Oku("Kayit.txt");
	ofstream KayitYaz("Kayit.tmp", ios::app);
	cout << "Silinecek Kaydýn Oda Numarasýný Giriniz: "; cin >> silinecek;
	//Odada müþteri kaydý varmý yokmu kontrolü yapýyor
	while (!KayitOku.eof())
	{
		KayitOku >> gecici >> odabilgisi.Oda_Numarasi >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici >> gecici;
		if (silinecek == odabilgisi.Oda_Numarasi)
		{
			if (KayitOku.eof())
			{
				KayitOku.close(); break;
			}
			bayrak = false;
		}
	}
	//Odada müþteri kaydý yoksa
	if (bayrak)
	{
		cout << "Odada Müþteri Kaydý Bulunmamaktadýr." << endl;
	}
	//Odada müþteri kaydý varsa
	else
	{
		while (!Kayit_Oku.eof())
		{
			Kayit_Oku >> gecici >> odabilgisi.Oda_Numarasi >> gecici >> musteribilgisi.Musteri_Numarasi >> gecici >> musteribilgisi.Musteri_Adi
				>> gecici >> musteribilgisi.Musteri_Soyadi >> gecici >> musteribilgisi.Musteri_TC;
			if (odabilgisi.Oda_Numarasi == silinecek)
			{
				if (Kayit_Oku.eof())
				{
					Kayit_Oku.close(); break;
				}
				bayrak = true;
			}
			else
			{
				if (Kayit_Oku.eof())
				{
					Kayit_Oku.close(); break;
				}
				KayitYaz << "Oda_Numarasý: " << odabilgisi.Oda_Numarasi << endl
					<< "Müþteri_Numarasý: " << musteribilgisi.Musteri_Numarasi << endl
					<< "Müþteri_Adý: " << musteribilgisi.Musteri_Adi << endl
					<< "Müþteri_Soyadý: " << musteribilgisi.Musteri_Soyadi << endl
					<< "Müþteri_TC_Numarasý: " << musteribilgisi.Musteri_TC << endl << endl;
			}
		}
		if (bayrak)
		{
			cout << silinecek << " Numaralý Oda Kaydý Silindi." << endl;
		}
	}
	KayitOku.close(); Kayit_Oku.close();  KayitYaz.close(); remove("Kayit.txt"); rename("Kayit.tmp", "Kayit.txt");
}

void Oda_Kayitlarini_Listele()
{
	ifstream DosyaOku("Kayit.txt", ios::app);
	system("CLS");
	cout << "Odalara Kayýtlý Müþterilerin Listesi: " << endl;
	while (!DosyaOku.eof())
	{
		DosyaOku.setf(ios::left);
		DosyaOku >> odabilgisi.Oda_Numarasi >> odabilgisi.Oda_Numarasi >> musteribilgisi.Musteri_Numarasi
			>> musteribilgisi.Musteri_Numarasi >> musteribilgisi.Musteri_Adi >> musteribilgisi.Musteri_Adi
			>> musteribilgisi.Musteri_Soyadi >> musteribilgisi.Musteri_Soyadi >> musteribilgisi.Musteri_TC >> musteribilgisi.Musteri_TC;
		if (DosyaOku.eof())
		{
			DosyaOku.close(); return;
		}
		cout << "Oda Numarasý: " << setw(15) << left << odabilgisi.Oda_Numarasi << "	Müþteri Numarasý: " << setw(15) << left << musteribilgisi.Musteri_Numarasi
			<< "	Müþteri Adý: " << setw(15) << left << musteribilgisi.Musteri_Adi << "	Müþteri Soyadý: " << setw(15) << left << musteribilgisi.Musteri_Soyadi
			<< "	Müþteri TC Numarasý: " << left << musteribilgisi.Musteri_TC << endl;
	}
	DosyaOku.close();
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	do
	{
		system("CLS");
		Menu();
		switch (secim)
		{
		case 1:
			do
			{
				system("CLS");
				Oda_Menu();
				switch (secim2)
				{
				case 1:
					system("CLS");
					Oda_Ekle();
					break;
				case 2:
					system("CLS");
					Oda_Sil();
					break;
				case 3:
					system("CLS");
					Oda_Listele();
					break;
				case 99:
					system("CLS"); break;
				default: cout << "Hatalý Seçim Yaptýnýz."; break;
				}
				if (!(secim2 == 99))
				{
					cout << endl << "Devam Etmek Ýçin Bir Tuþa Basýnýz...";
					_getch();
				}
			} while (!(secim2 == 99));
			break;
		case 2:
			do
			{
				system("CLS");
				Musteri_Menu();
				switch (secim2)
				{
				case 1:
					system("CLS");
					Musteri_Ekle();
					break;
				case 2:
					system("CLS");
					Musteri_Sil();
					break;
				case 3:
					system("CLS");
					Musteri_Listele();
					break;
				case 99:
					system("CLS"); break;
				default: cout << "Hatalý Seçim Yaptýnýz."; break;
				}
				if (!(secim2 == 99))
				{
					cout << endl << "Devam Etmek Ýçin Bir Tuþa Basýnýz...";
					_getch();
				}
			} while (!(secim2 == 99));
			break;
		case 3:
			do
			{
				system("CLS");
				Kayit_Menu();
				switch (secim2)
				{
				case 1:
					system("CLS");
					Odaya_Musteri_Ekle();
					break;
				case 2:
					system("CLS");
					Odadan_Musteri_Sil();
					break;
				case 3:
					system("CLS");
					Oda_Kayitlarini_Listele();
					break;
				case 99:
					system("CLS");
					break;
				default: cout << "Hatalý Seçim Yaptýnýz.";
					break;
				}
				if (!(secim2 == 99))
				{
					cout << endl << "Devam Etmek Ýçin Bir Tuþa Basýnýz...";
					_getch();
				}
			} while (!(secim2 == 99));
			break;
		case 99:
			system("CLS");
			break;
		default:
			cout << "Hatalý Seçim Yaptýnýz.";
			break;
		}
		if (!(secim == 99) && !(secim2 == 99))
		{
			cout << endl << "Devam Etmek Ýçin Bir Tuþa Basýnýz...";
			_getch();
		}
	} while (!(secim == 99));
	return 0;
}