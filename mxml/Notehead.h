#ifndef NOTEHEAD_H
#define NOTEHEAD_H
#include "Element.h"
#include "Font.h"
#include "Color.h"

namespace mxml
{
  class Notehead: public Value<NoteheadValueEnum>, public Font, public Color
  {
  public:
    Notehead();
    virtual const char* tagname() const { return "notehead"; }
    bool hasFilled() const;
    void hasFilled(bool value);
    YesNoEnum filled() const;
    void filled(YesNoEnum value);
    bool hasParentheses() const;
    void hasParentheses(bool value);
    YesNoEnum parentheses() const;
    void parentheses(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasFilled {false};
    YesNoEnum _filled;
    bool _hasParentheses {false};
    YesNoEnum _parentheses;
  };
}
#endif //NOTEHEAD_H
