#ifndef VOICE_H
#define VOICE_H
#include "Element.h"

namespace mxml
{
  class Voice: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "voice"; }
  };
}
#endif //VOICE_H
