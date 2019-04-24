// Podwika_Grzegorz_Program_03.cpp - wtorek 11:00

#include "pch.h"
#include "libCollections.h"
#include "libTables.h"
#include <iostream>
using namespace std;

int main()
{
	int numberOfDivisions = loadCorrectNumbOfDivisions();

	char name[50];
	loadCorrectFileName(name);
	fstream recordFile = createRecordFIle(name);

	saveDivisionsToFile(recordFile, numberOfDivisions);

	recordFile.close();
	return 0;
}