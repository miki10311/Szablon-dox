#ifndef UkladRownanLiniowych_HH
#define UkladRownanLiniowych_HH

#include <iostream>
#include <cmath>
#include "Macierz.hh"
#include "LZespolona.hh"





/*
 *  Klasa UkladRownanLiniowych 
 *  
 *  Prywatne:
 *    M                     - tablica zawierająca macierz z klasy Macierz
 *    W                     - tablica zawierająca wektor z klasy Wektor 
 *    W_bladu;              - tablica zwierająca wektor bledu z klasy Wektor
 *    wyznaczniki[ROZMIAR]; - tablica zapisujaca wyznaczniki Cramera
 *    Wynik;                - tablica zawierajaca wyniki dla danych wyznacznikow
 *    blad;                 - liczba mowiaca o dlugosci wektora bledu
 *
 *  Publiczne:
 *
 *     get_Macierz() const, get_Wektor() const - zwracają wartości macierzy/wektora
 *     get_Macierz() , get_Wektor()            - zwracają macierz/wektor
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
 * Realizuje zwracanie wartosci macierzy.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca wartosc macierzy.
 */
  SMacierz<typ,ROZMIAR> get_Macierz() const
  {
    return M;
  }

/*!
 * Realizuje zwracanie macierzy.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca macierz.
 */
  SMacierz<typ,ROZMIAR> & get_Macierz() 
  {
    return M;
  }


/*!
 * Realizuje zwracanie wartosci wektora.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca wartosc wektora.
 */
  SWektor<typ,ROZMIAR> get_Wektor() const
  {
    return W;
  }


/*!
 * Realizuje zwracanie wektora.
 * Argumenty:
 *     brak
 * Zwraca:
 *    Zwraca wektor.
 */
  SWektor<typ,ROZMIAR> & get_Wektor() 
  {
    return W;
  }




/*!
 * Realizuje wypisanie samych wynikow.
 * Argumenty:
 *     Wynik - tablica zawierajaca wyniki dla danych wyznacznikow
 */
  void wynik()
  {
    for(int i=0; i<ROZMIAR; i++)
    cout << Wynik[i] << "\t";
  }


/*!
 * Realizuje wypisanie bledu.
 * Argumanty:
 *      W_bladu - tablica zwierająca wektor bledu z klasy Wektor
 *      blad - liczba mowiaca o dlugosci wektora bledu
 */
  void wypisz_blad();
  

/*!
 * Liczy wyznaczniki dla układu Cramera.
 * Argumenty:
 *      wyznaczniki[ROZMIAR] - tablica zapisujaca wyznaczniki Cramera
 *      W - wektor umozliwiajacy uzycie metody Cramera
 *      M - macierz dajaca dostep do macierzy glownej
 * Zmienne:
 *     Macierze_po_zamianie[ROZMIAR] - zmienna pomocnicza do wykonywania 
 *                               operacji na macierzach
 */
  void Licz_Wyznaczniki();


/*!
 * Liczy wartosci x1, x2, x3
 * Sprawdza sytuacje, gdy brak rozwiazan i nieskonczenie wiele rozwiazan.
 * Argumenty:
 *      M - dostarcza informacji o wyznaczniku macierzy glownej
 *      wyznaczniki[i] - tablica z wyznacznikami Cramera
 *      Wynik[i] - tablica zapisujaca niewiadome x1, x2, x3
 * Zmienne:
 *     wyznacznik_glowny - liczba będąca wyznacznikiem macierzy
 */
  bool Oblicz();
  

/*!
 * Liczy blad wedlug wzoru i zapisuje do zmiennej 'blad'.
 * Argumenty:
 *      W_bladu, M, Wynik, W, blad - opisane wyzej
 *                 niezbedne do wzoru na dlugosc wektora bledu
 */
  void Oblicz_blad();
};



/*
 * Funkcja służy do wypisywania watrosci Układu na standardowe wyjście.
 * Argumenty:
 *    operator      - zawiera symbol operatora                            
 *    Strm, UklRown - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu ostream.
 */
template <typename typ, int ROZMIAR>
std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych<typ,ROZMIAR> &UklRown)
{
 
  Strm << "Macierz A^T:" << endl;
  Strm << UklRown.get_Macierz() << endl;
  Strm << "Wektor wyrazow wolnych b:" << endl;
  Strm << UklRown.get_Wektor() << endl;

  return Strm;
}



/*
 * Funkcja służy do przypisania watrosci Układu ze standartowego wejscia.
 * Argumenty:
 *    operator      - zawiera symbol operatora                            
 *    Strm, UklRown - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    Obiekt typu istream.
 */
template <typename typ, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<typ,ROZMIAR> &UklRown)
{
  Strm >> UklRown.get_Macierz() >> UklRown.get_Wektor();
  return Strm;
}



//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
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


//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
bool UkladRownanLiniowych<typ,ROZMIAR>::Oblicz()
{
  
  typ wyznacznik_glowny=M.Wyznacznik();
  Licz_Wyznaczniki();

  for (int i=0; i<ROZMIAR; i++)
  if(wyznacznik_glowny==0 && wyznaczniki[i]==0)
  {
    cout << "Uklad nieoznaczony, nieskonczenie wiele rozwiazan" << endl;
    return true;
  }
  
  if(wyznacznik_glowny==0)   
  {
    cout << "Uklad sprzeczny, brak rozwiazan" << endl;
    return true;
  }

  for (int i=0; i<ROZMIAR; i++)
  Wynik[i]=wyznaczniki[i]/wyznacznik_glowny;
  
  return false;
}


//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
void UkladRownanLiniowych<typ,ROZMIAR>::Oblicz_blad()
{
  W_bladu=M*Wynik-W;
}


//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
void UkladRownanLiniowych<typ,ROZMIAR>::wypisz_blad()
{
  cout << "Wektor bledu: Ax-b = (" << W_bladu << ")" << endl;
}


#endif