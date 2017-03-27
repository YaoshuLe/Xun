#ifndef CHORD_H
#define CHORD_H
#include "Element.h"

namespace mxml
{
  class Chord: public Empty
  {
  public:
    virtual const char* tagname() const { return "chord"; }
  };
}
#endif //CHORD_H
