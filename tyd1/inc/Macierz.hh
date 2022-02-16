#ifndef SMacierz_HH
#define SMacierz_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <algorithm>
#include <iostream>


/*
 *  Klasa 'SMacierz<typ,ROZMIAR>' opisuje nam pojęcie SMacierz<typ,ROZMIAR>y i zawiera
 *  elementy niezbedne do wykonywania operacji na SMacierz<typ,ROZMIAR>ach.
 *  
 *  Prywatne:
 *     tab - tablica (z klasy SWektor<typ,ROZMIAR>), dzieki ktorej zapisujemy SMacierz<typ,ROZMIAR>.
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Metoda typ Wyznacznik() liczy wyznacznik SMacierz<typ,ROZMIAR>y.
 *
 *     Przeciazenie operatora mnoznia realizuje mnozenie SMacierz<typ,ROZMIAR>y razy SWektor<typ,ROZMIAR>.
 */
   template <typename typ,  int ROZMIAR>
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
 * Realizuje liczenie wyznacznika SMacierz<typ,ROZMIAR>y metodą Gaussa.
 * Argumenty:
 *    brak
 *
 * Zmienne:
 *    kop=*this - kopia SMacierz<typ,ROZMIAR>y
 *    skalar    - zmienna usprawniajaca zerowanie wyrazów
 *    tmp       - SWektor<typ,ROZMIAR> pomocniczy
 *    wynik     - zmienna przechowująca aktualną wartośc wyznacznika
 *    ind       - zmienna zabezpieczająca wyjście poza SMacierz<typ,ROZMIAR>
 *    mnoznik   - zmienna zmieniajaca znak przy zamianie wierszy
 *
 * Zwraca:
 *    Liczbę, będącą wyznacznikiem SMacierz<typ,ROZMIAR>y.
 */
  typ Wyznacznik();



/*!
 * Realizuje mnożenie SMacierz<typ,ROZMIAR>y przez SWektor<typ,ROZMIAR>.
 * Argumenty:
 *    tab[i] - mamy dostep do SMacierz<typ,ROZMIAR>y dzieki przeciazeniu
 *    W      - SWektor<typ,ROZMIAR>, przez który mnożymy SMacierz<typ,ROZMIAR>
 * Zwraca:
 *    SWektor<typ,ROZMIAR>, jako wynik mnożenia.
 */
  SWektor<typ,ROZMIAR> operator * (SWektor<typ,ROZMIAR> W);
};





 template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> & SMacierz<typ,ROZMIAR>::operator[](int i)
{
    return tab[i];
}



 template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR>  SMacierz<typ,ROZMIAR>::operator[](int i) const
{
    return tab[i];
}



 template <typename typ,  int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const SMacierz<typ,ROZMIAR> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm << Mac[i] << std::endl;
    }
    return Strm;
}


 template <typename typ,  int ROZMIAR>
std::istream& operator >> (std::istream &Strm, SMacierz<typ,ROZMIAR> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
}



 template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR>  SMacierz<typ,ROZMIAR>::operator * (SWektor<typ,ROZMIAR> W)
{
    SWektor<typ,ROZMIAR> wynik;
    for (int i=0; i<ROZMIAR; i++)
    wynik[i]=tab[i]*W;

    return wynik;
}


 template <typename typ,  int ROZMIAR>
typ SMacierz<typ,ROZMIAR>::Wyznacznik()
{
    SMacierz<typ,ROZMIAR> kop=*this;
    
    typ wynik=0;
  

    int ind=0;
    for (int i=0; i<ROZMIAR; i++)
    {
        do
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
        }while (kop[i][i]==0);
        if(kop[i][i]==0)
        return 0;
        for (int j=i+1; j<ROZMIAR; j++)
        {
            kop[j]=kop[j]-kop[i]*kop[j][i]/kop[i][i];
        }

        wynik=wynik*kop[i][i];
    }
    
    return wynik;
}
#endif
