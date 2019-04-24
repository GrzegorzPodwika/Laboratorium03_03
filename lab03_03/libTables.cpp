#include "pch.h"
#include "libTables.h"
#include <cmath>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

int* createTable(int Tsize)
{
	int *T = nullptr;

	try
	{
		T = new int[Tsize];
	}
	catch (bad_alloc)
	{
		std::cout << "Nie udalo sie utworzyc tablicy!";
		std::cin.ignore();
		getchar();
		exit(0);
	}

	return T;
}

void showTable(int *tab, int Tsize)
{
	for (int i = 0; i < Tsize; i++)
	{
		cout << *tab << " ";
		tab++;
		//cout<<*(t+i);
	}
}

void fillTableRandomNumbers(int * tab, int Tsize)
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(-500, 500); //dist(pow(-2, 31), pow(2, 31)-1);

	for (int i = 0; i < Tsize; i++)
	{
		tab[i] = dist(rd);
	}
}

void sortTable(int * tab, int Tsize)
{
	sort(tab, tab + Tsize);

}





