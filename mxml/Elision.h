#ifndef ELISION_H
#define ELISION_H
#include "TextFontColor.h"

namespace mxml
{
  class Elision: public TextFontColor
  {
  public:
    virtual const char* tagname() const { return "elision"; }
  };
}
#endif //ELISION_H
