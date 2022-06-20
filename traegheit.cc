#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

int main() {
  const int N = 10000;     // Anzahl Integrationspunkte
  const double M = 2;      // Masse des Zylindermantels
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std::unique_ptr<Zylindermantel> zm(new Zylindermantel(ZM_R, ZM_L));
  std::unique_ptr<Vollzylinder> vz(new Vollzylinder(ZM_R, ZM_L));

  double Jzm = 0;     // Massentraegheitsmoment
  double Jvz = 0;
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = zm->punkt();
    Vektor y = vz->punkt();
    // Abstand Punkt x und Gerade a + t*u
    Vektor n = (x-a).kreuz(u);//Normalenvektor x-a kreuz u
    Vektor nvz = (y-a).kreuz(u);
    double r = n.betrag()/u.betrag(); //|n|/|u|
    double rvz = nvz.betrag()/u.betrag();
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    Jzm += m * r * r;
    Jvz += m * rvz * rvz;
  }
  std::cout << "Massentraegheitsmoment fuer einen Zylindermantel"
            << " mit a = " << a << " und u = " << u << ": " << Jzm << std::endl;
  std::cout << "Massentraegheitsmoment fuer einen Vollzylinder"
            << " mit a = " << a << " und u = " << u << ": " << Jvz << std::endl;
            
  return 0;
}
