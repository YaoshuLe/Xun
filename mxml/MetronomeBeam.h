#ifndef METRONOME_BEAM_H
#define METRONOME_BEAM_H
#include "Element.h"

namespace mxml
{
  class MetronomeBeam: public Value<BeamValueEnum>
  {
  public:
    MetronomeBeam();
    virtual const char* tagname() const { return "metronome-beam"; }
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasNumber {false};
    int _number;
  };
}
#endif //METRONOME_BEAM_H
