#ifndef OTHER_NOTATION_H
#define OTHER_NOTATION_H
#include "Element.h"
#include "PrintObject.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class OtherNotation: public Value<std::string>, public PrintObject, public PrintStyle, public Placement
  {
  public:
    OtherNotation();
    virtual const char* tagname() const { return "other-notation"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopSingleEnum type() const;
    void type(StartStopSingleEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopSingleEnum _type;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //OTHER_NOTATION_H
