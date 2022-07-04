#ifndef ZYLINDERMANTEL_HH
#define ZYLINDERMANTEL_HH

#include "Koerper.hh"

class Zylindermantel: public Koerper {
public:
  Zylindermantel(double nr, double nl);
  std::string name() {return "Zylindermantel";}
  Vektor punkt();

private:
  double r_, l_;
};

#endif
