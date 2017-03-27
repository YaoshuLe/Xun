#include "LyricLanguage.h"
#include <sstream>

namespace mxml
{
  LyricLanguage::LyricLanguage() {}
  bool LyricLanguage::hasNumber() const { return _hasNumber; }
  void LyricLanguage::hasNumber(bool value) { _hasNumber = value; }
  std::string LyricLanguage::number() const { return _number; }
  void LyricLanguage::number(std::string value) { _number = value; }
  bool LyricLanguage::hasName() const { return _hasName; }
  void LyricLanguage::hasName(bool value) { _hasName = value; }
  std::string LyricLanguage::name() const { return _name; }
  void LyricLanguage::name(std::string value) { _name = value; }
  bool LyricLanguage::hasLang() const { return _hasLang; }
  void LyricLanguage::hasLang(bool value) { _hasLang = value; }
  std::string LyricLanguage::lang() const { return _lang; }
  void LyricLanguage::lang(std::string value) { _lang = value; }
  void LyricLanguage::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasNumber) {
      self.append_attribute("number").set_value(_number.c_str());
    }
    if(_hasName) {
      self.append_attribute("name").set_value(_name.c_str());
    }
    if(_hasLang) {
      self.append_attribute("xml:lang").set_value(_lang.c_str());
    }
  }
  void LyricLanguage::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("number")) {
      _number = attr.as_string();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("name")) {
      _name = attr.as_string();
      _hasName = true;
    }
    if(auto attr = self.attribute("xml:lang")) {
      _lang = attr.as_string();
      _hasLang = true;
    }
  }
}
