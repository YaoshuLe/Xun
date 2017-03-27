#include "Ending.h"
#include <cstring>

namespace mxml
{
  Ending::Ending() {}
  bool Ending::hasNumber() const { return _hasNumber; }
  void Ending::hasNumber(bool value) { _hasNumber = value; }
  std::string Ending::number() const { return _number; }
  void Ending::number(std::string value) { _number = value; }
  bool Ending::hasType() const { return _hasType; }
  void Ending::hasType(bool value) { _hasType = value; }
  StartStopDiscontinueEnum Ending::type() const { return _type; }
  void Ending::type(StartStopDiscontinueEnum value) { _type = value; }
  bool Ending::hasEndLength() const { return _hasEndLength; }
  void Ending::hasEndLength(bool value) { _hasEndLength = value; }
  float Ending::endLength() const { return _endLength; }
  void Ending::endLength(float value) { _endLength = value; }
  bool Ending::hasTextX() const { return _hasTextX; }
  void Ending::hasTextX(bool value) { _hasTextX = value; }
  float Ending::textX() const { return _textX; }
  void Ending::textX(float value) { _textX = value; }
  bool Ending::hasTextY() const { return _hasTextY; }
  void Ending::hasTextY(bool value) { _hasTextY = value; }
  float Ending::textY() const { return _textY; }
  void Ending::textY(float value) { _textY = value; }

  void Ending::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    if(_hasNumber) {
      self.append_attribute("number").set_value(_number.c_str());
    }
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasEndLength) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _endLength);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("end-length").set_value(str);
    }
    if(_hasTextX) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _textX);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("text-x").set_value(str);
    }
    if(_hasTextY) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _textY);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("text-y").set_value(str);
    }
  }
  void Ending::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_string();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("type")) {
      _type = StartStopDiscontinueEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("end-length")) {
      _endLength = attr.as_float();
      _hasEndLength = true;
    }
    if(auto attr = self.attribute("text-x")) {
      _textX = attr.as_float();
      _hasTextX = true;
    }
    if(auto attr = self.attribute("text-y")) {
      _textY = attr.as_float();
      _hasTextY = true;
    }
  }
}
