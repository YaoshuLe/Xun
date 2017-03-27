#include "OctaveShift.h"
#include <cstring>

namespace mxml
{
  OctaveShift::OctaveShift() {}
  bool OctaveShift::hasType() const { return _hasType; }
  void OctaveShift::hasType(bool value) { _hasType = value; }
  UpDownStopContinueEnum OctaveShift::type() const { return _type; }
  void OctaveShift::type(UpDownStopContinueEnum value) { _type = value; }
  bool OctaveShift::hasNumber() const { return _hasNumber; }
  void OctaveShift::hasNumber(bool value) { _hasNumber = value; }
  int OctaveShift::number() const { return _number; }
  void OctaveShift::number(int value) { _number = value; }
  bool OctaveShift::hasSize() const { return _hasSize; }
  void OctaveShift::hasSize(bool value) { _hasSize = value; }
  int OctaveShift::size() const { return _size; }
  void OctaveShift::size(int value) { _size = value; }

  void OctaveShift::ostreamAttrs(pugi::xml_node& self) const
  {
    DashedFormatting::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasSize) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _size);
      self.append_attribute("size").set_value(str);
    }
  }
  void OctaveShift::istreamAttrs(const pugi::xml_node& self)
  {
    DashedFormatting::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = UpDownStopContinueEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("size")) {
      _size = attr.as_int();
      _hasSize = true;
    }
  }
}
