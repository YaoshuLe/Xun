#ifndef HUMMING_H
#define HUMMING_H
#include "Element.h"

namespace mxml
{
  class Humming: public Empty
  {
  public:
    virtual const char* tagname() const { return "humming"; }
  };
}
#endif //HUMMING_H
