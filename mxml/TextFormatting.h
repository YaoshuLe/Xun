#ifndef TEXT_FORMATTING_H
#define TEXT_FORMATTING_H
#include "Justify.h"
#include "PrintStyleAlign.h"
#include "TextDecoration.h"
#include "TextRotation.h"
#include "LetterSpacing.h"
#include "LineHeight.h"
#include "TextDirection.h"
#include "Enclosure.h"

namespace mxml
{
  class TextFormatting: public Justify, public PrintStyleAlign, public TextDecoration, public TextRotation, public LetterSpacing, public LineHeight, public TextDirection, public Enclosure
  {
  public:
    TextFormatting();
    bool hasLang() const;
    void hasLang(bool value);
    std::string lang() const;
    void lang(std::string value);
    bool hasSpace() const;
    void hasSpace(bool value);
    std::string space() const;
    void space(std::string value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLang {false};
    std::string _lang;
    bool _hasSpace {false};
    std::string _space;
  };
}
#endif //TEXT_FORMATTING_H
