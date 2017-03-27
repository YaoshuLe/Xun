#ifndef SUFFIX_H
#define SUFFIX_H
#include "StyleText.h"

namespace mxml
{
  class Suffix: public StyleText
  {
  public:
    virtual const char* tagname() const { return "suffix"; }
  };
}
#endif //SUFFIX_H
