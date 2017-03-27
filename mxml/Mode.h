#ifndef MODE_H
#define MODE_H
#include "Element.h"

namespace mxml
{
  class Mode: public Value<ModeEnum>
  {
  public:
    virtual const char* tagname() const { return "mode"; }
  };
}
#endif //MODE_H
