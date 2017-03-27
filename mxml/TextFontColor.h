#ifndef TEXT_FONT_COLOR_H
#define TEXT_FONT_COLOR_H
#include "Element.h"
#include "Font.h"
#include "Color.h"
#include "TextDecoration.h"
#include "TextRotation.h"
#include "LetterSpacing.h"
#include "TextDirection.h"

namespace mxml
{
  class TextFontColor: public Value<std::string>, public Font, public Color, public TextDecoration, public TextRotation, public LetterSpacing, public TextDirection
  {
  public:
    TextFontColor();
    virtual const char* tagname() const { return "text-font-color"; }
    bool hasLang() const;
    void hasLang(bool value);
    std::string lang() const;
    void lang(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLang {false};
    std::string _lang;
  };
}
#endif //TEXT_FONT_COLOR_H
