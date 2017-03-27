#ifndef ARTIFICIAL_H
#define ARTIFICIAL_H
#include "Element.h"

namespace mxml
{
  class Artificial: public Empty
  {
  public:
    virtual const char* tagname() const { return "artificial"; }
  };
}
#endif //ARTIFICIAL_H
