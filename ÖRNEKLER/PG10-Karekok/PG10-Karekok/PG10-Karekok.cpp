// PG10-Karekok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	double X, a, e, b, y;
	cout << "Karek�k� bulunacak say�: ";
	cin >> X;
	cout << "Bu say�ya en yak�n karek�k�n� bildi�iniz bir say� girin: ";
	cin >> a;
	cout << "Kabul edebilece�iniz hata oran�: ";
	cin >> e;
	do
	{
		b = (X - a*a) / (2 * a);
		y = a;
		a += b;
	} while (abs(b) > e);
	cout << X << "'in karek�k�: " << y << endl;

	system("PAUSE");
    return 0;
}

