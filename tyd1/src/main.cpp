#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main()
{
  UkladRownanLiniowych<LZespolona,5>   UklRown;    // zmienna przechowujaca macierz
  cin >> UklRown;

  
  cout << endl << " Start programu " << endl << endl;
  cout << UklRown;
  cout << endl;
  cout << "Rozwiazanie x = (x1, x2, x3):" << endl;

  if(UklRown.Oblicz())   // liczenie rozwiazan
  {
    return 0;
  }
  else
  {
    UklRown.wynik();   // wypisanie wynikow
    cout << endl;
    UklRown.wypisz_blad();  // wypisanie bledu
  }
  
  return 0;
}

