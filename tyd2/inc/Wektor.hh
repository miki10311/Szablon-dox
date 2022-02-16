#ifndef SWektor_HH
#define SWektor_HH

#include "rozmiar.h"
#include "LZespolona.hh"
#include <iostream>

using namespace std;

/*
 *  Klasa 'Wektor' opisuje nam pojęcie wektora i zawiera
 *  elementy niezbędne do wykonywania operacji na wektorach.
 *  
 *  Prywatne:
 *     tab - tablica, dzieki ktorej zapisujemy macierz.
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Przeciążenia operatorów arytmetycznych umożliwiają:
 *     - dodawanie i odejmowanie wektorów
 *     - mnożenie macierzy przez wektor
 *     - mnożenie i dzielenie wektora przez liczbę
 */
template <typename typ, int ROZMIAR>
class SWektor{

  typ tab[ROZMIAR];    // macierz o rozmiarze podanym w module 'rozmiar.h'

  public:

/*!
 * Dostarcza zmienną, na której możemy pracować. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Cala oryginalną zmienną. 
 */
  typ & operator[](int i);
  


/*!
 * Dostarcza stałą wartość. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Samą wartość.
 */
  typ operator[](int i) const;




/*!
 * Realizuje dodawanie dwoch wektorow (jeden z macierzy).
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - wektor
 * Zwraca:
 *    Wektor, jako suma wektorow.
 */
  SWektor<typ,ROZMIAR> operator + (SWektor<typ,ROZMIAR> skl2);




/*!
 * Realizuje odejmowanie dwoch wektorow (jeden z macierzy).
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - wektor
 * Zwraca:
 *    Wektor, jako roznica wektorow.
 */
  SWektor<typ,ROZMIAR> operator - (SWektor<typ,ROZMIAR> skl2);




/*!
 * Realizuje mnozenie wektora przez macierz.
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - wektor
 * Zwraca:
 *    Liczbe, jako wynik działania.
 */
  typ operator * (SWektor<typ,ROZMIAR> skl2);




/*!
 * Realizuje mnozenie wektora (z macierzy) przez liczbę. 
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - liczba
 * Zwraca:
 *    Wektor, jako wynik działania.
 */
  SWektor<typ,ROZMIAR> operator * (typ skl2);




/*!
 * Realizuje dzielenie wektora (z macierzy) przez liczbę. 
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - liczba
 * Zwraca:
 *    Wektor, jako wynik działania.
 */
  SWektor<typ,ROZMIAR> operator /(typ skl2);

};



/*
 * Funkcja służy do przypisania watrosci Wektora ze standartowego wejscia.
 * Argumenty:
 *    operator     - zawiera symbol operatora                            
 *    Strm, Wek    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu istream.
 */
template <typename typ, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, SWektor<typ,ROZMIAR> &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm >> Wek[i];
  
  return Strm;
}




/*
 * Funkcja służy do wypisywania watrosci Wektora na standardowe wyjście.
 * Argumenty:
 *    operator     - zawiera symbol operatora                            
 *    Strm, Wek    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu ostream.
 */
template <typename typ, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const SWektor<typ,ROZMIAR> &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm << Wek[i] << "\t";
  
  return Strm;
}



//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator + (SWektor<typ,ROZMIAR> skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]+skl2[i];
  
  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator - (SWektor<typ,ROZMIAR> skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]-skl2[i];
  
  return wynik; 
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ SWektor<typ,ROZMIAR>::operator * (SWektor<typ,ROZMIAR> skl2)
{
  typ suma=0;
  for (int i=0; i<ROZMIAR; i++)
  suma+=tab[i]*skl2[i];
  
  return suma;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator * (typ skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]*skl2;
  
  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator / (typ skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]/skl2;

  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ & SWektor<typ,ROZMIAR>::operator[] (int i)
{
  return tab[i];
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ  SWektor<typ,ROZMIAR>::operator[] (int i) const
{
  return tab[i];
}
#endif
