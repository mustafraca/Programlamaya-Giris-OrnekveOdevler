// PG1-GectiKaldi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int vize, finali;
	cout << "Vize ve Final notunu giriniz: ";
	cin >> vize >> finali;
	if ((vize + finali) / 2 >= 50) cout << "Geçti" << endl;
	else cout << "Kaldý" << endl;

	system("PAUSE");
	return 0;
}

