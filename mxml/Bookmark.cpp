#include "Bookmark.h"
#include <cstring>

namespace mxml
{
  Bookmark::Bookmark() {}
  bool Bookmark::hasId() const { return _hasId; }
  void Bookmark::hasId(bool value) { _hasId = value; }
  std::string Bookmark::id() const { return _id; }
  void Bookmark::id(std::string value) { _id = value; }
  bool Bookmark::hasName() const { return _hasName; }
  void Bookmark::hasName(bool value) { _hasName = value; }
  std::string Bookmark::name() const { return _name; }
  void Bookmark::name(std::string value) { _name = value; }

  void Bookmark::ostreamAttrs(pugi::xml_node& self) const
  {
    ElementPosition::ostreamAttrs(self);
    if(_hasId) {
      self.append_attribute("id").set_value(_id.c_str());
    }
    if(_hasName) {
      self.append_attribute("name").set_value(_name.c_str());
    }
  }
  void Bookmark::istreamAttrs(const pugi::xml_node& self)
  {
    ElementPosition::istreamAttrs(self);
    if(auto attr = self.attribute("id")) {
      _id = attr.as_string();
      _hasId = true;
    }
    if(auto attr = self.attribute("name")) {
      _name = attr.as_string();
      _hasName = true;
    }
  }
}
