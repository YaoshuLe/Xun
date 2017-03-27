#ifndef PP_H
#define PP_H
#include "Element.h"

namespace mxml
{
  class Pp: public Empty
  {
  public:
    virtual const char* tagname() const { return "pp"; }
  };
}
#endif //PP_H
