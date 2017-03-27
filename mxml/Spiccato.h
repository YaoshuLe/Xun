#ifndef SPICCATO_H
#define SPICCATO_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Spiccato: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "spiccato"; }
  };
}
#endif //SPICCATO_H
