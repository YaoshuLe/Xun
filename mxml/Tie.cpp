#include "Tie.h"
#include <cstring>

namespace mxml
{
  Tie::Tie() {}
  bool Tie::hasType() const { return _hasType; }
  void Tie::hasType(bool value) { _hasType = value; }
  StartStopEnum Tie::type() const { return _type; }
  void Tie::type(StartStopEnum value) { _type = value; }
  bool Tie::hasTimeOnly() const { return _hasTimeOnly; }
  void Tie::hasTimeOnly(bool value) { _hasTimeOnly = value; }
  std::string Tie::timeOnly() const { return _timeOnly; }
  void Tie::timeOnly(std::string value) { _timeOnly = value; }

  void Tie::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasTimeOnly) {
      self.append_attribute("time-only").set_value(_timeOnly.c_str());
    }
  }
  void Tie::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("time-only")) {
      _timeOnly = attr.as_string();
      _hasTimeOnly = true;
    }
  }
}
