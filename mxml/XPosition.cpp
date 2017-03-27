#include "XPosition.h"
#include <cstring>

namespace mxml
{
  XPosition::XPosition() {}
  bool XPosition::hasDefaultX() const { return _hasDefaultX; }
  void XPosition::hasDefaultX(bool value) { _hasDefaultX = value; }
  float XPosition::defaultX() const { return _defaultX; }
  void XPosition::defaultX(float value) { _defaultX = value; }
  bool XPosition::hasDefaultY() const { return _hasDefaultY; }
  void XPosition::hasDefaultY(bool value) { _hasDefaultY = value; }
  float XPosition::defaultY() const { return _defaultY; }
  void XPosition::defaultY(float value) { _defaultY = value; }
  bool XPosition::hasRelativeX() const { return _hasRelativeX; }
  void XPosition::hasRelativeX(bool value) { _hasRelativeX = value; }
  float XPosition::relativeX() const { return _relativeX; }
  void XPosition::relativeX(float value) { _relativeX = value; }
  bool XPosition::hasRelativeY() const { return _hasRelativeY; }
  void XPosition::hasRelativeY(bool value) { _hasRelativeY = value; }
  float XPosition::relativeY() const { return _relativeY; }
  void XPosition::relativeY(float value) { _relativeY = value; }

  void XPosition::ostreamAttrs(pugi::xml_node& self) const
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
  void XPosition::istreamAttrs(const pugi::xml_node& self)
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
