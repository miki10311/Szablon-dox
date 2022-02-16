#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

/*
 *  Klasa UkladRownanLiniowych 
 *  
 *  Prywatne:
 *    re     - czesc rzeczywista liczby
 *    im     - czesc urojona liczby
 *
 *  Publiczne:
 *    Konstruktor parametryczny. 
 *    Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *        na potrzebnych danych nie zmieniajac oryginalu.
 *
 *    Inne operatory opisane są poniżej
 *
 *    Metoda 'Sprzezenie' realizuje sprzężenie liczy zespolonej.
 *    Metoda 'Modul' realizuje modul liczby zespolonej do kwadratu.
 *    Metoda 'Wyswietl' realizuje wypisnie liczby zespolonej wedlug standardu.
 *
 */
class  LZespolona {

  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  public:

/*
 * Konstruktor parametryczny rozwiązujący problem błędu 
 * przyrównania do zera (różnych typów)
 */
  LZespolona(double re=0, double im=0):re(re),im(im)
  {}


/*!
 * Dostarcza zmienną, na której możemy pracować. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Cala oryginalną zmienną. 
 */
  double & operator [] (int i)
  {
    assert(i<3 && i>0);
    if(i==1)
    return re;

    return im;
  }


/*!
 * Dostarcza stałą wartość. 
 * Argumenty:
 *    i - indeks
 * Zwraca:
 *    Samą wartość.
 */
  double  operator [] (int i) const
  {
    assert(i<3 && i>0);
    if(i==1)
    return re;

    return im;
  }



/*!
 * Realizuje porownanie dwoch liczb zespolonych.
 * Argumenty:
 *    re   - część rzeczywsita pierwszej liczby zespolonej
 *    im   - część urojona pierwszej liczby zespolonej
 *    Skl2 - druga liczba zespolona,
 * Zwraca:
 *    Komunikat o bledzie, albo o poprawnosci.
 */
  bool operator == (LZespolona Skl2);




/*!
 * Sprawdza czy dana liczba jest urojona czy rzeczywista.
 * Argumenty:
 *    re   - czesc rzeczywsiata liczby zespolonej
 *    im   - czesc urojona liczby zespolonej
 *    Skl2 - dowolna wartość rzeczywsiata 
 * Zwraca:
 *    Roztrzygnięcie typu wprowadzonych danych liczby.
 */
  bool operator == (double Skl2);




/*!
 * Realizuje przypisywanie liczby zmiennoprzecinkowej
 * do współczynników liczby zespolonej.
 * Argumenty:
 *    re   - czesc rzeczywsiata liczby zespolonej
 *    im   - czesc urojona liczby zespolonej
 *    Skl2 - wartość re i im po wykonaniu 
 * Zwraca:
 *    Wskaźnik na tę liczbę.
 */
  LZespolona  operator = (double Skl2);




/*!
 * Realizuje przypisywanie liczby całkowitej
 * do współczynników liczby zespolonej.
 * Argumenty:
 *    re   - czesc rzeczywsiata liczby zespolonej
 *    im   - czesc urojona liczby zespolonej
 *    Skl2 - wartość re i im po wykonaniu 
 * Zwraca:
 *    Wskaźnik na tę liczbę.
 */
  LZespolona  operator = (int Skl2);




/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik,
 *    Skl2 - drugi skladnik.
 * Zwraca:
 *    Sume dwoch liczb przekazanych jako parametry.
 */
  LZespolona  operator + (LZespolona Skl2);



/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - odjemna,
 *    Skl2 - odjemnik.
 * Zwraca:
 *    Roznice dwoch liczb przekazanych jako parametry.
 */
  LZespolona  operator - (LZespolona Skl2);



/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy czynnik,
 *    Skl2 - drugi czynnik.
 * Zwraca:
 *    Iloczyn dwoch liczb przekazanych jako parametry.
 */
  LZespolona  operator * (LZespolona Skl2);




/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Iloraz dwoch liczb przekazanych jako parametry.
 */
  LZespolona  operator / (LZespolona Skl2);




/*!
 * Realizuje fragment dzielenia dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Iloraz dwoch liczb przekazanych jako parametry.
 */
  LZespolona  operator / (double Skl2);




/*!
 * Realizuje mnozenie liczby zespolonej przez stałą.
 * Argumenty:
 *    Skl2  - stała (parametr),
 *    wynik - tablica z wynikiem poprzednich operacji
 *    re    - czesc rzeczywsiata liczby zespolonej
 *    im    - czesc urojona liczny zespolonej
 * Zwraca:
 *    Iloczyn dwoch liczb przekazanych jako parametry.
 */
  LZespolona  operator * (double Skl2);



/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    wynik[2] - czesc urojona liczby zespoloej
 * Zwraca:
 *    Sprzezenie liczby zespolonej.
 */
  LZespolona Sprzezenie();




/*!
 * Realizuje modul liczby zespolonej do kwadratu.
 * Argumenty:
 *    re    - czesc rzeczywsiata liczby zespolonej
 *    im    - czesc urojona liczny zespolonej 
 * Zwraca:
 *    Modul liczby zespolonej do kwadratu.
 */
  double Modul2();
};




/*!
 * Realizuje poprawne wyswietlenie liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Brak
 */
void Wyswietl(LZespolona);



/*!
 * Realizuje przeciazenie operacji wyjscia.
 * Argumenty:
 *    Skl - liczba zespolona,
 *    wyj - strumien do realizacji przeciazenia,
 * Zwraca:
 *    Strumien wyjscia.
 */
ostream &operator << (ostream &wyj, LZespolona Skl);




/*!
 * Realizuje przeciazenie operacji wejscia i sprawdzenie wczytywanego ciagu znakow.
 * Argumenty:
 *    Skl - liczba zespolona,
 *    wej - strumien do realizacji przeciazenia,
 * Zwraca:
 *    Strumien wejscia.
 */
istream &operator >> (istream &wej, LZespolona &Skl);


#endif