#ifndef INSTRUMENT_NAME_H
#define INSTRUMENT_NAME_H
#include "Element.h"

namespace mxml
{
  class InstrumentName: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "instrument-name"; }
  };
}
#endif //INSTRUMENT_NAME_H
