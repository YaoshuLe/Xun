#ifndef DEGREE_TYPE_H
#define DEGREE_TYPE_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class DegreeType: public Value<DegreeTypeValueEnum>, public PrintStyle
  {
  public:
    DegreeType();
    virtual const char* tagname() const { return "degree-type"; }
    bool hasText() const;
    void hasText(bool value);
    std::string text() const;
    void text(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasText {false};
    std::string _text;
  };
}
#endif //DEGREE_TYPE_H
