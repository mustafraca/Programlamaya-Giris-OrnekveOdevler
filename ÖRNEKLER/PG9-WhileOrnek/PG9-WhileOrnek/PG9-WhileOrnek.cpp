// PG9-WhileOrnek.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int a, b;
	cout << "Birinci Sayý: ";
	cin >> a;
	cout << "Ýkinci Sayý: ";
	cin >> b;

	while (a != b)
		if (a > b) a -= b;
		else b -= a;
		cout << "EBOB: " << a << endl;

	system("PAUSE");
    return 0;
}

