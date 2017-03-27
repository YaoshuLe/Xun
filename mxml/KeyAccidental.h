#ifndef KEY_ACCIDENTAL_H
#define KEY_ACCIDENTAL_H
#include "Element.h"

namespace mxml
{
  class KeyAccidental: public Value<AccidentalValueEnum>
  {
  public:
    virtual const char* tagname() const { return "key-accidental"; }
  };
}
#endif //KEY_ACCIDENTAL_H
