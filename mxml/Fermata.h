#ifndef FERMATA_H
#define FERMATA_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class Fermata: public Value<FermataShapeEnum>, public PrintStyle
  {
  public:
    Fermata();
    virtual const char* tagname() const { return "fermata"; }
    bool hasType() const;
    void hasType(bool value);
    UprightInvertedEnum type() const;
    void type(UprightInvertedEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    UprightInvertedEnum _type;
  };
}
#endif //FERMATA_H
