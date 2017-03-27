#include "Tuplet.h"
#include <cstring>
#include "TupletActual.h"
#include "TupletNormal.h"

namespace mxml
{
  Tuplet::Tuplet() {}
  TupletActualPtr Tuplet::getTupletActual() const { return _tupletActualPtr; }
  void Tuplet::setTupletActual(const TupletActualPtr& value) { _tupletActualPtr = value; value->setParent(shared_from_this()); }
  TupletNormalPtr Tuplet::getTupletNormal() const { return _tupletNormalPtr; }
  void Tuplet::setTupletNormal(const TupletNormalPtr& value) { _tupletNormalPtr = value; value->setParent(shared_from_this()); }
  bool Tuplet::hasType() const { return _hasType; }
  void Tuplet::hasType(bool value) { _hasType = value; }
  StartStopEnum Tuplet::type() const { return _type; }
  void Tuplet::type(StartStopEnum value) { _type = value; }
  bool Tuplet::hasNumber() const { return _hasNumber; }
  void Tuplet::hasNumber(bool value) { _hasNumber = value; }
  int Tuplet::number() const { return _number; }
  void Tuplet::number(int value) { _number = value; }
  bool Tuplet::hasBracket() const { return _hasBracket; }
  void Tuplet::hasBracket(bool value) { _hasBracket = value; }
  YesNoEnum Tuplet::bracket() const { return _bracket; }
  void Tuplet::bracket(YesNoEnum value) { _bracket = value; }
  bool Tuplet::hasShowNumber() const { return _hasShowNumber; }
  void Tuplet::hasShowNumber(bool value) { _hasShowNumber = value; }
  ShowTupletEnum Tuplet::showNumber() const { return _showNumber; }
  void Tuplet::showNumber(ShowTupletEnum value) { _showNumber = value; }
  bool Tuplet::hasShowType() const { return _hasShowType; }
  void Tuplet::hasShowType(bool value) { _hasShowType = value; }
  ShowTupletEnum Tuplet::showType() const { return _showType; }
  void Tuplet::showType(ShowTupletEnum value) { _showType = value; }

  void Tuplet::ostreamAttrs(pugi::xml_node& self) const
  {
    LineShape::ostreamAttrs(self);
    Position::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasBracket) {
      self.append_attribute("bracket").set_value(_bracket.operator const char *());
    }
    if(_hasShowNumber) {
      self.append_attribute("show-number").set_value(_showNumber.operator const char *());
    }
    if(_hasShowType) {
      self.append_attribute("show-type").set_value(_showType.operator const char *());
    }
  }
  void Tuplet::istreamAttrs(const pugi::xml_node& self)
  {
    LineShape::istreamAttrs(self);
    Position::istreamAttrs(self);
    Placement::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = StartStopEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("bracket")) {
      _bracket = YesNoEnum(attr.as_string());
      _hasBracket = true;
    }
    if(auto attr = self.attribute("show-number")) {
      _showNumber = ShowTupletEnum(attr.as_string());
      _hasShowNumber = true;
    }
    if(auto attr = self.attribute("show-type")) {
      _showType = ShowTupletEnum(attr.as_string());
      _hasShowType = true;
    }
  }
  void Tuplet::ostreamContents(pugi::xml_node& self) const
  {
    if(_tupletActualPtr) {
      auto child = self.append_child("tuplet-actual");
      _tupletActualPtr->ostream(child);
    }
    if(_tupletNormalPtr) {
      auto child = self.append_child("tuplet-normal");
      _tupletNormalPtr->ostream(child);
    }
  }
  void Tuplet::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "tuplet-actual")==0) {
        auto tupletActualPtr = std::make_shared<TupletActual>();
        tupletActualPtr->istream(child);
        setTupletActual(tupletActualPtr);
      }
      else if(strcmp(child.name(), "tuplet-normal")==0) {
        auto tupletNormalPtr = std::make_shared<TupletNormal>();
        tupletNormalPtr->istream(child);
        setTupletNormal(tupletNormalPtr);
      }
    }
  }
}
