// PG30-ClassTan�mlamas�.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Araba.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	Araba araba;
	araba.marka = "Toyota";
	araba.model = "Corolla";
	cout << "Araban�n Markas�: " << araba.marka << endl;
	cout << "Araban�n Modeli: " << araba.model << endl;

    return 0;
}

