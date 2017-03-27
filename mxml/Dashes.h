#ifndef DASHES_H
#define DASHES_H
#include "Element.h"
#include "DashedFormatting.h"
#include "Position.h"
#include "Color.h"

namespace mxml
{
  class Dashes: public Empty, public DashedFormatting, public Position, public Color
  {
  public:
    Dashes();
    virtual const char* tagname() const { return "dashes"; }
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
#endif //DASHES_H
