#ifndef ACCIDENTAL_TEXT_H
#define ACCIDENTAL_TEXT_H
#include "Element.h"
#include "TextFormatting.h"

namespace mxml
{
  class AccidentalText: public Value<AccidentalValueEnum>, public TextFormatting
  {
  public:
    AccidentalText();
    virtual const char* tagname() const { return "accidental-text"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //ACCIDENTAL_TEXT_H
