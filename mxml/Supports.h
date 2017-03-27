#ifndef SUPPORTS_H
#define SUPPORTS_H
#include "Element.h"

namespace mxml
{
  class Supports: public Empty
  {
  public:
    Supports();
    virtual const char* tagname() const { return "supports"; }
    bool hasType() const;
    void hasType(bool value);
    YesNoEnum type() const;
    void type(YesNoEnum value);
    bool hasElement() const;
    void hasElement(bool value);
    std::string element() const;
    void element(std::string value);
    bool hasAttribute() const;
    void hasAttribute(bool value);
    std::string attribute() const;
    void attribute(std::string value);
    bool hasValue() const;
    void hasValue(bool value);
    std::string value() const;
    void value(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    YesNoEnum _type;
    bool _hasElement {false};
    std::string _element;
    bool _hasAttribute {false};
    std::string _attribute;
    bool _hasValue {false};
    std::string _value;
  };
}
#endif //SUPPORTS_H
