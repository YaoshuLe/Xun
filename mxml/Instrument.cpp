#include "Instrument.h"
#include <cstring>

namespace mxml
{
  Instrument::Instrument() {}
  bool Instrument::hasId() const { return _hasId; }
  void Instrument::hasId(bool value) { _hasId = value; }
  std::string Instrument::id() const { return _id; }
  void Instrument::id(std::string value) { _id = value; }

  void Instrument::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasId) {
      self.append_attribute("id").set_value(_id.c_str());
    }
  }
  void Instrument::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("id")) {
      _id = attr.as_string();
      _hasId = true;
    }
  }
}
