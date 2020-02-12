#include "stdafx.h"
#include <iostream>
#include <string>
#include "Kisi.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	Kisi kisi("Mustafa", "Acar", 20);
	kisi.BilgiGir();
	cout << "---------------" << endl;
	kisi.BilgiYaz();

	system("PAUSE");
    return 0;
}

