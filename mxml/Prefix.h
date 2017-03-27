#ifndef PREFIX_H
#define PREFIX_H
#include "StyleText.h"

namespace mxml
{
  class Prefix: public StyleText
  {
  public:
    virtual const char* tagname() const { return "prefix"; }
  };
}
#endif //PREFIX_H
