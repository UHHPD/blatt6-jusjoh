#include "Vektor.hh"
#include "Vollzylinder.hh"
#include "Zylindermantel.hh"
#include <iostream>
#include <memory>

double traegheit_berechnen(Koerper *zm, Vektor a, Vektor u) {
  const int N = 10000; // Anzahl Integrationspunkte
  const double M = 1;  // Masse des Zylindermantels

  double Jzm = 0;   // Massentraegheitsmoment
  double m = M / N; // Masse eines Massenpunktes
  for (int i = 0; i < N; ++i) {
    Vektor x = zm->punkt();
    // Abstand Punkt x und Gerade a + t*u
    Vektor n = (x - a).kreuz(u);        // Normalenvektor x-a kreuz u
    double r = n.betrag() / u.betrag(); //|n|/|u|
    // std::cout << x << " :" << r << std::endl;
    // addiere Beitrag des Massenpunktes zum Traegheitsmoment
    Jzm += m * r * r;
  }
  std::cout << "Massentraegheitsmoment fuer einen " << zm->name()
            << " mit a = " << a << " und u = " << u << ": " << Jzm << std::endl;
}
int main() {

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

  traegheit_berechnen(zm.get(), a, u);
  traegheit_berechnen(vz.get(), a, u);

  return 0;
}
