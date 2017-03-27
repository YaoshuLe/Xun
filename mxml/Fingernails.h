#ifndef FINGERNAILS_H
#define FINGERNAILS_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Fingernails: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "fingernails"; }
  };
}
#endif //FINGERNAILS_H
