#include "MetronomeBeam.h"
#include <cstring>

namespace mxml
{
  MetronomeBeam::MetronomeBeam() {}
  bool MetronomeBeam::hasNumber() const { return _hasNumber; }
  void MetronomeBeam::hasNumber(bool value) { _hasNumber = value; }
  int MetronomeBeam::number() const { return _number; }
  void MetronomeBeam::number(int value) { _number = value; }

  void MetronomeBeam::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void MetronomeBeam::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
}
