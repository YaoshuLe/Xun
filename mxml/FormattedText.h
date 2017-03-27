#ifndef FORMATTED_TEXT_H
#define FORMATTED_TEXT_H
#include "Element.h"
#include "TextFormatting.h"

namespace mxml
{
  class FormattedText: public Value<std::string>, public TextFormatting
  {
  public:
    FormattedText();
    virtual const char* tagname() const { return "formatted-text"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //FORMATTED_TEXT_H
