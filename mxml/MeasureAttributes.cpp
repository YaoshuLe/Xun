#include "MeasureAttributes.h"
#include <cstring>

namespace mxml
{
  MeasureAttributes::MeasureAttributes() {}
  bool MeasureAttributes::hasNumber() const { return _hasNumber; }
  void MeasureAttributes::hasNumber(bool value) { _hasNumber = value; }
  std::string MeasureAttributes::number() const { return _number; }
  void MeasureAttributes::number(std::string value) { _number = value; }
  bool MeasureAttributes::hasImplicit() const { return _hasImplicit; }
  void MeasureAttributes::hasImplicit(bool value) { _hasImplicit = value; }
  YesNoEnum MeasureAttributes::implicit() const { return _implicit; }
  void MeasureAttributes::implicit(YesNoEnum value) { _implicit = value; }
  bool MeasureAttributes::hasNonControlling() const { return _hasNonControlling; }
  void MeasureAttributes::hasNonControlling(bool value) { _hasNonControlling = value; }
  YesNoEnum MeasureAttributes::nonControlling() const { return _nonControlling; }
  void MeasureAttributes::nonControlling(YesNoEnum value) { _nonControlling = value; }
  bool MeasureAttributes::hasWidth() const { return _hasWidth; }
  void MeasureAttributes::hasWidth(bool value) { _hasWidth = value; }
  float MeasureAttributes::width() const { return _width; }
  void MeasureAttributes::width(float value) { _width = value; }

  void MeasureAttributes::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasNumber) {
      self.append_attribute("number").set_value(_number.c_str());
    }
    if(_hasImplicit) {
      self.append_attribute("implicit").set_value(_implicit.operator const char *());
    }
    if(_hasNonControlling) {
      self.append_attribute("non-controlling").set_value(_nonControlling.operator const char *());
    }
    if(_hasWidth) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _width);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("width").set_value(str);
    }
  }
  void MeasureAttributes::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("number")) {
      _number = attr.as_string();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("implicit")) {
      _implicit = YesNoEnum(attr.as_string());
      _hasImplicit = true;
    }
    if(auto attr = self.attribute("non-controlling")) {
      _nonControlling = YesNoEnum(attr.as_string());
      _hasNonControlling = true;
    }
    if(auto attr = self.attribute("width")) {
      _width = attr.as_float();
      _hasWidth = true;
    }
  }
}
