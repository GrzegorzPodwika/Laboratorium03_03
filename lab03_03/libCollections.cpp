#include "pch.h"
#include "libCollections.h"
#include "libTables.h"
#include <iostream>
#include <fstream>
using namespace std;

int loadCorrectNumberOfElements()
{
	int result{};
	cout << "Podaj ilosc elementow zbioru z przedzialu (1, 30)	";

	for (int i = 1; i < 4; i++)
	{
		cin >> result;
		if (result >= 1 && result < 30)
			return result;
		else
			cout << "Zly przedzial" << endl;
	}

	return 0;
}

int loadCorrectNumbOfDivisions()
{
	int res{};

	cout << "Podaj liczbe naturalna:  ";
	cin >> res;

	while (res < 1) {
		cin >> res;
		if (res < 1)
			cout << "Bledny przedzial";
	}

	return res;
}

void loadCorrectFileName(char *fileName)
{
	cout << "Podaj nazwe pliku do zapisu z rozszerzeniem .txt  ";
	cin >> fileName;
	int nameLength = strlen(fileName);
	bool flag = false;

	for (int i = 1; i <= 3; i++)
	{
		if (i == 3) {
			cout << "Przekroczono limit prob wprowadzenia wlasciwej nazwy.";
			cin.ignore();
			exit(0);
		}

		for (int j = 0; j < nameLength; j++)
		{
			if (j <= nameLength - 4 && fileName[j] == '.' && fileName[j + 1] == 't' && fileName[j + 2] == 'x' && fileName[j + 3] == 't') {
				flag = true;
				break;
			}
		}

		if (flag)
			break;
		else {
			cout << "Bledna nazwa pliku! Podaj nazwe z rozszerzeniem .txt!" << endl;
			cin >> fileName;
			nameLength = strlen(fileName);
		}
	}
}


void loadCorrectParameters(int & n, int & k)
{
	cout << "Podaj ilosc elementow zbioru z przedzialu (2, 50)	";
	cin >> n;

	while (n < 2 && n > 50) {
		cin >> n;
		if (n < 2 && n > 50)
			cout << "Bledny przedzial!";
	}

	cout << "Podaj ilosc elementow zbioru z przedzialu (2, n)	";
	cin >> k;

	while (k < 2 && k >= n) {
		cin >> k;
		if (k < 2 && k >= n)
			cout << "Bledny przedzial!";
	}
}


fstream createRecordFIle(char * fileName)
{
	fstream rFile(fileName, ios::out | ios::trunc);
	if (!rFile) {
		cout << "Nie udalo sie utworzyc pliku!";
		rFile.close();
		exit(0);
	}



	return rFile;
}

void saveSubsetsInLexicoGraphicOrderToFile(std::fstream & rFile, int amountOfElemInCollec, int amountOfElemInSub)
{
	int k = amountOfElemInSub;
	int n = amountOfElemInCollec;

	int p{};
	int i{};

	int *tab = createTable(k + 1);

	for (i = 1; i <= k; i++) {
		tab[i] = i;
	}

	p = k;
	while (p >= 1) {

		for (int j = 1; j <= k; j++) {
			rFile << tab[j];
		}

		rFile << endl;

		if (tab[k] == n) {
			p--;
		}
		else
			p = k;

		if (p >= 1) {
			for (i = k; i >= p; i--)
				tab[i] = tab[p] + i - p + 1;
		}
	}

	delete[] tab;
}

void saveSubsetsToFile(fstream &rFile, int n)
{
	int *B = createTable(n + 1);
	B[0] = 0;
	int i{};
	int p{};
	int j{};

	for (i = 1; i <= n; i++) {
		B[i] = 0;
	}

	i = 0;

	do
	{
		for (int k = 1; k <= n; k++)
		{
			rFile << B[k];
		}
		rFile << endl;

		i += 1;
		p = 1;
		j = i;

		while (j % 2 == 0)
		{
			j /= 2; p += 1;
		}

		if (p <= n)
			B[p] = 1 - B[p];
	} while (p <= n);



}

void saveDivisionsToFile(std::fstream & rFile, int number)
{
	int n = number;
	int d{};
	int sum{};
	int x{};

	int *S = createTable(n + 1);
	int *R = createTable(n + 1);

	S[1] = n;
	R[1] = 1;
	d = 1;

	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= R[i]; j++) {
			rFile << S[i] << " ";
		}
	}
	rFile << endl;

	while (S[1] > 1)
	{
		sum = 0;
		if (S[d] == 1)
		{
			sum += R[d];
			d -= 1;
		}

		sum += S[d];
		R[d] -= 1;
		x = S[d] - 1;

		if (R[d] > 0)
			d = d + 1;

		S[d] = x;
		R[d] = sum / x;

		x = sum % x;
		if (x != 0) {
			d += 1;
			S[d] = x;
			R[d] = 1;
		}

		for (int i = 1; i <= d; i++) {
			for (int j = 1; j <= R[i]; j++) {
				rFile << S[i] << " ";
			}
		}
		rFile << endl;
	}

	delete[] S;
	delete[] R;
}
