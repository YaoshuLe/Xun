#ifndef TYPED_TEXT_H
#define TYPED_TEXT_H
#include "Element.h"

namespace mxml
{
  class TypedText: public Value<std::string>
  {
  public:
    TypedText();
    virtual const char* tagname() const { return "typed-text"; }
    bool hasType() const;
    void hasType(bool value);
    std::string type() const;
    void type(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    std::string _type;
  };
}
#endif //TYPED_TEXT_H
