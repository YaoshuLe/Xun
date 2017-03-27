#ifndef DEGREE_VALUE_H
#define DEGREE_VALUE_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class DegreeValue: public Value<int>, public PrintStyle
  {
  public:
    DegreeValue();
    virtual const char* tagname() const { return "degree-value"; }
    bool hasSymbol() const;
    void hasSymbol(bool value);
    DegreeSymbolValueEnum symbol() const;
    void symbol(DegreeSymbolValueEnum value);
    bool hasText() const;
    void hasText(bool value);
    std::string text() const;
    void text(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasSymbol {false};
    DegreeSymbolValueEnum _symbol;
    bool _hasText {false};
    std::string _text;
  };
}
#endif //DEGREE_VALUE_H
