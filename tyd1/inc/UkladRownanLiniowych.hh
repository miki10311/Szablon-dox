#ifndef UkladRownanLiniowych_HH
#define UkladRownanLiniowych_HH

#include <iostream>
#include "Macierz.hh"
#include <cmath>



/*
 *  Klasa UkladRownanLiniowych<typ,ROZMIAR> 
 *  
 *  Prywatne:
 *    M                     - tablica zawierająca SMacierz<typ,ROZMIAR> z klasy SMacierz<typ,ROZMIAR>
 *    W                     - tablica zawierająca SWektor<typ,ROZMIAR> z klasy SWektor<typ,ROZMIAR> 
 *    W_bladu;              - tablica zwierająca SWektor<typ,ROZMIAR> bledu z klasy SWektor<typ,ROZMIAR>
 *    wyznaczniki[ROZMIAR]; - tablica zapisujaca wyznaczniki Cramera
 *    Wynik;                - tablica zawierajaca wyniki dla danych wyznacznikow
 *    blad;                 - liczba mowiaca o dlugosci SWektor<typ,ROZMIAR>a bledu
 *
 *  Publiczne:
 *
 *     get_Macierz() const, get_Wektor() const - zwracają wartości SMacierz<typ,ROZMIAR>y/SWektor<typ,ROZMIAR>a
 *     get_Macierz() , get_Wektor()            - zwracają SMacierz<typ,ROZMIAR>/SWektor<typ,ROZMIAR>
 *
 *     Metody:
 *           void wynik()
 *           void wypisz_blad();
 *           void Licz_Wyznaczniki();
 *           bool Oblicz();
 *           void Oblicz_blad();
 *                sa opisane ponizej.
 *
 */
  template <typename typ,  int ROZMIAR>
class UkladRownanLiniowych {
 
  SMacierz<typ,ROZMIAR> M;
  SWektor<typ,ROZMIAR> W;
  SWektor<typ,ROZMIAR> W_bladu;
  typ wyznaczniki[ROZMIAR];
  SWektor<typ,ROZMIAR> Wynik;
  typ blad;

  public:


/*!
 * Realizuje zwracanie wartosci SMacierz<typ,ROZMIAR>y.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca wartosc SMacierz<typ,ROZMIAR>y.
 */
 
  SMacierz<typ,ROZMIAR> get_Macierz() const
  {
    return M;
  }

/*!
 * Realizuje zwracanie SMacierz<typ,ROZMIAR>y.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca SMacierz<typ,ROZMIAR>.
 */
  SMacierz<typ,ROZMIAR> & get_Macierz() 
  {
    return M;
  }


/*!
 * Realizuje zwracanie wartosci SWektor<typ,ROZMIAR>a.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca wartosc SWektor<typ,ROZMIAR>a.
 */
  SWektor<typ,ROZMIAR> get_Wektor() const
  {
    return W;
  }


/*!
 * Realizuje zwracanie SWektor<typ,ROZMIAR>a.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca SWektor<typ,ROZMIAR>.
 */
  SWektor<typ,ROZMIAR> & get_Wektor() 
  {
    return W;
  }




/*!
 * Realizuje wypisanie samych wynikow.
 */
  void wynik()
  {
    for(int i=0; i<ROZMIAR; i++)
    cout << Wynik[i] << "\t";
  }


/*!
 * Realizuje wypisanie bledu.
 */
  void wypisz_blad();
  

/*!
 * Liczy wyznaczniki dla układu Cramera.
 */
  void Licz_Wyznaczniki();


/*!
 * Liczy wartosci x1, x2, x3
 * Sprawdza sytuacje, gdy brak rozwiazan i nieskonczenie wiele rozwiazan.
 */
  bool Oblicz();
  

/*!
 * Liczy blad wedlug wzoru i zapisuje do zmiennej 'blad'.
 */
  void Oblicz_blad();
};




 template <typename typ,  int ROZMIAR>

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<typ,ROZMIAR> &UklRown)
{
 
    Strm << "SMacierz<typ,ROZMIAR> A^T:" << endl;
    Strm << UklRown.get_Macierz() << endl;
    Strm << "SWektor<typ,ROZMIAR> wyrazow wolnych b:" << endl;
    Strm << UklRown.get_Wektor() << endl;
    

    // Kod rozszerzony
    /*
    string szukane[3]={"x_1","x_2","x_3"};
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm <<"|"<< UklRown.get_Macierz()[i] <<"|"<<"|"<< szukane[i] <<"|";
        
        if (i==ROZMIAR/2)
        Strm << "=";
        else
        Strm << " ";
        
        Strm <<"|"<< UklRown.get_Wektor()[i] <<"|"<< endl; 
    }
    */
    return Strm;
}

 template <typename typ,  int ROZMIAR>

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<typ,ROZMIAR> &UklRown)
{
    Strm >> UklRown.get_Macierz() >> UklRown.get_Wektor();
    return Strm;
}


 template <typename typ,  int ROZMIAR>
void UkladRownanLiniowych<typ,ROZMIAR>::Licz_Wyznaczniki()
{
    SMacierz<typ,ROZMIAR> Macierz_po_zamianie[ROZMIAR];

    for (int i=0; i<ROZMIAR; i++)
    Macierz_po_zamianie[i]=M;

    for (int i=0; i<ROZMIAR; i++)
    for (int j=0; j<ROZMIAR; j++)
    Macierz_po_zamianie[i][i][j]=W[j];

    for(int i=0; i<ROZMIAR; i++)
    wyznaczniki[i]=Macierz_po_zamianie[i].Wyznacznik();
}



 template <typename typ,  int ROZMIAR>
bool UkladRownanLiniowych<typ,ROZMIAR>::Oblicz()
{
    typ wyznacznik_glowny=M.Wyznacznik();
    Licz_Wyznaczniki();

    for (int i=0; i<ROZMIAR; i++)
    if(wyznacznik_glowny==0 && wyznaczniki[i]==0)
    { 
        cout << "Uklad nieoznaczony nieskonczenie wiele rozwiazan" << endl;
        return true;
    }

    if(wyznacznik_glowny==0)
    { 
        cout << "Brak rozwiazan" << endl;
        return true;
    }
   

    for (int i=0; i<ROZMIAR; i++)
    Wynik[i]=wyznaczniki[i]/wyznacznik_glowny;
    return false;
}



 template <typename typ,  int ROZMIAR>
void UkladRownanLiniowych<typ,ROZMIAR>::Oblicz_blad()
{
    W_bladu=M*Wynik-W;
    blad=sqrt(W_bladu*W_bladu);
}



 template <typename typ,  int ROZMIAR>
void UkladRownanLiniowych<typ,ROZMIAR>::wypisz_blad()
{
    cout << "SWektor<typ,ROZMIAR> bledu: Ax-b = (" << W_bladu << ")" << endl;
    cout << "Dlugosc SWektor<typ,ROZMIAR>a bledu: ||Ax-b|| = " << blad << endl;
}
#endif
