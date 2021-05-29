// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "scena.hh"
#include "exampleConfig.h"
#include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "Graniastoslup6.hh"


/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150

int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;





 
  char opcja;

Scena a;
std::cout<<"obruc"<<std::endl;
std::cout<<"powtorz obroc"<<std::endl;
std::cout<<"przesun"<<std::endl;
std::cout<<"wyswietl wiezcholki"<<std::endl;
std::cout<<"move"<<std::endl;

while (opcja != 'k')
{
     a.Zapis();
     a.opcja();
      a.Zapis();
  std::cout<<"opcja"<<std::endl;
    std::cin>>opcja;
  /*  switch(opcja)
    {
        case 'o':
        {
Matrix<3> mac;
while(1)
{

    std::cout<<"podaj os"<<std::endl;
            std::cin>>os;
            if(os=='.')
            {
              break;
            }
          std::cout<<"podaj kat"<<std::endl;
            std::cin>>kat;

            if(os=='x')
            {
                mac=mac*obr_x(kat);
            }
            else  if(os=='y')
            {
  mac=mac*obr_y(kat);
            }
             else  if(os=='z')
             {
  mac=mac*obr_z(kat);
             }
}
re.rot(mac);
        mac_g=mac;
            
         
        }break;
        case 'p':
        {
          double x,y,z;
          std::cout<<"podaj x y"<<std::endl;
            std::cin>>x>>y>>z;
             wektor[0]=x;
             wektor[1]=y;
              wektor[1]=z;
              Vector <3> tmpV3 = Vector <3>(wektor);
              re.move_r(tmpV3);
            //kod tanslacji czyli przesuniecia
        }break;
        case 'w':
        {
            std::cout<<re;
        }break;
                 case 't':
        {
re.rot(mac_g);
  }break;
                   case 'r':
        {
std::cout<<mac_g;
  }break;
         case 'm':
        {
std::cout<<"obruc"<<std::endl;
std::cout<<"przesun"<<std::endl;
std::cout<<"wyswietl wiezcholki"<<std::endl;
std::cout<<"move"<<std::endl;
std::cout<<"koniec"<<std::endl;
  }break;
    }
        if (!n.Zapis()) return 1;
    if (!re.Zapis()) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    */
}

  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}

