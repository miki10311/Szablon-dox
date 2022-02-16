#ifndef SMacierz_HH
#define SMacierz_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include "LZespolona.hh"
#include <algorithm>
#include <iostream>


/*
 *  Klasa 'SMacierz' opisuje nam pojęcie macierzy i zawiera
 *  elementy niezbedne do wykonywania operacji na macierzach.
 *  
 *  Prywatne:
 *     tab - tablica (z klasy SWektor), dzieki ktorej zapisujemy macierz.
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Metoda double Wyznacznik() liczy wyznacznik macierzy.
 *
 *     Przeciazenie operatora mnoznia realizuje mnozenie macierzy razy wektor.
 */
template <typename typ, int ROZMIAR>
class SMacierz{

  SWektor<typ,ROZMIAR> tab[ROZMIAR];

  public:

/*!
 * Dostarcza zmienną, na której możemy pracować. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Cala oryginalną zmienną. 
 */
  SWektor<typ,ROZMIAR> & operator[](int i);



/*!
 * Dostarcza stałą wartość. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Samą wartość.
 */
  SWektor<typ,ROZMIAR> operator[](int i) const;



/*!
 * Realizuje liczenie wyznacznika macierzy metodą Gaussa.
 * Argumenty:
 *    brak
 *
 * Zmienne:
 *    kop=*this - kopia macierzy
 *    wynik     - zmienna przechowująca aktualną wartośc wyznacznika
 *    ind       - zmienna zabezpieczająca wyjście poza macierz
 *
 * Zwraca:
 *    Liczbę, będącą wyznacznikiem macierzy.
 */
  typ Wyznacznik();



/*!
 * Realizuje mnożenie macierzy przez wektor.
 * Argumenty:
 *    tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    W      - wektor, przez który mnożymy macierz
 * Zwraca:
 *    Wektor, jako wynik mnożenia.
 */
  SWektor<typ,ROZMIAR> operator * (SWektor<typ,ROZMIAR> W);
};




/*!
 * Dostarcza zmienną, na której możemy pracować. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Cala oryginalną zmienną. 
 */
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> & SMacierz<typ,ROZMIAR>::operator[](int i)
{
    return tab[i];
}



/*!
 * Dostarcza stałą wartość. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Samą wartość.
 */
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> SMacierz<typ,ROZMIAR>::operator[](int i) const
{
    return tab[i];
}



/*
 * Funkcja służy do wypisywania watrosci Macierzy na standardowe wyjście.
 * Argumenty:
 *    operator     - zawiera symbol operatora                            
 *    Strm, Mac    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu ostream.
 */
template <typename typ, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const SMacierz<typ,ROZMIAR> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm << Mac[i] << std::endl;
    }
    return Strm;
}


/*
 * Funkcja służy do przypisania watrosci Macierzy ze standartowego wejscia.
 * Argumenty:
 *    operator     - zawiera symbol operatora                            
 *    Strm, Mac    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu istream.
 */
template <typename typ, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, SMacierz<typ,ROZMIAR> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
}




//opisane wyżej w ciele klasy
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> SMacierz<typ,ROZMIAR>::operator * (SWektor<typ,ROZMIAR> W)
{
    SWektor<typ,ROZMIAR> wynik;
    for (int i=0; i<ROZMIAR; i++)
    wynik[i]=tab[i]*W;

    return wynik;
}



// opisane wyżej w ciele klasy
template <typename typ, int ROZMIAR>
typ SMacierz<typ,ROZMIAR>::Wyznacznik()
{
    SMacierz<typ,ROZMIAR> kop=*this;
    typ wynik=1;
    int ind=0;
    
    for (int i=0; i<ROZMIAR; i++)
    {
        while (kop[i][i]==0)
        {
            if (++ind==ROZMIAR)
            {     
                break;
            }
            else if (kop[i][i]==0)
            {
                std::swap(kop[i],kop[ind]);
                wynik=wynik*(-1); 
            }
        }
        
        if(kop[i][i]==0)
        return 0;
         
        for (int j=i+1; j<ROZMIAR; j++)
        {
            if(kop[i][i]==0)
            return 0;

            kop[j]=kop[j]-(kop[i]*kop[j][i]/kop[i][i]);
        
            if(kop[i][i]==0)
            return 0;
        
        }
        wynik=kop[i][i] * wynik;
    }
    return wynik;
}

#endif