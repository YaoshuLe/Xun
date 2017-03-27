#include "Clef.h"
#include <cstring>
#include "Sign.h"
#include "Line.h"
#include "ClefOctaveChange.h"

namespace mxml
{
  Clef::Clef() {}
  SignPtr Clef::getSign() const { return _signPtr; }
  void Clef::setSign(const SignPtr& value) { _signPtr = value; value->setParent(shared_from_this()); }
  LinePtr Clef::getLine() const { return _linePtr; }
  void Clef::setLine(const LinePtr& value) { _linePtr = value; value->setParent(shared_from_this()); }
  ClefOctaveChangePtr Clef::getClefOctaveChange() const { return _clefOctaveChangePtr; }
  void Clef::setClefOctaveChange(const ClefOctaveChangePtr& value) { _clefOctaveChangePtr = value; value->setParent(shared_from_this()); }
  bool Clef::hasNumber() const { return _hasNumber; }
  void Clef::hasNumber(bool value) { _hasNumber = value; }
  int Clef::number() const { return _number; }
  void Clef::number(int value) { _number = value; }
  bool Clef::hasAdditional() const { return _hasAdditional; }
  void Clef::hasAdditional(bool value) { _hasAdditional = value; }
  YesNoEnum Clef::additional() const { return _additional; }
  void Clef::additional(YesNoEnum value) { _additional = value; }
  bool Clef::hasSize() const { return _hasSize; }
  void Clef::hasSize(bool value) { _hasSize = value; }
  SymbolSizeEnum Clef::size() const { return _size; }
  void Clef::size(SymbolSizeEnum value) { _size = value; }
  bool Clef::hasAfterBarline() const { return _hasAfterBarline; }
  void Clef::hasAfterBarline(bool value) { _hasAfterBarline = value; }
  YesNoEnum Clef::afterBarline() const { return _afterBarline; }
  void Clef::afterBarline(YesNoEnum value) { _afterBarline = value; }

  void Clef::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    PrintObject::ostreamAttrs(self);
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasAdditional) {
      self.append_attribute("additional").set_value(_additional.operator const char *());
    }
    if(_hasSize) {
      self.append_attribute("size").set_value(_size.operator const char *());
    }
    if(_hasAfterBarline) {
      self.append_attribute("after-barline").set_value(_afterBarline.operator const char *());
    }
  }
  void Clef::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    PrintObject::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("additional")) {
      _additional = YesNoEnum(attr.as_string());
      _hasAdditional = true;
    }
    if(auto attr = self.attribute("size")) {
      _size = SymbolSizeEnum(attr.as_string());
      _hasSize = true;
    }
    if(auto attr = self.attribute("after-barline")) {
      _afterBarline = YesNoEnum(attr.as_string());
      _hasAfterBarline = true;
    }
  }
  void Clef::ostreamContents(pugi::xml_node& self) const
  {
    if(_signPtr) {
      auto child = self.append_child("sign");
      _signPtr->ostream(child);
    }
    if(_linePtr) {
      auto child = self.append_child("line");
      _linePtr->ostream(child);
    }
    if(_clefOctaveChangePtr) {
      auto child = self.append_child("clef-octave-change");
      _clefOctaveChangePtr->ostream(child);
    }
  }
  void Clef::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "sign")==0) {
        auto signPtr = std::make_shared<Sign>();
        signPtr->istream(child);
        setSign(signPtr);
      }
      else if(strcmp(child.name(), "line")==0) {
        auto linePtr = std::make_shared<Line>();
        linePtr->istream(child);
        setLine(linePtr);
      }
      else if(strcmp(child.name(), "clef-octave-change")==0) {
        auto clefOctaveChangePtr = std::make_shared<ClefOctaveChange>();
        clefOctaveChangePtr->istream(child);
        setClefOctaveChange(clefOctaveChangePtr);
      }
    }
  }
}
