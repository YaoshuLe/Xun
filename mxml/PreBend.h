#ifndef PRE_BEND_H
#define PRE_BEND_H
#include "Element.h"

namespace mxml
{
  class PreBend: public Empty
  {
  public:
    virtual const char* tagname() const { return "pre-bend"; }
  };
}
#endif //PRE_BEND_H
