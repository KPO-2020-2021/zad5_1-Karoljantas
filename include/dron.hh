#pragma once
#include <unistd.h>
#include "prism.hh"
#include "Graniastoslup6.hh"
/*!
 * \brief Kalasa opisujaca prostopadloscian
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu prostopadloscianu
 */
class  Dron
{
   prism *korpus;
   Graniastoslup6 *wirniki[4];
   int id;
   double kat;
   public:

    Dron(int id,double argumentsV2[3]){
   
  Vector<3> tmpV3(argumentsV2);
kat=0;
this->id=id;
        korpus = new prism(tmpV3,100,140,100,"../datasets/prostopadloscian"+std::to_string(id)+".dat");
        for(int i=0; i<4; i++)
 wirniki[i]=new Graniastoslup6((*korpus)[i+4],50,"../datasets/gra"+std::to_string(id)+std::to_string(i)+".dat");


    }
void lot_w_dol()
{
       Vector<3> ruch2;
    ruch2[2]=-1;

    korpus->move_r(ruch2);
         for(int i=0; i<4; i++)
 wirniki[i]->move_r(ruch2);
 usleep(5000);
}
void lot_w_gore()
{
       Vector<3> ruch2;
    ruch2[2]=1;

    korpus->move_r(ruch2);
         for(int i=0; i<4; i++)
 wirniki[i]->move_r(ruch2);
 usleep(5000);
}
void obrot(double _kat=1)
{
     korpus->rot(obr_z(_kat));
             for(int i=0; i<4; i++)
 delete wirniki[i];
        for(int i=0; i<4; i++)
 wirniki[i]=new Graniastoslup6((*korpus)[i+4],50,"../datasets/gra"+std::to_string(id)+std::to_string(i)+".dat");
  usleep(5000);
}
void set_kat(double _kat)
{kat+=_kat;}
void przesun(double prze=1)
{
   Vector<3>droga;
   droga[0]=prze;
   Vector<3> ruch;


ruch=obr_z(kat)*droga;

   korpus->move_r(ruch);
         for(int i=0; i<4; i++)
 wirniki[i]->move_r(ruch);
  usleep(5000);
}

void  Zapis()
{
  korpus->Zapis();
 for(int i=0; i<4; i++)
    wirniki[i]->Zapis();
    
}

};

