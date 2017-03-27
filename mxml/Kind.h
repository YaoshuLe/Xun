#ifndef KIND_H
#define KIND_H
#include "Element.h"
#include "PrintStyle.h"
#include "Halign.h"
#include "Valign.h"

namespace mxml
{
  class Kind: public Value<KindValueEnum>, public PrintStyle, public Halign, public Valign
  {
  public:
    Kind();
    virtual const char* tagname() const { return "kind"; }
    bool hasUseSymbols() const;
    void hasUseSymbols(bool value);
    YesNoEnum useSymbols() const;
    void useSymbols(YesNoEnum value);
    bool hasText() const;
    void hasText(bool value);
    std::string text() const;
    void text(std::string value);
    bool hasStackDegrees() const;
    void hasStackDegrees(bool value);
    YesNoEnum stackDegrees() const;
    void stackDegrees(YesNoEnum value);
    bool hasParenthesesDegrees() const;
    void hasParenthesesDegrees(bool value);
    YesNoEnum parenthesesDegrees() const;
    void parenthesesDegrees(YesNoEnum value);
    bool hasBracketDegrees() const;
    void hasBracketDegrees(bool value);
    YesNoEnum bracketDegrees() const;
    void bracketDegrees(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasUseSymbols {false};
    YesNoEnum _useSymbols;
    bool _hasText {false};
    std::string _text;
    bool _hasStackDegrees {false};
    YesNoEnum _stackDegrees;
    bool _hasParenthesesDegrees {false};
    YesNoEnum _parenthesesDegrees;
    bool _hasBracketDegrees {false};
    YesNoEnum _bracketDegrees;
  };
}
#endif //KIND_H
