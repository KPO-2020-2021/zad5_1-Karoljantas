#pragma once
#include "dron.hh"
#include "powierzchnia.hh"
/*!
 * \brief Kalasa opisujaca scene
 *
 *nieniejsza klasa zawiera metody oraz paremetry potrzebne do opisu scene
 */
#include "../include/lacze_do_gnuplota.hh"
class Scena {
  PzG::LaczeDoGNUPlota Lacze;
  Powierzchnia *dno;
  Dron *nowy[2];

public:
  Scena() {
    double argumentsV2[] = {10.0, 25.0, 10.0};
    double argumentsV3[] = {-100.0, -105.0, -10.0};
    nowy[0] = new Dron(0, argumentsV2);
    nowy[1] = new Dron(1, argumentsV3);

    for (int i = 0; i < 2; i++) {
      Lacze.DodajNazwePliku(
          ("../datasets/prostopadloscian" + std::to_string(i) + ".dat").c_str(),
          PzG::RR_Ciagly, 2);
      for (int j = 0; j < 4; j++)
        Lacze.DodajNazwePliku(
            ("../datasets/gra" + std::to_string(i) + std::to_string(j) + ".dat")
                .c_str(),
            PzG::RR_Ciagly, 2);
    }
    Lacze.DodajNazwePliku("../datasets/dno.dat", PzG::RR_Ciagly, 2);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    // Ustawienie zakresow poszczegolnych osi
    Lacze.UstawZakresY(-400, 400);
    Lacze.UstawZakresX(-400, 400);
    Lacze.UstawZakresZ(-400, 400);
    dno = new Powierzchnia(800, 800, -20, "../datasets/dno.dat");
  }
  /*!
   * Funkcja opisująca opcje. | Argumenty: |
   *                                                |
   *     \param [in]        kat - kat                        |
   *            \param [in] nr   - nr drona | \param [in] x  -droga | .        |
   */

  void opcja() {
    double x;
    double kat = 0;
    int nr;
    std::cout << "podaj nr drona: " << std::endl;
    std::cin >> nr;
    std::cout << "podaj drogę: " << std::endl;
    std::cin >> x;
     std::cout<<"podaj kat: "<<std::endl;
    std::cin>>kat;
    Lacze.DodajNazwePliku("../datasets/droga.dat", PzG::RR_Ciagly, 2);
    nowy[nr]->okresl_droge(x);
    for (int i = 0; i < 50; i++) {
      nowy[nr]->lot_w_gore();
      Zapis();
    }

    nowy[nr]->set_kat(kat);
    for (int i = 0; i < kat; i++) {

      nowy[nr]->obrot();

      Zapis();
    }
    for (int i = 0; i < x; i++) {
      nowy[nr]->przesun();

      Zapis();
    }
    /*
    x = x * sin((170 / 2) * M_PI / 180) / sin(10 * M_PI / 180);

    for (int i = 0; i < 360; i += 10) {    std::cout << "dsfdsfdddddddddddf" << x;
      nowy[nr]->set_kat(10);
      for (int i = 0; i < 10; i++) {

        nowy[nr]->obrot();

        Zapis();
      }
      for (int i = 0; i < x; i++) {
        nowy[nr]->przesun();

        Zapis();
      }
    }*/
    for (int i = 0; i < 50; i++) {
      nowy[nr]->lot_w_dol();
      Zapis();
    }
    Lacze.UsunOstatniaNazwe();
  }
  /*!
   * Funkcja opisujaca zapis | Argumenty: |
   *                                                |
   */

  void Zapis() {
    for (int i = 0; i < 2; i++)
      nowy[i]->Zapis();
    dno->Zapis();
    Lacze.Rysuj();
  }
};