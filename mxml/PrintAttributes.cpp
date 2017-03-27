#include "PrintAttributes.h"
#include <cstring>

namespace mxml
{
  PrintAttributes::PrintAttributes() {}
  bool PrintAttributes::hasStaffSpacing() const { return _hasStaffSpacing; }
  void PrintAttributes::hasStaffSpacing(bool value) { _hasStaffSpacing = value; }
  float PrintAttributes::staffSpacing() const { return _staffSpacing; }
  void PrintAttributes::staffSpacing(float value) { _staffSpacing = value; }
  bool PrintAttributes::hasNewSystem() const { return _hasNewSystem; }
  void PrintAttributes::hasNewSystem(bool value) { _hasNewSystem = value; }
  YesNoEnum PrintAttributes::newSystem() const { return _newSystem; }
  void PrintAttributes::newSystem(YesNoEnum value) { _newSystem = value; }
  bool PrintAttributes::hasNewPage() const { return _hasNewPage; }
  void PrintAttributes::hasNewPage(bool value) { _hasNewPage = value; }
  YesNoEnum PrintAttributes::newPage() const { return _newPage; }
  void PrintAttributes::newPage(YesNoEnum value) { _newPage = value; }
  bool PrintAttributes::hasBlankPage() const { return _hasBlankPage; }
  void PrintAttributes::hasBlankPage(bool value) { _hasBlankPage = value; }
  int PrintAttributes::blankPage() const { return _blankPage; }
  void PrintAttributes::blankPage(int value) { _blankPage = value; }
  bool PrintAttributes::hasPageNumber() const { return _hasPageNumber; }
  void PrintAttributes::hasPageNumber(bool value) { _hasPageNumber = value; }
  std::string PrintAttributes::pageNumber() const { return _pageNumber; }
  void PrintAttributes::pageNumber(std::string value) { _pageNumber = value; }

  void PrintAttributes::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasStaffSpacing) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _staffSpacing);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("staff-spacing").set_value(str);
    }
    if(_hasNewSystem) {
      self.append_attribute("new-system").set_value(_newSystem.operator const char *());
    }
    if(_hasNewPage) {
      self.append_attribute("new-page").set_value(_newPage.operator const char *());
    }
    if(_hasBlankPage) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _blankPage);
      self.append_attribute("blank-page").set_value(str);
    }
    if(_hasPageNumber) {
      self.append_attribute("page-number").set_value(_pageNumber.c_str());
    }
  }
  void PrintAttributes::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("staff-spacing")) {
      _staffSpacing = attr.as_float();
      _hasStaffSpacing = true;
    }
    if(auto attr = self.attribute("new-system")) {
      _newSystem = YesNoEnum(attr.as_string());
      _hasNewSystem = true;
    }
    if(auto attr = self.attribute("new-page")) {
      _newPage = YesNoEnum(attr.as_string());
      _hasNewPage = true;
    }
    if(auto attr = self.attribute("blank-page")) {
      _blankPage = attr.as_int();
      _hasBlankPage = true;
    }
    if(auto attr = self.attribute("page-number")) {
      _pageNumber = attr.as_string();
      _hasPageNumber = true;
    }
  }
}
