#ifndef LEVEL_DISPLAY_H
#define LEVEL_DISPLAY_H
#include "AttrGroup.h"

namespace mxml
{
  class LevelDisplay: public AttrGroup
  {
  public:
    LevelDisplay();
    bool hasParentheses() const;
    void hasParentheses(bool value);
    YesNoEnum parentheses() const;
    void parentheses(YesNoEnum value);
    bool hasBracket() const;
    void hasBracket(bool value);
    YesNoEnum bracket() const;
    void bracket(YesNoEnum value);
    bool hasSize() const;
    void hasSize(bool value);
    SymbolSizeEnum size() const;
    void size(SymbolSizeEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasParentheses {false};
    YesNoEnum _parentheses;
    bool _hasBracket {false};
    YesNoEnum _bracket;
    bool _hasSize {false};
    SymbolSizeEnum _size;
  };
}
#endif //LEVEL_DISPLAY_H
