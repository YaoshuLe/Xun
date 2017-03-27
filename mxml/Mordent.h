#ifndef MORDENT_H
#define MORDENT_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"
#include "TrillSound.h"

namespace mxml
{
  class Mordent: public Empty, public PrintStyle, public Placement, public TrillSound
  {
  public:
    Mordent();
    virtual const char* tagname() const { return "mordent"; }
    bool hasLength() const;
    void hasLength(bool value);
    YesNoEnum length() const;
    void length(YesNoEnum value);
    bool hasApproach() const;
    void hasApproach(bool value);
    AboveBelowEnum approach() const;
    void approach(AboveBelowEnum value);
    bool hasDeparture() const;
    void hasDeparture(bool value);
    AboveBelowEnum departure() const;
    void departure(AboveBelowEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLength {false};
    YesNoEnum _length;
    bool _hasApproach {false};
    AboveBelowEnum _approach;
    bool _hasDeparture {false};
    AboveBelowEnum _departure;
  };
}
#endif //MORDENT_H
