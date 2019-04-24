#ifndef LIBCOLLECTIONS_H
#define LIBCOLLECTIONS_H
#include <fstream>

/*
Funkcja wczytujaca liczbe elementow zbioru (n)
@return n liczbe elementow zbioru lub 0 po 3 probach
*/
int loadCorrectNumberOfElements();

/*
Funkcja wczytujaca do skutku liczbe podzialow liczby n
@return n liczba podzialow
*/
int loadCorrectNumbOfDivisions();

/*
Funkcja wczytujaca poprawna nazwe pliku
@param fileName nazwa pliku do wczytania i kontroli bledow
*/
void loadCorrectFileName(char *fileName);

/*
Funkcja wczytujaca poprawna liczbe parametrow n i k
@param n ilosc elementow zbioru
@param k ilosc elementow w podzbiorze (k<n)
*/
void loadCorrectParameters(int &n, int &k);

/*
Funkcja tworzaca plik do zapisu wraz z kontrola bledu
@param fileName nazwa pliku do zapisu
@return strumien sluzacy do zapisu w pliku
*/
std::fstream createRecordFIle(char *fileName);

/*
Funkcja obliczajaca wszystkie k-elementowe podzbiory {1, ..., n} w porzadku leksykograficznym
@param 
*/
void saveSubsetsInLexicoGraphicOrderToFile(std::fstream &rFile, int amountOfElemInCollec, int amountOfElemInSub);

/*
Funkcja zapisujaca ciag wszystkich podzbiorow zbioru n-elementowego do pliku wynikowego
@param rFile plik do zapisu
@param n ilosc elementow zbioru
*/
void saveSubsetsToFile(std::fstream &rFile, int n);

/*
Funkcja zapisujaca ciag podzialow liczby n w porzadku antyleksykograficznym
@param rFile plik do zapisu
@param number liczba naturalna z ktorej funkcja tworzy ciag podzialow
*/
void saveDivisionsToFile(std::fstream &rFile, int number);

#endif // !LIBCOLLECTIONS_H
