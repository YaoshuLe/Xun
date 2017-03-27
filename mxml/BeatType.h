#ifndef BEAT_TYPE_H
#define BEAT_TYPE_H
#include "Element.h"

namespace mxml
{
  class BeatType: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "beat-type"; }
  };
}
#endif //BEAT_TYPE_H
