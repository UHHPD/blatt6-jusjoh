#ifndef KOERPER_HH
#define KOERPER_HH

#include <iostream>
#include "Vektor.hh"

class Koerper{
public:
  virtual std::string name() {return "Koerper";}

  virtual Vektor punkt() = 0;

};
#endif