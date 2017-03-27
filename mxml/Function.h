#ifndef FUNCTION_H
#define FUNCTION_H
#include "StyleText.h"

namespace mxml
{
  class Function: public StyleText
  {
  public:
    virtual const char* tagname() const { return "function"; }
  };
}
#endif //FUNCTION_H
