#ifndef FINGERING_H
#define FINGERING_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class Fingering: public Value<std::string>, public PrintStyle, public Placement
  {
  public:
    Fingering();
    virtual const char* tagname() const { return "fingering"; }
    bool hasSubstitution() const;
    void hasSubstitution(bool value);
    YesNoEnum substitution() const;
    void substitution(YesNoEnum value);
    bool hasAlternate() const;
    void hasAlternate(bool value);
    YesNoEnum alternate() const;
    void alternate(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasSubstitution {false};
    YesNoEnum _substitution;
    bool _hasAlternate {false};
    YesNoEnum _alternate;
  };
}
#endif //FINGERING_H
