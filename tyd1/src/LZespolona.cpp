#include "LZespolona.hh"


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik[1] = re + Skl2[1];
  Wynik[2] = im + Skl2[2];
  return Wynik;
}

bool LZespolona::operator == ( double Skl2)
{
  if(re==Skl2 && im==0)
    return true;
  
  return false;
}

LZespolona  LZespolona::operator * ( double  Skl2)
{
  LZespolona wynik;
  wynik[1]=re*Skl2;
    wynik[2]=im*Skl2;
    return wynik;
}


/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator - (  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik[1] =re - Skl2[1];
  Wynik[2] =im - Skl2[2];
  return Wynik;
}



/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator * ( LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik[1] = (re * Skl2[1]) - (im * Skl2[2]);
  Wynik[2] = (im * Skl2[1]) + (re * Skl2[2]);
  return Wynik;
}



/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator / (  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik=(*this)*Sprzezenie()/Modul2();
  return Wynik;
}


/*!
 * Realizuje fragment dzielenia dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator / (  double  Skl2)
{
  LZespolona  Wynik;

  assert(Skl2!=0 || Skl2!=0);
  Wynik[1] = re/Skl2;
  Wynik[2] = im/Skl2;
  return Wynik;
}

LZespolona  LZespolona::operator = ( double  Skl2)
{
  re=Skl2;
  im=Skl2;
  return *this;
}
LZespolona  LZespolona::operator = ( int  Skl2)
{
  re=Skl2;
  im=Skl2;
  return *this;
}


/*!
 * Realizuje sprzezenie urojonych czesci liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Sprzezenie liczby zespolonej.
 */
LZespolona LZespolona::Sprzezenie()
{
  LZespolona wynik=*this;
  wynik[2]=wynik[2] *(-1);
  return wynik;
}

/*!
 * Realizuje modul liczby zespolonej do kwadratu.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Modul liczby zespolonej do kwadratu.
 */
double LZespolona::Modul2()
{
  return pow(re,2) + pow(im,2);
}


/*!
 * Realizuje poprawne wyswietlenie liczby zespolonej.
 * Argumenty:
 *    Skl1 - liczba zespolona,
 * Zwraca:
 *    Brak
 */
void Wyswietl(LZespolona Skl1)
{
cout << "(" << Skl1[1] << showpos << Skl1[2] << noshowpos << "i" << ")";
}


/*!
 * Realizuje przeciazenie operacji wyjscia.
 * Argumenty:
 *    Skl - liczba zespolona,
 *    wyj - strumien do realizacji przeciazenia,
 * Zwraca:
 *    Strumien wyjscia.
 */
ostream & operator << (ostream &wyj, LZespolona Skl)
{
  wyj << "(" << Skl[1] << showpos << Skl[2] << noshowpos << "i" << ")";
  return wyj;
}


/*!
 * Realizuje przeciazenie operacji wejscia i sprawdzenie wczytywanego ciagu znakow.
 * Argumenty:
 *    Skl - liczba zespolona,
 *    wej - strumien do realizacji przeciazenia,
 * Zwraca:
 *    Strumien wejscia.
 */
istream & operator >> (istream & wej, LZespolona &Skl)
{
  char Znak;
  
  wej >> Znak;
  if (Znak != '(')
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    wej.setstate(ios_base::badbit);   // ustawienie statusu bledu 
    return wej;
  }

  wej >> Skl[1];
  if (wej.bad())
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    return wej;
  }

  wej >> Skl[2];
  if (wej.bad())
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    return wej;
  }

  wej >> Znak;
  if (Znak != 'i')
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    wej.setstate(ios_base::badbit);   // ustawienie statusu bledu 
    return wej;
  }

  wej >> Znak;
  if (Znak != ')')
  {
    cerr << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
    wej.setstate(ios_base::badbit);
    return wej;
  }

  return wej;
}



// Zakomentowany fragment kodu, to czesc programu potrzebna przy realizacji tygodnia 1 //

/*!
 * Realizuje sprawdzenie poprawnosci wczytanej liczby zespolonej.
 * Argumenty:
 *    Liczba - liczba zespolona,
 * Zwraca:
 *    Liczbe, ktora jest komunikatem o bledzie, albo o poprawnosci.
 */
 /*     int Wczytaj(LZespolona &Skl1)
        {
          char Znak;
          LZespolona Liczba;

          cin >> Znak;
          if (Znak != '(')
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          cin >> Liczba[1];
          if (cin.bad())
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          cin >> Liczba[2];
          if (cin.bad())
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          cin >> Znak;
          if (Znak != 'i')
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          cin >> Znak;
          if (Znak != ')')
          {
            cerr << "Blad zapisu liczby zespolonej. ..." << endl;
            return -1;
          }

          return 1;
        }
 */


/*!
 * Realizuje porownanie wprowadzonej liczby zespolonej z poprawnym wynikiem.
 * Argumenty:
 *    Skl1 - pierwsza liczba zespolona,
 *    Skl2 - druga liczba zespolona,
 * Zwraca:
 *    Komunikat o bledzie, albo o poprawnosci.
 */
bool LZespolona::operator == ( LZespolona Skl2)
{
  if(abs(re-Skl2[1])<EPS && abs(im-Skl2[2])<EPS )
    return true;      // mialem tutaj duzo bledow przy danych zmiennoprzecinkowych
                      // wiec wprowadzilem zakres poprawnosci jako stala

  return false;
}