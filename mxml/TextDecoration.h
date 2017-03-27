#ifndef TEXT_DECORATION_H
#define TEXT_DECORATION_H
#include "AttrGroup.h"

namespace mxml
{
  class TextDecoration: public AttrGroup
  {
  public:
    TextDecoration();
    bool hasUnderline() const;
    void hasUnderline(bool value);
    int underline() const;
    void underline(int value);
    bool hasOverline() const;
    void hasOverline(bool value);
    int overline() const;
    void overline(int value);
    bool hasLineThrough() const;
    void hasLineThrough(bool value);
    int lineThrough() const;
    void lineThrough(int value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasUnderline {false};
    int _underline;
    bool _hasOverline {false};
    int _overline;
    bool _hasLineThrough {false};
    int _lineThrough;
  };
}
#endif //TEXT_DECORATION_H
