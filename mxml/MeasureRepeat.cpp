#include "MeasureRepeat.h"
#include <cstring>

namespace mxml
{
  MeasureRepeat::MeasureRepeat() {}
  bool MeasureRepeat::hasType() const { return _hasType; }
  void MeasureRepeat::hasType(bool value) { _hasType = value; }
  StartStopEnum MeasureRepeat::type() const { return _type; }
  void MeasureRepeat::type(StartStopEnum value) { _type = value; }
  bool MeasureRepeat::hasSlashes() const { return _hasSlashes; }
  void MeasureRepeat::hasSlashes(bool value) { _hasSlashes = value; }
  int MeasureRepeat::slashes() const { return _slashes; }
  void MeasureRepeat::slashes(int value) { _slashes = value; }

  void MeasureRepeat::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasSlashes) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _slashes);
      self.append_attribute("slashes").set_value(str);
    }
  }
  void MeasureRepeat::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("slashes")) {
      _slashes = attr.as_int();
      _hasSlashes = true;
    }
  }
}
