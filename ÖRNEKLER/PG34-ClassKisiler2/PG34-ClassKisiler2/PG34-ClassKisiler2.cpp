#include "stdafx.h"
#include <iostream>
#include <string>
#include "Kisi.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	Kisi kisi1("Mustafa");
	kisi1.KisiSayisi();
	Kisi kisi2(21);
	kisi2.KisiSayisi();
	Kisi kisi3("Mustafa", "Acar", 21);
	kisi3.KisiSayisi();

	system("PAUSE");
    return 0;
}

