#ifndef SIGN_H
#define SIGN_H
#include "Element.h"

namespace mxml
{
  class Sign: public Value<ClefSignEnum>
  {
  public:
    virtual const char* tagname() const { return "sign"; }
  };
}
#endif //SIGN_H
