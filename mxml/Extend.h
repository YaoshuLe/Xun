#ifndef EXTEND_H
#define EXTEND_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class Extend: public Empty, public PrintStyle
  {
  public:
    Extend();
    virtual const char* tagname() const { return "extend"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopContinueEnum type() const;
    void type(StartStopContinueEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopContinueEnum _type;
  };
}
#endif //EXTEND_H
