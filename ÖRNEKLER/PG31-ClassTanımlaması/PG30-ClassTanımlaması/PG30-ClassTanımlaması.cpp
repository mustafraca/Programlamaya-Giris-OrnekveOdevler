// PG30-ClassTanımlaması.cpp : Defines the entry point for the console application.
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
	cout << "Arabanın Markası: " << araba.marka << endl;
	cout << "Arabanın Modeli: " << araba.model << endl;

    return 0;
}

