// PG10-Karekok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	double X, a, e, b, y;
	cout << "Karekökü bulunacak sayý: ";
	cin >> X;
	cout << "Bu sayýya en yakýn karekökünü bildiðiniz bir sayý girin: ";
	cin >> a;
	cout << "Kabul edebileceðiniz hata oraný: ";
	cin >> e;
	do
	{
		b = (X - a*a) / (2 * a);
		y = a;
		a += b;
	} while (abs(b) > e);
	cout << X << "'in karekökü: " << y << endl;

	system("PAUSE");
    return 0;
}

