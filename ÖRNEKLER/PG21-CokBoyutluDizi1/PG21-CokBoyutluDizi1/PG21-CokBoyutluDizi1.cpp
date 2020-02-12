// PG21-CokBoyutluDizi1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Turkish");

	char isim[5][4];
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ". öðrencinin ismi: ";
		cin >> isim[i];
	}
	for (int i = 0; i < 5; i++)
	{
		if (isim[i][0] == 'c')cout << isim[i] << endl;
	}

	system("PAUSE");
	return 0;
}

