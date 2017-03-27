#include "ValignImage.h"
#include <cstring>

namespace mxml
{
  ValignImage::ValignImage() {}
  bool ValignImage::hasValign() const { return _hasValign; }
  void ValignImage::hasValign(bool value) { _hasValign = value; }
  ValignImageEnum ValignImage::valign() const { return _valign; }
  void ValignImage::valign(ValignImageEnum value) { _valign = value; }

  void ValignImage::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasValign) {
      self.append_attribute("valign").set_value(_valign.operator const char *());
    }
  }
  void ValignImage::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("valign")) {
      _valign = ValignImageEnum(attr.as_string());
      _hasValign = true;
    }
  }
}
