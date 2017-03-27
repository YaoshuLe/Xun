#ifndef TIMPANI_H
#define TIMPANI_H
#include "Element.h"

namespace mxml
{
  class Timpani: public Empty
  {
  public:
    virtual const char* tagname() const { return "timpani"; }
  };
}
#endif //TIMPANI_H
