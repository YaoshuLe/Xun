#ifndef METRONOME_RELATION_H
#define METRONOME_RELATION_H
#include "Element.h"

namespace mxml
{
  class MetronomeRelation: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "metronome-relation"; }
  };
}
#endif //METRONOME_RELATION_H
