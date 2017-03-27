#ifndef MUTE_H
#define MUTE_H
#include "Element.h"

namespace mxml
{
  class Mute: public Value<MuteEnum>
  {
  public:
    virtual const char* tagname() const { return "mute"; }
  };
}
#endif //MUTE_H
