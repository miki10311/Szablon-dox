#ifndef SWektor_HH
#define SWektor_HH

#include "rozmiar.h"
#include <iostream>

using namespace std;

/*
 *  Klasa 'SWektor<typ,ROZMIAR>' opisuje nam pojęcie SWektor<typ,ROZMIAR>a i zawiera
 *  elementy niezbędne do wykonywania operacji na SWektor<typ,ROZMIAR>ach.
 *  
 *  Prywatne:
 *     tab - tablica, dzieki ktorej zapisujemy macierz.
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Przeciążenia operatorów arytmetycznych umożliwiają:
 *     - dodawanie i odejmowanie SWektor<typ,ROZMIAR>ów
 *     - mnożenie macierzy przez SWektor<typ,ROZMIAR>
 *     - mnożenie i dzielenie SWektor<typ,ROZMIAR>a przez liczbę
 */
 template <typename typ,  int ROZMIAR>
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
 * Realizuje dodawanie dwoch SWektor<typ,ROZMIAR>ow (jeden z macierzy).
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - SWektor<typ,ROZMIAR>
 * Zwraca:
 *    SWektor<typ,ROZMIAR>, jako suma SWektor<typ,ROZMIAR>ow.
 */
  SWektor<typ,ROZMIAR> operator + (SWektor<typ,ROZMIAR> skl2);




/*!
 * Realizuje odejmowanie dwoch SWektor<typ,ROZMIAR>ow (jeden z macierzy).
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - SWektor<typ,ROZMIAR>
 * Zwraca:
 *    SWektor<typ,ROZMIAR>, jako roznica SWektor<typ,ROZMIAR>ow.
 */
  SWektor<typ,ROZMIAR> operator - (SWektor<typ,ROZMIAR> skl2);




/*!
 * Realizuje mnozenie SWektor<typ,ROZMIAR>a przez macierz.
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - SWektor<typ,ROZMIAR>
 * Zwraca:
 *    Liczbe, jako wynik działania.
 */
  typ operator * (SWektor<typ,ROZMIAR> skl2);




/*!
 * Realizuje mnozenie SWektor<typ,ROZMIAR>a (z macierzy) przez liczbę. 
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - liczba
 * Zwraca:
 *    SWektor<typ,ROZMIAR>, jako wynik działania.
 */
  SWektor<typ,ROZMIAR> operator * (typ skl2);




/*!
 * Realizuje dzielenie SWektor<typ,ROZMIAR>a (z macierzy) przez liczbę. 
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    Skl2   - liczba
 * Zwraca:
 *    SWektor<typ,ROZMIAR>, jako wynik działania.
 */
  SWektor<typ,ROZMIAR> operator /(typ skl2);

};

 template <typename typ,  int ROZMIAR>

std::istream & operator >> (std::istream &Strm, SWektor<typ,ROZMIAR> &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm >> Wek[i];
  return Strm;
}

 template <typename typ,  int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const SWektor<typ,ROZMIAR> &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm << Wek[i] << "\t";
  
  return Strm;
}

 template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator + (SWektor<typ,ROZMIAR> skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]+skl2[i];
  
  return wynik;
}

 template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator - (SWektor<typ,ROZMIAR> skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]-skl2[i];
  
  return wynik; 
}

 template <typename typ,  int ROZMIAR>
typ SWektor<typ,ROZMIAR>::operator * (SWektor<typ,ROZMIAR> skl2)
{
  typ suma=0;
  for (int i=0; i<ROZMIAR; i++)
  suma+=tab[i]*skl2[i];
  
  return suma;
}

 template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator * (typ skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]*skl2;
  
  return wynik;
}

 template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator / (typ skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]/skl2;

  return wynik;
}

 template <typename typ,  int ROZMIAR>
typ & SWektor<typ,ROZMIAR>::operator[] (int i)
{
  return tab[i];
}

 template <typename typ,  int ROZMIAR>
typ  SWektor<typ,ROZMIAR>::operator[] (int i) const
{
  return tab[i];
}
#endif
