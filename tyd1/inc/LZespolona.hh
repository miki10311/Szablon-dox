#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#define EPS 0.1             // stała definiujaca dokladnosc rownan

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class  LZespolona {

  
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
public:




double & operator [] (int i)
{
  assert(i<3 && i>0);
  if(i==1)
  return re;

  return im;
}

double  operator [] (int i) const
{
  assert(i<3 && i>0);
  if(i==1)
  return re;

  return im;
}
bool operator == ( LZespolona Skl2);
bool operator == (double Skl2);

LZespolona  operator = ( double  Skl2);
LZespolona  operator = ( int  Skl2);

LZespolona  operator + ( LZespolona  Skl2);
LZespolona  operator - ( LZespolona  Skl2);
LZespolona  operator * ( LZespolona  Skl2);
LZespolona  operator / ( LZespolona  Skl2);
LZespolona  operator / ( double  Skl2);
LZespolona  operator * ( double  Skl2);


LZespolona Sprzezenie();
double Modul2();


};




void Wyswietl(LZespolona);
int Wczytaj(LZespolona&);
/*
 * Zapowiedzi definicji przeciazen operatorow
 */

ostream &operator << (ostream &wyj, LZespolona Skl);
istream &operator >> (istream &wej, LZespolona &Skl);


#endif
