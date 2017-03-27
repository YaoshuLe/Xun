#ifndef WAVY_LINE_H
#define WAVY_LINE_H
#include "Element.h"
#include "Position.h"
#include "Placement.h"
#include "Color.h"
#include "TrillSound.h"

namespace mxml
{
  class WavyLine: public Empty, public Position, public Placement, public Color, public TrillSound
  {
  public:
    WavyLine();
    virtual const char* tagname() const { return "wavy-line"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopContinueEnum type() const;
    void type(StartStopContinueEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopContinueEnum _type;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //WAVY_LINE_H
