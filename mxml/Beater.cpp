#include "Beater.h"
#include <cstring>

namespace mxml
{
  Beater::Beater() {}
  bool Beater::hasTip() const { return _hasTip; }
  void Beater::hasTip(bool value) { _hasTip = value; }
  TipDirectionEnum Beater::tip() const { return _tip; }
  void Beater::tip(TipDirectionEnum value) { _tip = value; }

  void Beater::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasTip) {
      self.append_attribute("tip").set_value(_tip.operator const char *());
    }
  }
  void Beater::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("tip")) {
      _tip = TipDirectionEnum(attr.as_string());
      _hasTip = true;
    }
  }
}
