#ifndef LETTER_SPACING_H
#define LETTER_SPACING_H
#include "AttrGroup.h"

namespace mxml
{
  class LetterSpacing: public AttrGroup
  {
  public:
    LetterSpacing();
    bool hasLetterSpacing() const;
    void hasLetterSpacing(bool value);
    NumberOrNormalEnum letterSpacing() const;
    void letterSpacing(NumberOrNormalEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLetterSpacing {false};
    NumberOrNormalEnum _letterSpacing;
  };
}
#endif //LETTER_SPACING_H
