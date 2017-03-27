#include "Printout.h"
#include <cstring>

namespace mxml
{
  Printout::Printout() {}
  bool Printout::hasPrintDot() const { return _hasPrintDot; }
  void Printout::hasPrintDot(bool value) { _hasPrintDot = value; }
  YesNoEnum Printout::printDot() const { return _printDot; }
  void Printout::printDot(YesNoEnum value) { _printDot = value; }
  bool Printout::hasPrintLyric() const { return _hasPrintLyric; }
  void Printout::hasPrintLyric(bool value) { _hasPrintLyric = value; }
  YesNoEnum Printout::printLyric() const { return _printLyric; }
  void Printout::printLyric(YesNoEnum value) { _printLyric = value; }

  void Printout::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintSpacing::ostreamAttrs(self);
    if(_hasPrintDot) {
      self.append_attribute("print-dot").set_value(_printDot.operator const char *());
    }
    if(_hasPrintLyric) {
      self.append_attribute("print-lyric").set_value(_printLyric.operator const char *());
    }
  }
  void Printout::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintSpacing::istreamAttrs(self);
    if(auto attr = self.attribute("print-dot")) {
      _printDot = YesNoEnum(attr.as_string());
      _hasPrintDot = true;
    }
    if(auto attr = self.attribute("print-lyric")) {
      _printLyric = YesNoEnum(attr.as_string());
      _hasPrintLyric = true;
    }
  }
}
