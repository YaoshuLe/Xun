#ifndef BEAM_H
#define BEAM_H
#include "Element.h"
#include "Color.h"

namespace mxml
{
  class Beam: public Value<BeamValueEnum>, public Color
  {
  public:
    Beam();
    virtual const char* tagname() const { return "beam"; }
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasRepeater() const;
    void hasRepeater(bool value);
    YesNoEnum repeater() const;
    void repeater(YesNoEnum value);
    bool hasFan() const;
    void hasFan(bool value);
    FanEnum fan() const;
    void fan(FanEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasNumber {false};
    int _number;
    bool _hasRepeater {false};
    YesNoEnum _repeater;
    bool _hasFan {false};
    FanEnum _fan;
  };
}
#endif //BEAM_H
