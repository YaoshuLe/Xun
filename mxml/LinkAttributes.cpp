#include "LinkAttributes.h"
#include <sstream>

namespace mxml
{
  LinkAttributes::LinkAttributes() {}
  bool LinkAttributes::hasHref() const { return _hasHref; }
  void LinkAttributes::hasHref(bool value) { _hasHref = value; }
  std::string LinkAttributes::href() const { return _href; }
  void LinkAttributes::href(std::string value) { _href = value; }
  bool LinkAttributes::hasType() const { return _hasType; }
  void LinkAttributes::hasType(bool value) { _hasType = value; }
  std::string LinkAttributes::type() const { return _type; }
  void LinkAttributes::type(std::string value) { _type = value; }
  bool LinkAttributes::hasRole() const { return _hasRole; }
  void LinkAttributes::hasRole(bool value) { _hasRole = value; }
  std::string LinkAttributes::role() const { return _role; }
  void LinkAttributes::role(std::string value) { _role = value; }
  bool LinkAttributes::hasTitle() const { return _hasTitle; }
  void LinkAttributes::hasTitle(bool value) { _hasTitle = value; }
  std::string LinkAttributes::title() const { return _title; }
  void LinkAttributes::title(std::string value) { _title = value; }
  bool LinkAttributes::hasShow() const { return _hasShow; }
  void LinkAttributes::hasShow(bool value) { _hasShow = value; }
  std::string LinkAttributes::show() const { return _show; }
  void LinkAttributes::show(std::string value) { _show = value; }
  bool LinkAttributes::hasActuate() const { return _hasActuate; }
  void LinkAttributes::hasActuate(bool value) { _hasActuate = value; }
  std::string LinkAttributes::actuate() const { return _actuate; }
  void LinkAttributes::actuate(std::string value) { _actuate = value; }
  
  void LinkAttributes::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasHref) {
      self.append_attribute("xlink:href").set_value(_href.c_str());
    }
    if(_hasType) {
      self.append_attribute("xlink:type").set_value(_type.c_str());
    }
    if(_hasRole) {
      self.append_attribute("xlink:role").set_value(_role.c_str());
    }
    if(_hasTitle) {
      self.append_attribute("xlink:title").set_value(_title.c_str());
    }
    if(_hasShow) {
      self.append_attribute("xlink:show").set_value(_show.c_str());
    }
    if(_hasActuate) {
      self.append_attribute("xlink:actuate").set_value(_actuate.c_str());
    }
  }
  void LinkAttributes::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("xlink:href")) {
      _href = attr.as_string();
      _hasHref = true;
    }
    if(auto attr = self.attribute("xlink:type")) {
      _type = attr.as_string();
      _hasType = true;
    }
    if(auto attr = self.attribute("xlink:role")) {
      _role = attr.as_string();
      _hasRole = true;
    }
    if(auto attr = self.attribute("xlink:title")) {
      _title = attr.as_string();
      _hasTitle = true;
    }
    if(auto attr = self.attribute("xlink:show")) {
      _show = attr.as_string();
      _hasShow = true;
    }
    if(auto attr = self.attribute("xlink:actuate")) {
      _actuate = attr.as_string();
      _hasActuate = true;
    }
  }
}
