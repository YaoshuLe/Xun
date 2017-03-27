#include "YPosition.h"
#include <cstring>

namespace mxml
{
  YPosition::YPosition() {}
  bool YPosition::hasDefaultX() const { return _hasDefaultX; }
  void YPosition::hasDefaultX(bool value) { _hasDefaultX = value; }
  float YPosition::defaultX() const { return _defaultX; }
  void YPosition::defaultX(float value) { _defaultX = value; }
  bool YPosition::hasDefaultY() const { return _hasDefaultY; }
  void YPosition::hasDefaultY(bool value) { _hasDefaultY = value; }
  float YPosition::defaultY() const { return _defaultY; }
  void YPosition::defaultY(float value) { _defaultY = value; }
  bool YPosition::hasRelativeX() const { return _hasRelativeX; }
  void YPosition::hasRelativeX(bool value) { _hasRelativeX = value; }
  float YPosition::relativeX() const { return _relativeX; }
  void YPosition::relativeX(float value) { _relativeX = value; }
  bool YPosition::hasRelativeY() const { return _hasRelativeY; }
  void YPosition::hasRelativeY(bool value) { _hasRelativeY = value; }
  float YPosition::relativeY() const { return _relativeY; }
  void YPosition::relativeY(float value) { _relativeY = value; }

  void YPosition::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasDefaultX) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _defaultX);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("default-x").set_value(str);
    }
    if(_hasDefaultY) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _defaultY);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("default-y").set_value(str);
    }
    if(_hasRelativeX) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _relativeX);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("relative-x").set_value(str);
    }
    if(_hasRelativeY) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _relativeY);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("relative-y").set_value(str);
    }
  }
  void YPosition::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("default-x")) {
      _defaultX = attr.as_float();
      _hasDefaultX = true;
    }
    if(auto attr = self.attribute("default-y")) {
      _defaultY = attr.as_float();
      _hasDefaultY = true;
    }
    if(auto attr = self.attribute("relative-x")) {
      _relativeX = attr.as_float();
      _hasRelativeX = true;
    }
    if(auto attr = self.attribute("relative-y")) {
      _relativeY = attr.as_float();
      _hasRelativeY = true;
    }
  }
}
