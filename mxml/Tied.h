#ifndef TIED_H
#define TIED_H
#include "Element.h"
#include "LineType.h"
#include "DashedFormatting.h"
#include "Position.h"
#include "Placement.h"
#include "Orientation.h"
#include "Bezier.h"
#include "Color.h"

namespace mxml
{
  class Tied: public Empty, public LineType, public DashedFormatting, public Position, public Placement, public Orientation, public Bezier, public Color
  {
  public:
    Tied();
    virtual const char* tagname() const { return "tied"; }
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
#endif //TIED_H
