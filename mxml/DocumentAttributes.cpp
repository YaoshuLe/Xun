#include "DocumentAttributes.h"
#include <cstring>

namespace mxml
{
  DocumentAttributes::DocumentAttributes() {}
  bool DocumentAttributes::hasVersion() const { return _hasVersion; }
  void DocumentAttributes::hasVersion(bool value) { _hasVersion = value; }
  std::string DocumentAttributes::version() const { return _version; }
  void DocumentAttributes::version(std::string value) { _version = value; }

  void DocumentAttributes::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasVersion) {
      self.append_attribute("version").set_value(_version.c_str());
    }
  }
  void DocumentAttributes::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("version")) {
      _version = attr.as_string();
      _hasVersion = true;
    }
  }
}
