#include "PrincipalVoice.h"
#include <cstring>

namespace mxml
{
  PrincipalVoice::PrincipalVoice() {}
  bool PrincipalVoice::hasType() const { return _hasType; }
  void PrincipalVoice::hasType(bool value) { _hasType = value; }
  StartStopEnum PrincipalVoice::type() const { return _type; }
  void PrincipalVoice::type(StartStopEnum value) { _type = value; }
  bool PrincipalVoice::hasSymbol() const { return _hasSymbol; }
  void PrincipalVoice::hasSymbol(bool value) { _hasSymbol = value; }
  PrincipalVoiceSymbolEnum PrincipalVoice::symbol() const { return _symbol; }
  void PrincipalVoice::symbol(PrincipalVoiceSymbolEnum value) { _symbol = value; }

  void PrincipalVoice::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasSymbol) {
      self.append_attribute("symbol").set_value(_symbol.operator const char *());
    }
  }
  void PrincipalVoice::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("symbol")) {
      _symbol = PrincipalVoiceSymbolEnum(attr.as_string());
      _hasSymbol = true;
    }
  }
}
