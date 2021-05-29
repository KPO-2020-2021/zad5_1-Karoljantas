#pragma once

#include "matrix.hh"
#include "vector.hh"
/*!
 * \brief Kalasa opisujaca prostopadloscian
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu prostopadloscianu
 */

class  bryla{
protected:
int SIZE;
  Vector<3> srodek;
   std::vector<Vector<3>> point;
   std::string nazwa;
   public:
   

const   Vector<3> &operator [] (int index) const;
  Vector<3> &operator [] (int index) ;
 bryla operator + (  Vector<3> move);
void move_r(  Vector<3> move);
void rot(Matrix<3> mac);
std::string get_nazwa(){return nazwa;}



};
/*!
 * rotacja bryly                                                          |
 *  Argumenty:                                                                |
 *     \param[in] mac - macie obr                                                 |
 *                                                |
 *                                                                    |
 *    \retval  bryla po obr                              |
 */
void bryla::rot(Matrix<3> mac)
{
    for(int i=0;i< SIZE;i++)
    {
        point[i]=mac*(point[i]-srodek)+srodek;
    }
   
}


/*!
 *  Funktor prostopadloscianu.                                                                                                                      
 * \param[in] index - index wektora.                                                                                                             
 * \retval Wartosc prostopadloscianu w danym miejscu tablicy.                              
 */
const   Vector<3> & bryla::operator [] (int index) const
{
    return point[index];
}
/*!
 *  Funktor prostopadloscianu.                                                                                                                      
 * \param[in] index - index wektora.                                                                                                             
 * \retval Wartosc prostopadloscianu w danym miejscu tablicy.                              
 */
  Vector<3> & bryla::operator [] (int index) 
{
return point[index];
}
/*!
*  Realizuje dodawanie Wektora do prostopadloscianu.                                                                      
 * \param[in]  move- drugi skladnik dodawania.                                         
  * \retval    Sume dwoch skladnikow wierzcholkow prostopadloscianu i wektora                                                                             
 */
 bryla  bryla::operator + (  Vector<3> move)
{
    
     bryla wynik;
  
    for(int i=0;i< SIZE;i++)
        wynik[i]=point[i]+move;
    return wynik;
    
}

/*!
*  funkcja przesowajaca prostopadloscian o dany wektor                                                                  
 * \param[in]  move- wektor translacjia.   
 * \param this - prostopadloscian                                     
  * \retval   prostopadloscian po przesunueciu                                                                          
 */
void  bryla::move_r(  Vector<3> move)
{
     
     srodek=srodek+move;
    for(int i=0;i< SIZE;i++)
        point[i]=point[i]+move;
 
}





