#include "Bezier.h"
#include <cstring>

namespace mxml
{
  Bezier::Bezier() {}
  bool Bezier::hasBezierOffset() const { return _hasBezierOffset; }
  void Bezier::hasBezierOffset(bool value) { _hasBezierOffset = value; }
  float Bezier::bezierOffset() const { return _bezierOffset; }
  void Bezier::bezierOffset(float value) { _bezierOffset = value; }
  bool Bezier::hasBezierOffset2() const { return _hasBezierOffset2; }
  void Bezier::hasBezierOffset2(bool value) { _hasBezierOffset2 = value; }
  float Bezier::bezierOffset2() const { return _bezierOffset2; }
  void Bezier::bezierOffset2(float value) { _bezierOffset2 = value; }
  bool Bezier::hasBezierX() const { return _hasBezierX; }
  void Bezier::hasBezierX(bool value) { _hasBezierX = value; }
  float Bezier::bezierX() const { return _bezierX; }
  void Bezier::bezierX(float value) { _bezierX = value; }
  bool Bezier::hasBezierY() const { return _hasBezierY; }
  void Bezier::hasBezierY(bool value) { _hasBezierY = value; }
  float Bezier::bezierY() const { return _bezierY; }
  void Bezier::bezierY(float value) { _bezierY = value; }
  bool Bezier::hasBezierX2() const { return _hasBezierX2; }
  void Bezier::hasBezierX2(bool value) { _hasBezierX2 = value; }
  float Bezier::bezierX2() const { return _bezierX2; }
  void Bezier::bezierX2(float value) { _bezierX2 = value; }
  bool Bezier::hasBezierY2() const { return _hasBezierY2; }
  void Bezier::hasBezierY2(bool value) { _hasBezierY2 = value; }
  float Bezier::bezierY2() const { return _bezierY2; }
  void Bezier::bezierY2(float value) { _bezierY2 = value; }

  void Bezier::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasBezierOffset) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _bezierOffset);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("bezier-offset").set_value(str);
    }
    if(_hasBezierOffset2) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _bezierOffset2);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("bezier-offset2").set_value(str);
    }
    if(_hasBezierX) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _bezierX);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("bezier-x").set_value(str);
    }
    if(_hasBezierY) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _bezierY);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("bezier-y").set_value(str);
    }
    if(_hasBezierX2) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _bezierX2);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("bezier-x2").set_value(str);
    }
    if(_hasBezierY2) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _bezierY2);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("bezier-y2").set_value(str);
    }
  }
  void Bezier::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("bezier-offset")) {
      _bezierOffset = attr.as_float();
      _hasBezierOffset = true;
    }
    if(auto attr = self.attribute("bezier-offset2")) {
      _bezierOffset2 = attr.as_float();
      _hasBezierOffset2 = true;
    }
    if(auto attr = self.attribute("bezier-x")) {
      _bezierX = attr.as_float();
      _hasBezierX = true;
    }
    if(auto attr = self.attribute("bezier-y")) {
      _bezierY = attr.as_float();
      _hasBezierY = true;
    }
    if(auto attr = self.attribute("bezier-x2")) {
      _bezierX2 = attr.as_float();
      _hasBezierX2 = true;
    }
    if(auto attr = self.attribute("bezier-y2")) {
      _bezierY2 = attr.as_float();
      _hasBezierY2 = true;
    }
  }
}
