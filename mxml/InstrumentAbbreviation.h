#ifndef INSTRUMENT_ABBREVIATION_H
#define INSTRUMENT_ABBREVIATION_H
#include "Element.h"

namespace mxml
{
  class InstrumentAbbreviation: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "instrument-abbreviation"; }
  };
}
#endif //INSTRUMENT_ABBREVIATION_H
