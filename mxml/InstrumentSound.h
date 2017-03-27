#ifndef INSTRUMENT_SOUND_H
#define INSTRUMENT_SOUND_H
#include "Element.h"

namespace mxml
{
  class InstrumentSound: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "instrument-sound"; }
  };
}
#endif //INSTRUMENT_SOUND_H
