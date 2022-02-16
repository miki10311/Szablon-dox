#include "LZespolona.hh"



LZespolona  LZespolona::operator + (LZespolona Skl2)
{
  LZespolona  Wynik;

  Wynik[1] = re + Skl2[1];
  Wynik[2] = im + Skl2[2];
  return Wynik;
}



LZespolona  LZespolona::operator - (LZespolona Skl2)
{
  LZespolona  Wynik;

  Wynik[1] = re - Skl2[1];
  Wynik[2] = im - Skl2[2];
  return Wynik;
}



LZespolona  LZespolona::operator * (LZespolona Skl2)
{
  LZespolona  Wynik;

  Wynik[1] = (re * Skl2[1]) - (im * Skl2[2]);
  Wynik[2] = (im * Skl2[1]) + (re * Skl2[2]);
  return Wynik;
}



LZespolona  LZespolona::operator * (double Skl2)
{
  LZespolona wynik;

  wynik[1]=re*Skl2;
  wynik[2]=im*Skl2;
  return wynik;
}



LZespolona  LZespolona::operator / (LZespolona Skl2)
{
  LZespolona  Wynik;
  Wynik=(*this)*Skl2.Sprzezenie()/Skl2.Modul2();
  return Wynik;
}



LZespolona LZespolona::Sprzezenie()
{
  LZespolona wynik=*this;
  wynik[2]=wynik[2] *(-1);
  return wynik;
}



double LZespolona::Modul2()
{
  return re*re + im*im;
}



LZespolona  LZespolona::operator / (double Skl2)
{
  LZespolona  Wynik;
  
  assert (Skl2!=0);
  Wynik[1] = re/Skl2;
  Wynik[2] = im/Skl2;
  return Wynik;
}



bool LZespolona::operator == (LZespolona Skl2)
{
  if(re==Skl2.re && im==Skl2.im )
    return true;
  
  return false;
}



bool LZespolona::operator == (double Skl2)
{
  if(re==Skl2 && im==0)
    return true;
  
  return false;
}



void Wyswietl(LZespolona Skl1)
{
cout << "(" << Skl1[1] << showpos << Skl1[2] << noshowpos << "i" << ")";
}



ostream & operator << (ostream &wyj, LZespolona Skl)
{
  wyj << "(" << Skl[1] << showpos << Skl[2] << noshowpos << "i" << ")";
  return wyj;
}



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