#ifndef HORIZONTAL_TURN_H
#define HORIZONTAL_TURN_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"
#include "TrillSound.h"

namespace mxml
{
  class HorizontalTurn: public Empty, public PrintStyle, public Placement, public TrillSound
  {
  public:
    HorizontalTurn();
    virtual const char* tagname() const { return "horizontal-turn"; }
    bool hasSlash() const;
    void hasSlash(bool value);
    YesNoEnum slash() const;
    void slash(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasSlash {false};
    YesNoEnum _slash;
  };
}
#endif //HORIZONTAL_TURN_H
