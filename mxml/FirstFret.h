#ifndef FIRST_FRET_H
#define FIRST_FRET_H
#include "Element.h"

namespace mxml
{
  class FirstFret: public Value<int>
  {
  public:
    FirstFret();
    virtual const char* tagname() const { return "first-fret"; }
    bool hasText() const;
    void hasText(bool value);
    std::string text() const;
    void text(std::string value);
    bool hasLocation() const;
    void hasLocation(bool value);
    LeftRightEnum location() const;
    void location(LeftRightEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasText {false};
    std::string _text;
    bool _hasLocation {false};
    LeftRightEnum _location;
  };
}
#endif //FIRST_FRET_H
