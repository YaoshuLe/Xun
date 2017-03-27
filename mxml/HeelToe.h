#ifndef HEEL_TOE_H
#define HEEL_TOE_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class HeelToe: public Empty, public PrintStyle, public Placement
  {
  public:
    HeelToe();
    virtual const char* tagname() const { return "heel-toe"; }
    bool hasSubstitution() const;
    void hasSubstitution(bool value);
    YesNoEnum substitution() const;
    void substitution(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasSubstitution {false};
    YesNoEnum _substitution;
  };
}
#endif //HEEL_TOE_H
