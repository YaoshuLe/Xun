#include "Grace.h"
#include <cstring>

namespace mxml
{
  Grace::Grace() {}
  bool Grace::hasStealTimePrevious() const { return _hasStealTimePrevious; }
  void Grace::hasStealTimePrevious(bool value) { _hasStealTimePrevious = value; }
  float Grace::stealTimePrevious() const { return _stealTimePrevious; }
  void Grace::stealTimePrevious(float value) { _stealTimePrevious = value; }
  bool Grace::hasStealTimeFollowing() const { return _hasStealTimeFollowing; }
  void Grace::hasStealTimeFollowing(bool value) { _hasStealTimeFollowing = value; }
  float Grace::stealTimeFollowing() const { return _stealTimeFollowing; }
  void Grace::stealTimeFollowing(float value) { _stealTimeFollowing = value; }
  bool Grace::hasMakeTime() const { return _hasMakeTime; }
  void Grace::hasMakeTime(bool value) { _hasMakeTime = value; }
  float Grace::makeTime() const { return _makeTime; }
  void Grace::makeTime(float value) { _makeTime = value; }
  bool Grace::hasSlash() const { return _hasSlash; }
  void Grace::hasSlash(bool value) { _hasSlash = value; }
  YesNoEnum Grace::slash() const { return _slash; }
  void Grace::slash(YesNoEnum value) { _slash = value; }

  void Grace::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasStealTimePrevious) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _stealTimePrevious);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("steal-time-previous").set_value(str);
    }
    if(_hasStealTimeFollowing) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _stealTimeFollowing);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("steal-time-following").set_value(str);
    }
    if(_hasMakeTime) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _makeTime);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("make-time").set_value(str);
    }
    if(_hasSlash) {
      self.append_attribute("slash").set_value(_slash.operator const char *());
    }
  }
  void Grace::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("steal-time-previous")) {
      _stealTimePrevious = attr.as_float();
      _hasStealTimePrevious = true;
    }
    if(auto attr = self.attribute("steal-time-following")) {
      _stealTimeFollowing = attr.as_float();
      _hasStealTimeFollowing = true;
    }
    if(auto attr = self.attribute("make-time")) {
      _makeTime = attr.as_float();
      _hasMakeTime = true;
    }
    if(auto attr = self.attribute("slash")) {
      _slash = YesNoEnum(attr.as_string());
      _hasSlash = true;
    }
  }
}
