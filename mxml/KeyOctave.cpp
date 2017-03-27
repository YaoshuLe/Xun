#include "KeyOctave.h"
#include <cstring>

namespace mxml
{
  KeyOctave::KeyOctave() {}
  bool KeyOctave::hasNumber() const { return _hasNumber; }
  void KeyOctave::hasNumber(bool value) { _hasNumber = value; }
  int KeyOctave::number() const { return _number; }
  void KeyOctave::number(int value) { _number = value; }
  bool KeyOctave::hasCancel() const { return _hasCancel; }
  void KeyOctave::hasCancel(bool value) { _hasCancel = value; }
  YesNoEnum KeyOctave::cancel() const { return _cancel; }
  void KeyOctave::cancel(YesNoEnum value) { _cancel = value; }

  void KeyOctave::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasCancel) {
      self.append_attribute("cancel").set_value(_cancel.operator const char *());
    }
  }
  void KeyOctave::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("cancel")) {
      _cancel = YesNoEnum(attr.as_string());
      _hasCancel = true;
    }
  }
}
