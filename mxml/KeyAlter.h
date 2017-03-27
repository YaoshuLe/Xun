#ifndef KEY_ALTER_H
#define KEY_ALTER_H
#include "Element.h"

namespace mxml
{
  class KeyAlter: public Value<float>
  {
  public:
    virtual const char* tagname() const { return "key-alter"; }
  };
}
#endif //KEY_ALTER_H
