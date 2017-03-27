#ifndef SFP_H
#define SFP_H
#include "Element.h"

namespace mxml
{
  class Sfp: public Empty
  {
  public:
    virtual const char* tagname() const { return "sfp"; }
  };
}
#endif //SFP_H
