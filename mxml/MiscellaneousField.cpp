#include "MiscellaneousField.h"
#include <cstring>

namespace mxml
{
  MiscellaneousField::MiscellaneousField() {}
  bool MiscellaneousField::hasName() const { return _hasName; }
  void MiscellaneousField::hasName(bool value) { _hasName = value; }
  std::string MiscellaneousField::name() const { return _name; }
  void MiscellaneousField::name(std::string value) { _name = value; }

  void MiscellaneousField::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasName) {
      self.append_attribute("name").set_value(_name.c_str());
    }
  }
  void MiscellaneousField::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("name")) {
      _name = attr.as_string();
      _hasName = true;
    }
  }
}
