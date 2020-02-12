// PG22-CokBoyutluDizi2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	int yaslar[4][3][3][2];
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << " sýnýf: " << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << j + 1 << " öðretim türü: " << endl;
			char karakter = 'A';
			for (int k = 0; k < 3; k++)
			{
				karakter += k;
				cout << (karakter) << " sýnýfý: " << endl;
				for (int l = 0; l < 2; l++) {
					cout << l + 1 << " öðrencinin yaþý: ";
					cin >> yaslar[i][j][k][l];
				}
			}
		}
	}

	system("PAUSE");
	return 0;
}

