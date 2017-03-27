#ifndef LAUGHING_H
#define LAUGHING_H
#include "Element.h"

namespace mxml
{
  class Laughing: public Empty
  {
  public:
    virtual const char* tagname() const { return "laughing"; }
  };
}
#endif //LAUGHING_H
