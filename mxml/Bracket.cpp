#include "Bracket.h"
#include <cstring>

namespace mxml
{
  Bracket::Bracket() {}
  bool Bracket::hasType() const { return _hasType; }
  void Bracket::hasType(bool value) { _hasType = value; }
  StartStopContinueEnum Bracket::type() const { return _type; }
  void Bracket::type(StartStopContinueEnum value) { _type = value; }
  bool Bracket::hasNumber() const { return _hasNumber; }
  void Bracket::hasNumber(bool value) { _hasNumber = value; }
  int Bracket::number() const { return _number; }
  void Bracket::number(int value) { _number = value; }
  bool Bracket::hasLineEnd() const { return _hasLineEnd; }
  void Bracket::hasLineEnd(bool value) { _hasLineEnd = value; }
  LineEndEnum Bracket::lineEnd() const { return _lineEnd; }
  void Bracket::lineEnd(LineEndEnum value) { _lineEnd = value; }
  bool Bracket::hasEndLength() const { return _hasEndLength; }
  void Bracket::hasEndLength(bool value) { _hasEndLength = value; }
  float Bracket::endLength() const { return _endLength; }
  void Bracket::endLength(float value) { _endLength = value; }

  void Bracket::ostreamAttrs(pugi::xml_node& self) const
  {
    LineType::ostreamAttrs(self);
    DashedFormatting::ostreamAttrs(self);
    Position::ostreamAttrs(self);
    Color::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasLineEnd) {
      self.append_attribute("line-end").set_value(_lineEnd.operator const char *());
    }
    if(_hasEndLength) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _endLength);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("end-length").set_value(str);
    }
  }
  void Bracket::istreamAttrs(const pugi::xml_node& self)
  {
    LineType::istreamAttrs(self);
    DashedFormatting::istreamAttrs(self);
    Position::istreamAttrs(self);
    Color::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopContinueEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("line-end")) {
      _lineEnd = LineEndEnum(attr.as_string());
      _hasLineEnd = true;
    }
    if(auto attr = self.attribute("end-length")) {
      _endLength = attr.as_float();
      _hasEndLength = true;
    }
  }
}
