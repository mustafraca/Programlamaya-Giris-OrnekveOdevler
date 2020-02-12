// PG30-ClassTanýmlamasý.cpp : Defines the entry point for the console application.
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
	cout << "Arabanýn Markasý: " << araba.marka << endl;
	cout << "Arabanýn Modeli: " << araba.model << endl;

    return 0;
}

