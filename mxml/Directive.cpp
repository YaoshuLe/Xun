#include "Directive.h"
#include <cstring>

namespace mxml
{
  Directive::Directive() {}
  bool Directive::hasDirective() const { return _hasDirective; }
  void Directive::hasDirective(bool value) { _hasDirective = value; }
  YesNoEnum Directive::directive() const { return _directive; }
  void Directive::directive(YesNoEnum value) { _directive = value; }

  void Directive::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasDirective) {
      self.append_attribute("directive").set_value(_directive.operator const char *());
    }
  }
  void Directive::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("directive")) {
      _directive = YesNoEnum(attr.as_string());
      _hasDirective = true;
    }
  }
}
