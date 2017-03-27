#include "DashedFormatting.h"
#include <cstring>

namespace mxml
{
  DashedFormatting::DashedFormatting() {}
  bool DashedFormatting::hasDashLength() const { return _hasDashLength; }
  void DashedFormatting::hasDashLength(bool value) { _hasDashLength = value; }
  float DashedFormatting::dashLength() const { return _dashLength; }
  void DashedFormatting::dashLength(float value) { _dashLength = value; }
  bool DashedFormatting::hasSpaceLength() const { return _hasSpaceLength; }
  void DashedFormatting::hasSpaceLength(bool value) { _hasSpaceLength = value; }
  float DashedFormatting::spaceLength() const { return _spaceLength; }
  void DashedFormatting::spaceLength(float value) { _spaceLength = value; }

  void DashedFormatting::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasDashLength) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _dashLength);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("dash-length").set_value(str);
    }
    if(_hasSpaceLength) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _spaceLength);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("space-length").set_value(str);
    }
  }
  void DashedFormatting::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("dash-length")) {
      _dashLength = attr.as_float();
      _hasDashLength = true;
    }
    if(auto attr = self.attribute("space-length")) {
      _spaceLength = attr.as_float();
      _hasSpaceLength = true;
    }
  }
}
