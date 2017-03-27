#ifndef ACCIDENTAL_MARK_H
#define ACCIDENTAL_MARK_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class AccidentalMark: public Value<AccidentalValueEnum>, public PrintStyle, public Placement
  {
  public:
    AccidentalMark();
    virtual const char* tagname() const { return "accidental-mark"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //ACCIDENTAL_MARK_H
