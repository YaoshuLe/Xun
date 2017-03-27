#include "PartSymbol.h"
#include <cstring>

namespace mxml
{
  PartSymbol::PartSymbol() {}
  bool PartSymbol::hasTopStaff() const { return _hasTopStaff; }
  void PartSymbol::hasTopStaff(bool value) { _hasTopStaff = value; }
  int PartSymbol::topStaff() const { return _topStaff; }
  void PartSymbol::topStaff(int value) { _topStaff = value; }
  bool PartSymbol::hasBottomStaff() const { return _hasBottomStaff; }
  void PartSymbol::hasBottomStaff(bool value) { _hasBottomStaff = value; }
  int PartSymbol::bottomStaff() const { return _bottomStaff; }
  void PartSymbol::bottomStaff(int value) { _bottomStaff = value; }

  void PartSymbol::ostreamAttrs(pugi::xml_node& self) const
  {
    Position::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    if(_hasTopStaff) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _topStaff);
      self.append_attribute("top-staff").set_value(str);
    }
    if(_hasBottomStaff) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _bottomStaff);
      self.append_attribute("bottom-staff").set_value(str);
    }
  }
  void PartSymbol::istreamAttrs(const pugi::xml_node& self)
  {
    Position::istreamAttrs(self);
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("top-staff")) {
      _topStaff = attr.as_int();
      _hasTopStaff = true;
    }
    if(auto attr = self.attribute("bottom-staff")) {
      _bottomStaff = attr.as_int();
      _hasBottomStaff = true;
    }
  }
}
