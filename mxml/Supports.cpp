#include "Supports.h"
#include <cstring>

namespace mxml
{
  Supports::Supports() {}
  bool Supports::hasType() const { return _hasType; }
  void Supports::hasType(bool value) { _hasType = value; }
  YesNoEnum Supports::type() const { return _type; }
  void Supports::type(YesNoEnum value) { _type = value; }
  bool Supports::hasElement() const { return _hasElement; }
  void Supports::hasElement(bool value) { _hasElement = value; }
  std::string Supports::element() const { return _element; }
  void Supports::element(std::string value) { _element = value; }
  bool Supports::hasAttribute() const { return _hasAttribute; }
  void Supports::hasAttribute(bool value) { _hasAttribute = value; }
  std::string Supports::attribute() const { return _attribute; }
  void Supports::attribute(std::string value) { _attribute = value; }
  bool Supports::hasValue() const { return _hasValue; }
  void Supports::hasValue(bool value) { _hasValue = value; }
  std::string Supports::value() const { return _value; }
  void Supports::value(std::string value) { _value = value; }

  void Supports::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasElement) {
      self.append_attribute("element").set_value(_element.c_str());
    }
    if(_hasAttribute) {
      self.append_attribute("attribute").set_value(_attribute.c_str());
    }
    if(_hasValue) {
      self.append_attribute("value").set_value(_value.c_str());
    }
  }
  void Supports::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = YesNoEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("element")) {
      _element = attr.as_string();
      _hasElement = true;
    }
    if(auto attr = self.attribute("attribute")) {
      _attribute = attr.as_string();
      _hasAttribute = true;
    }
    if(auto attr = self.attribute("value")) {
      _value = attr.as_string();
      _hasValue = true;
    }
  }
}
