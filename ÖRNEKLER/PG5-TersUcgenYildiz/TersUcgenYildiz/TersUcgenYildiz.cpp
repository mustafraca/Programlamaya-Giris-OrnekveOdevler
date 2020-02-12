// TersUcgenYildiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Ters Üçgen Çizimi
	int yildiz = 7, bosluk = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < bosluk; j++)
			cout << " ";
		for (int j = 0; j < yildiz; j++)
			cout << "*";
		cout << "\n";
		bosluk++;
		yildiz -= 2;
	}

	system("PAUSE");
	return 0;
}

