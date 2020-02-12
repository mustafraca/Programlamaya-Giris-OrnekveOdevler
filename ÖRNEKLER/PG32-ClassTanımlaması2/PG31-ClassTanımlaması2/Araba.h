#ifndef ARABA_H
#define ARABA_H
#include <iostream>
#include <string>
using namespace std;

class Araba
{
private:
	string marka;
	string model;
	int maxHiz;
	int hiz;
public:
	Araba(string marka, string model)
	{
		this->marka = marka;
		this->model = model;
		this->maxHiz = 220;
		hiz = 0;
	}
	Araba(string marka, string model, int maxHiz)
	{
		this->marka = marka;
		this->model = model;
		this->maxHiz = maxHiz;
		hiz = 0;
	}
	string getMarka() { return marka; }
	string getModel() { return model; }
	int getmaxHiz() { return maxHiz; }
	int getHiz() { return hiz; }
	void Hizlan(int ivme)
	{
		if (hiz + ivme > maxHiz)
		{
			hiz = maxHiz;
			throw 1;
		}
		hiz += ivme;
	}
	void Yavasla(int ivme)
	{
		if (hiz - ivme < 0)
		{
			hiz = 0;
			throw 2;
		}
		hiz -= ivme;
	}
};
#endif // !ARABA_H

