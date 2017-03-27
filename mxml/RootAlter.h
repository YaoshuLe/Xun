#ifndef ROOT_ALTER_H
#define ROOT_ALTER_H
#include "Element.h"
#include "PrintObject.h"
#include "PrintStyle.h"

namespace mxml
{
  class RootAlter: public Value<float>, public PrintObject, public PrintStyle
  {
  public:
    RootAlter();
    virtual const char* tagname() const { return "root-alter"; }
    bool hasLocation() const;
    void hasLocation(bool value);
    LeftRightEnum location() const;
    void location(LeftRightEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLocation {false};
    LeftRightEnum _location;
  };
}
#endif //ROOT_ALTER_H
