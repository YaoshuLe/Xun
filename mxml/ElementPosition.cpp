#include "ElementPosition.h"
#include <cstring>

namespace mxml
{
  ElementPosition::ElementPosition() {}
  bool ElementPosition::hasElement() const { return _hasElement; }
  void ElementPosition::hasElement(bool value) { _hasElement = value; }
  std::string ElementPosition::element() const { return _element; }
  void ElementPosition::element(std::string value) { _element = value; }
  bool ElementPosition::hasPosition() const { return _hasPosition; }
  void ElementPosition::hasPosition(bool value) { _hasPosition = value; }
  int ElementPosition::position() const { return _position; }
  void ElementPosition::position(int value) { _position = value; }

  void ElementPosition::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasElement) {
      self.append_attribute("element").set_value(_element.c_str());
    }
    if(_hasPosition) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _position);
      self.append_attribute("position").set_value(str);
    }
  }
  void ElementPosition::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("element")) {
      _element = attr.as_string();
      _hasElement = true;
    }
    if(auto attr = self.attribute("position")) {
      _position = attr.as_int();
      _hasPosition = true;
    }
  }
}
