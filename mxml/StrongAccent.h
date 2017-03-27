#ifndef STRONG_ACCENT_H
#define STRONG_ACCENT_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class StrongAccent: public Empty, public PrintStyle, public Placement
  {
  public:
    StrongAccent();
    virtual const char* tagname() const { return "strong-accent"; }
    bool hasType() const;
    void hasType(bool value);
    UpDownEnum type() const;
    void type(UpDownEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    UpDownEnum _type;
  };
}
#endif //STRONG_ACCENT_H
