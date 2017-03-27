#ifndef BREATH_MARK_H
#define BREATH_MARK_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class BreathMark: public Value<BreathMarkValueEnum>, public PrintStyle, public Placement
  {
  public:
    BreathMark();
    virtual const char* tagname() const { return "breath-mark"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //BREATH_MARK_H
