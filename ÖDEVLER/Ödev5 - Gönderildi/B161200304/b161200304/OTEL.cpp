/****************************************************************************
**								   SAKARYA �N�VERS�TES�
**							B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**								B�L���M S�STEMLER� M�HEND�SL���
**							      PROGRAMLAMAYA G�R�� DERS�
**								    2017-2018 G�Z D�NEM�
**
**							�DEV NUMARASI..........: 5
**							��RENC� ADI............: Mustafa ACAR
**							��RENC� NUMARASI.......: b161200304
**                          DERS�N ALINDI�I GRUP...: A
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

//Main'deki ana men�n�n switch yan�t giri�idir.
int secim;
//Main'deki ara men�n�n switch yan�t giri�idir.
int secim2;
string odanumarasi;
string musterinumarasi;
string dosyadancek;
//Dosyadan istenmeyen veriler buraya at�l�r.
string gecici;
bool bayrak = true;

void Menu()
{
	cout << "Otel ��lemleri" << endl;
	cout << "--------------------" << endl;
	cout << "1-Oda ��lemleri" << endl;
	cout << "2-M��teri ��lemleri" << endl;
	cout << "3-Oda Kay�t ��lemleri" << endl;
	cout << "99-��k��" << endl;
	cout << "Se�iminiz: ";
	cin >> secim;
}

void Oda_Menu()
{
	cout << "Oda ��lemleri" << endl;
	cout << "--------------------" << endl;
	cout << "1-Oda Ekle" << endl;
	cout << "2-Oda Sil" << endl;
	cout << "3-Odalar� Listele" << endl;
	cout << "99-�st Men�" << endl;
	cout << "Se�iminiz: ";
	cin >> secim2;
}

void Musteri_Menu()
{
	cout << "M��teri ��lemleri" << endl;
	cout << "--------------------" << endl;
	cout << "1-M��teri Ekle" << endl;
	cout << "2-M��teri Sil" << endl;
	cout << "3-M��teri Listele" << endl;
	cout << "99-�st Men�" << endl;
	cout << "Se�iminiz: ";
	cin >> secim2;
}

void Kayit_Menu()
{
	cout << "Oda Kay�t ��lemleri" << endl;
	cout << "--------------------" << endl;
	cout << "1-Odaya M��teri Ekle" << endl;
	cout << "2-Odadan M��teri Sil" << endl;
	cout << "3-Oda Kay�tlar� Listele" << endl;
	cout << "99-�st Men�" << endl;
	cout << "Se�iminiz: ";
	cin >> secim2;
}

void Oda_Ekle()
{
	cout << "Oda Numaras�: "; cin >> odabilgisi.Oda_Numarasi;
	// Eklenecek oday� "Oda.txt" i�erisinde arar. Mevcut oda varsa i�lem yapmaz.
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
	cout << "Oda �creti: "; cin >> odabilgisi.Oda_Ucret;
	// Burada say� harici giri� kontrol� yap�yor.
	for (int i = 0; i < odabilgisi.Oda_Ucret.length(); i++)
	{
		if ((int)odabilgisi.Oda_Ucret[i] < 44 || (int)odabilgisi.Oda_Ucret[i] > 57 || (int)odabilgisi.Oda_Ucret[i] == 47 || (int)odabilgisi.Oda_Ucret[i] == 45)
		{
			cout << "Oda �cretinde Harf veya Karakter Kullan�ld�.";
			return;
		}
	}
	ofstream DosyaYaz("Oda.txt", ios::app);
	//Sola Yaslama
	DosyaYaz.setf(ios::left);
	DosyaYaz << "Oda_Numaras�: " << odabilgisi.Oda_Numarasi << endl << "Oda_�creti: " << odabilgisi.Oda_Ucret << endl << endl;
	cout << "Otele Oda Eklendi." << endl;
	DosyaYaz.close();
}

void Oda_Sil()
{
	bayrak = false;
	//EVET - HAYIR
	char E_H;
	string silinecek;
	//Kay�t dosyas�nda oda numaras� kay�tl� m�?
	ifstream KayitOku("Kayit.txt", ios::app);
	//Silinecek oda hari� temp dosyas�na atar.
	ifstream KayitOku2("Kayit.txt", ios::app);
	//Oda var m� sorusunun yan�t�n� verir.
	ifstream OdaOku("Oda.txt");
	//Oda kayd�n� silmek i�in.
	ifstream OdaOku2("Oda.txt");
	//Oda kayd�n� silmek i�in kay�t ile.
	ifstream OdaOku3("Oda.txt");
	ofstream OdaYaz("Oda.tmp", ios::app);
	ofstream KayitYaz("Kayit.tmp", ios::app);
	cout << "Silinecek Oda Numaras�n� Giriniz: "; cin >> silinecek;
	//Oda kontrol�.
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
		cout << "Oda Bulunmamaktad�r." << endl;
		KayitOku.close(); KayitOku2.close(); OdaOku.close(); OdaOku2.close(); OdaYaz.close(); KayitYaz.close(); remove("Kayit.tmp"); remove("Oda.tmp");
		return;
	}
	bayrak = false;
	//Kay�t dosyas�nda oda var m�?
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
	//Kay�t dosyas�nda kay�t varsa buraya gir.
	if (bayrak)
	{
		bayrak = false;
		cout << "Silmek �stedi�iniz Odada M��teri Kayd� Mevcut." << endl
			<< "Oday� Silmek �sti�inize Emin misiniz ? (Evet i�in 'e' veya 'E'yi, Hay�r ��in 'h' veya 'H'yi Se�in)" << endl
			<< "Se�iminiz: "; cin >> E_H;
		if (E_H == 'e' || E_H == 'E')
		{
			//�nce oda.txt den oday� siliyor.
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
					OdaYaz << "Oda_Numaras�: " << odabilgisi.Oda_Numarasi << endl << "Oda_�creti: " << odabilgisi.Oda_Ucret << endl << endl;
				}
			}
			if (bayrak) { cout << silinecek << " Numaral� Oda Silindi." << endl; }
			bayrak = false;
			//Kay�t.txt i�erisinde silincek olan haricindekileri tempe atar.
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
					KayitYaz << "Oda_Numaras�: " << odabilgisi.Oda_Numarasi << endl << "M��teri_Numaras�: " << musteribilgisi.Musteri_Numarasi << endl
						<< "M��teri_Ad�: " << musteribilgisi.Musteri_Adi << endl << "M��teri_Soyad�: " << musteribilgisi.Musteri_Soyadi << endl
						<< "M��teri_TC_Numaras�: " << musteribilgisi.Musteri_TC << endl << endl;
				}
			}
			if (bayrak) { cout << silinecek << " Numaral� Odadaki M��teri Kayd� Silindi." << endl; }
		}
		KayitOku.close(); KayitOku2.close(); OdaOku.close(); OdaOku2.close(); OdaOku3.close(); OdaYaz.close(); KayitYaz.close();
		remove("Oda.txt"); rename("Oda.tmp", "Oda.txt"); remove("Kayit.txt"); rename("Kayit.tmp", "Kayit.txt");
		return;
	}
	////Kay�t dosyas�nda kay�t yoksa buraya gir.
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
				OdaYaz << "Oda_Numaras�: " << odabilgisi.Oda_Numarasi << endl << "Oda_�creti: " << odabilgisi.Oda_Ucret << endl << endl;
			}
		}
		if (bayrak)
			cout << silinecek << " Numaral� Oda Silindi." << endl;
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
		cout << "Oda Numaras�: " << setw(30) << left << odabilgisi.Oda_Numarasi << "	Oda �creti: " << left << odabilgisi.Oda_Ucret << endl;
	}
}

void Musteri_Ekle()
{
	cout << "M��teri Numaras�: "; cin >> musteribilgisi.Musteri_Numarasi;
	ifstream DosyaOku("Musteri.txt", ios::app);
	//M��teri numaras� var m� yok mu?
	while (!DosyaOku.eof())
	{
		DosyaOku >> dosyadancek >> dosyadancek;
		if (dosyadancek == musteribilgisi.Musteri_Numarasi)
		{
			cout << "Otelde Bu M��teri Zaten Bulunmaktad�r." << endl;
			DosyaOku.close();
			return;
		}
	}
	cout << "M��teri Ad�: "; cin >> musteribilgisi.Musteri_Adi;
	cout << "M��teri Soyad�: "; cin >> musteribilgisi.Musteri_Soyadi;
	cout << "M��teri TC Numaras�: "; cin >> musteribilgisi.Musteri_TC;
	if (musteribilgisi.Musteri_TC.length() != 11)
	{
		cout << "TC Numaras� 11 Haneli Olmal�d�r.";
		return;
	}
	//Harf hari� kontrol yapar.
	for (int i = 0; i < 11; i++)
	{
		if ((int)musteribilgisi.Musteri_TC[i] < 48 || (int)musteribilgisi.Musteri_TC[i] > 57)
		{
			cout << "TC Numaras�nda Harf veya Karakter Kullan�ld�.";
			return;
		}
	}
	ofstream DosyaYaz("Musteri.txt", ios::app);
	DosyaYaz << "M��teri_Numaras�: " << musteribilgisi.Musteri_Numarasi << endl
		<< "M��teri_Ad�: " << musteribilgisi.Musteri_Adi << endl
		<< "M��teri_Soyad�: " << musteribilgisi.Musteri_Soyadi << endl
		<< "M��teri_TC_Numaras�: " << musteribilgisi.Musteri_TC << endl << endl;
	cout << "Otele M��teri Eklendi." << endl;
	DosyaYaz.close();
}

void Musteri_Sil()
{
	bayrak = true;
	string silinecek;
	//M��teri var m� yok mu?
	ifstream MusteriOku("Musteri.txt");
	ofstream MusteriYaz("Musteri.tmp", ios::app);
	//Silinen hari� di�er verileri okur.
	ifstream KayitOku("Kayit.txt");
	ofstream KayitYaz("Kayit.tmp", ios::app);
	//Silinen harici di�er verileri okur.
	ifstream Musteri_Oku("Musteri.txt");
	cout << "Silinecek M��teri Numaras�n� Giriniz: "; cin >> silinecek;
	//M��teri var m� yok mu?
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
		cout << "B�yle Bir M��teri Kayd� Bulunmamaktad�r." << endl; 
		MusteriOku.close(); Musteri_Oku.close(); MusteriYaz.close(); KayitOku.close(); KayitYaz.close();
		remove("Musteri.tmp"); remove("Kayit.tmp");
		return;
	}
	else
	{
		//Silinen harici oku ve yaz. m��teri.txt
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
				MusteriYaz << "M��teri_Numaras�: " << musteribilgisi.Musteri_Numarasi << endl
					<< "M��teri_Ad�: " << musteribilgisi.Musteri_Adi << endl
					<< "M��teri_Soyad�: " << musteribilgisi.Musteri_Soyadi << endl
					<< "M��teri_TC_Numaras�: " << musteribilgisi.Musteri_TC << endl << endl;
			}
		}
		if (bayrak)
			cout << silinecek << " Numaral� M��teri Silindi." << endl;
		bayrak = false;
		//kayit.txt dosyas�nda silinen m��teri odaya kay�tl� m�?
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
				KayitYaz << "Oda_Numaras�: " << odabilgisi.Oda_Numarasi << endl
					<< "M��teri_Numaras�: " << musteribilgisi.Musteri_Numarasi << endl
					<< "M��teri_Ad�: " << musteribilgisi.Musteri_Adi << endl
					<< "M��teri_Soyad�: " << musteribilgisi.Musteri_Soyadi << endl
					<< "M��teri_TC_Numaras�: " << musteribilgisi.Musteri_TC << endl << endl;
			}
		}
		if (bayrak)
			cout << silinecek << " Numaral� M��terinin Oda Kayd� Silindi." << endl;
	}
	MusteriOku.close(); Musteri_Oku.close(); MusteriYaz.close(); KayitOku.close(); KayitYaz.close();
	remove("Musteri.txt"); rename("Musteri.tmp", "Musteri.txt"); remove("Kayit.txt"); rename("Kayit.tmp", "Kayit.txt");
}

void Musteri_Listele()
{
	ifstream DosyaOku("Musteri.txt", ios::app);
	system("CLS");
	cout << "Oteldeki Mevcut M��teri Listesi: " << endl;
	while (!DosyaOku.eof())
	{
		DosyaOku.setf(ios::left);
		DosyaOku >> musteribilgisi.Musteri_Numarasi >> musteribilgisi.Musteri_Numarasi >> musteribilgisi.Musteri_Adi >> musteribilgisi.Musteri_Adi
			>> musteribilgisi.Musteri_Soyadi >> musteribilgisi.Musteri_Soyadi >> musteribilgisi.Musteri_TC >> musteribilgisi.Musteri_TC;
		if (DosyaOku.eof())
		{
			DosyaOku.close(); return;
		}
		cout << "M��teri Numaras�: " << setw(25) << left << musteribilgisi.Musteri_Numarasi << "	M��teri Ad�: " << setw(25) << left << musteribilgisi.Musteri_Adi;
		cout << "	M��teri Soyad�: " << setw(25) << left << musteribilgisi.Musteri_Soyadi << "	M��teri TC Numaras�: " << left << musteribilgisi.Musteri_TC << endl;
	}
}

void Odaya_Musteri_Ekle()
{
	bayrak = true;
	cout << "Kay�t Yap�lacak Oda Numaras�: ";
	cin >> odanumarasi;
	ifstream MusteriOku("Musteri.txt", ios::app);
	ifstream OdaOku("Oda.txt", ios::app);
	cout << "Kayd� Yap�lacak M��teri Numaras�: ";
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
		cout << "M��teri Numaras� Mevcut De�il" << endl;
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
			cout << "Bu Odada M��teri Bulunmaktad�r." << endl;
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
			KayitYaz << "Oda_Numaras�: " << odanumarasi << endl << "M��teri_Numaras�: " << musterinumarasi << endl << "M��teri_Ad�: " << musteribilgisi.Musteri_Adi
				<< endl << "M��teri_Soyadi: " << musteribilgisi.Musteri_Soyadi << endl << "M��teri_TC_Numaras�: " << musteribilgisi.Musteri_TC << endl << endl;
			OdaOku.close(); MusteriOku.close(); KayitYaz.close(); Musteri_Oku.close();
			KayitYaz.close();
			Musteri_Oku.close();
			if (bayrak) cout << odanumarasi << " Numaral� Odaya " << musterinumarasi << " Numaral� M��teri Eklendi." << endl;
			bayrak = false;
			break;
		}
	}
	if (bayrak)
		cout << "Oda Numaras� Bulunamad�." << endl;
	OdaOku.close(); MusteriOku.close();
}

void Odadan_Musteri_Sil()
{
	bayrak = true;
	string silinecek;
	ifstream KayitOku("Kayit.txt");
	ifstream Kayit_Oku("Kayit.txt");
	ofstream KayitYaz("Kayit.tmp", ios::app);
	cout << "Silinecek Kayd�n Oda Numaras�n� Giriniz: "; cin >> silinecek;
	//Odada m��teri kayd� varm� yokmu kontrol� yap�yor
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
	//Odada m��teri kayd� yoksa
	if (bayrak)
	{
		cout << "Odada M��teri Kayd� Bulunmamaktad�r." << endl;
	}
	//Odada m��teri kayd� varsa
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
				KayitYaz << "Oda_Numaras�: " << odabilgisi.Oda_Numarasi << endl
					<< "M��teri_Numaras�: " << musteribilgisi.Musteri_Numarasi << endl
					<< "M��teri_Ad�: " << musteribilgisi.Musteri_Adi << endl
					<< "M��teri_Soyad�: " << musteribilgisi.Musteri_Soyadi << endl
					<< "M��teri_TC_Numaras�: " << musteribilgisi.Musteri_TC << endl << endl;
			}
		}
		if (bayrak)
		{
			cout << silinecek << " Numaral� Oda Kayd� Silindi." << endl;
		}
	}
	KayitOku.close(); Kayit_Oku.close();  KayitYaz.close(); remove("Kayit.txt"); rename("Kayit.tmp", "Kayit.txt");
}

void Oda_Kayitlarini_Listele()
{
	ifstream DosyaOku("Kayit.txt", ios::app);
	system("CLS");
	cout << "Odalara Kay�tl� M��terilerin Listesi: " << endl;
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
		cout << "Oda Numaras�: " << setw(15) << left << odabilgisi.Oda_Numarasi << "	M��teri Numaras�: " << setw(15) << left << musteribilgisi.Musteri_Numarasi
			<< "	M��teri Ad�: " << setw(15) << left << musteribilgisi.Musteri_Adi << "	M��teri Soyad�: " << setw(15) << left << musteribilgisi.Musteri_Soyadi
			<< "	M��teri TC Numaras�: " << left << musteribilgisi.Musteri_TC << endl;
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
				default: cout << "Hatal� Se�im Yapt�n�z."; break;
				}
				if (!(secim2 == 99))
				{
					cout << endl << "Devam Etmek ��in Bir Tu�a Bas�n�z...";
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
				default: cout << "Hatal� Se�im Yapt�n�z."; break;
				}
				if (!(secim2 == 99))
				{
					cout << endl << "Devam Etmek ��in Bir Tu�a Bas�n�z...";
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
				default: cout << "Hatal� Se�im Yapt�n�z.";
					break;
				}
				if (!(secim2 == 99))
				{
					cout << endl << "Devam Etmek ��in Bir Tu�a Bas�n�z...";
					_getch();
				}
			} while (!(secim2 == 99));
			break;
		case 99:
			system("CLS");
			break;
		default:
			cout << "Hatal� Se�im Yapt�n�z.";
			break;
		}
		if (!(secim == 99) && !(secim2 == 99))
		{
			cout << endl << "Devam Etmek ��in Bir Tu�a Bas�n�z...";
			_getch();
		}
	} while (!(secim == 99));
	return 0;
}