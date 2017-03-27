#include "Grouping.h"
#include <cstring>
#include "Feature.h"

namespace mxml
{
  Grouping::Grouping() {}
  const FeatureSet& Grouping::getFeatureSet() const {  return _featureSet; }
  void Grouping::removeFeature(const FeaturePtr& value) { if(value) { auto i = std::find_if(_featureSet.begin(), _featureSet.end(), [&](const FeaturePtr& item) { return item==value; }); if(i!=_featureSet.end()) _featureSet.erase(i); } } 
  void Grouping::addFeature(const FeaturePtr& value) { if(value) { _featureSet.push_back(value); value->setParent(shared_from_this()); } }
  void Grouping::clearFeatureSet() { _featureSet.clear(); }
  bool Grouping::hasType() const { return _hasType; }
  void Grouping::hasType(bool value) { _hasType = value; }
  StartStopSingleEnum Grouping::type() const { return _type; }
  void Grouping::type(StartStopSingleEnum value) { _type = value; }
  bool Grouping::hasNumber() const { return _hasNumber; }
  void Grouping::hasNumber(bool value) { _hasNumber = value; }
  std::string Grouping::number() const { return _number; }
  void Grouping::number(std::string value) { _number = value; }
  bool Grouping::hasMemberOf() const { return _hasMemberOf; }
  void Grouping::hasMemberOf(bool value) { _hasMemberOf = value; }
  std::string Grouping::memberOf() const { return _memberOf; }
  void Grouping::memberOf(std::string value) { _memberOf = value; }

  void Grouping::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      self.append_attribute("number").set_value(_number.c_str());
    }
    if(_hasMemberOf) {
      self.append_attribute("member-of").set_value(_memberOf.c_str());
    }
  }
  void Grouping::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = StartStopSingleEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_string();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("member-of")) {
      _memberOf = attr.as_string();
      _hasMemberOf = true;
    }
  }
  void Grouping::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _featureSet) {
      auto child = self.append_child("feature");
      item->ostream(child);
    }
  }
  void Grouping::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "feature")==0) {
        auto featurePtr = std::make_shared<Feature>();
        featurePtr->istream(child);
        addFeature(featurePtr);
      }
    }
  }
}
