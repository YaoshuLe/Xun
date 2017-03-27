#include "MultipleRest.h"
#include <cstring>

namespace mxml
{
  MultipleRest::MultipleRest() {}
  bool MultipleRest::hasUseSymbols() const { return _hasUseSymbols; }
  void MultipleRest::hasUseSymbols(bool value) { _hasUseSymbols = value; }
  YesNoEnum MultipleRest::useSymbols() const { return _useSymbols; }
  void MultipleRest::useSymbols(YesNoEnum value) { _useSymbols = value; }

  void MultipleRest::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasUseSymbols) {
      self.append_attribute("use-symbols").set_value(_useSymbols.operator const char *());
    }
  }
  void MultipleRest::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("use-symbols")) {
      _useSymbols = YesNoEnum(attr.as_string());
      _hasUseSymbols = true;
    }
  }
}
