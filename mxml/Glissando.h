#ifndef GLISSANDO_H
#define GLISSANDO_H
#include "Element.h"
#include "LineType.h"
#include "DashedFormatting.h"
#include "PrintStyle.h"

namespace mxml
{
  class Glissando: public Value<std::string>, public LineType, public DashedFormatting, public PrintStyle
  {
  public:
    Glissando();
    virtual const char* tagname() const { return "glissando"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //GLISSANDO_H
