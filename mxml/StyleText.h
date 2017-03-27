#ifndef STYLE_TEXT_H
#define STYLE_TEXT_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class StyleText: public Value<std::string>, public PrintStyle
  {
  public:
    StyleText();
    virtual const char* tagname() const { return "style-text"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //STYLE_TEXT_H
