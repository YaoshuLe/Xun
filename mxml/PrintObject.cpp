#include "PrintObject.h"
#include <cstring>

namespace mxml
{
  PrintObject::PrintObject() {}
  bool PrintObject::hasPrintObject() const { return _hasPrintObject; }
  void PrintObject::hasPrintObject(bool value) { _hasPrintObject = value; }
  YesNoEnum PrintObject::printObject() const { return _printObject; }
  void PrintObject::printObject(YesNoEnum value) { _printObject = value; }

  void PrintObject::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasPrintObject) {
      self.append_attribute("print-object").set_value(_printObject.operator const char *());
    }
  }
  void PrintObject::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("print-object")) {
      _printObject = YesNoEnum(attr.as_string());
      _hasPrintObject = true;
    }
  }
}
