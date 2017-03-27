#include "Link.h"
#include <cstring>

namespace mxml
{
  Link::Link() {}
  bool Link::hasName() const { return _hasName; }
  void Link::hasName(bool value) { _hasName = value; }
  std::string Link::name() const { return _name; }
  void Link::name(std::string value) { _name = value; }

  void Link::ostreamAttrs(pugi::xml_node& self) const
  {
    LinkAttributes::ostreamAttrs(self);
    ElementPosition::ostreamAttrs(self);
    Position::ostreamAttrs(self);
    if(_hasName) {
      self.append_attribute("name").set_value(_name.c_str());
    }
  }
  void Link::istreamAttrs(const pugi::xml_node& self)
  {
    LinkAttributes::istreamAttrs(self);
    ElementPosition::istreamAttrs(self);
    Position::istreamAttrs(self);
    if(auto attr = self.attribute("name")) {
      _name = attr.as_string();
      _hasName = true;
    }
  }
}
