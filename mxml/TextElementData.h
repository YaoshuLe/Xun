#ifndef TEXT_ELEMENT_DATA_H
#define TEXT_ELEMENT_DATA_H
#include "Element.h"
#include "Font.h"
#include "Color.h"
#include "TextDecoration.h"
#include "TextRotation.h"
#include "LetterSpacing.h"
#include "TextDirection.h"

namespace mxml
{
  class TextElementData: public Value<std::string>, public Font, public Color, public TextDecoration, public TextRotation, public LetterSpacing, public TextDirection
  {
  public:
    TextElementData();
    virtual const char* tagname() const { return "text-element-data"; }
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
#endif //TEXT_ELEMENT_DATA_H
