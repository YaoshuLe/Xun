#include "Barline.h"
#include <cstring>
#include "BarStyle.h"
#include "Footnote.h"
#include "Level.h"
#include "WavyLine.h"
#include "Segno.h"
#include "Coda.h"
#include "Fermata.h"
#include "Ending.h"
#include "Repeat.h"

namespace mxml
{
  Barline::Barline() {}
  BarStylePtr Barline::getBarStyle() const { return _barStylePtr; }
  void Barline::setBarStyle(const BarStylePtr& value) { _barStylePtr = value; value->setParent(shared_from_this()); }
  FootnotePtr Barline::getFootnote() const { return _footnotePtr; }
  void Barline::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Barline::getLevel() const { return _levelPtr; }
  void Barline::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  WavyLinePtr Barline::getWavyLine() const { return _wavyLinePtr; }
  void Barline::setWavyLine(const WavyLinePtr& value) { _wavyLinePtr = value; value->setParent(shared_from_this()); }
  SegnoPtr Barline::getSegno() const { return _segnoPtr; }
  void Barline::setSegno(const SegnoPtr& value) { _segnoPtr = value; value->setParent(shared_from_this()); }
  CodaPtr Barline::getCoda() const { return _codaPtr; }
  void Barline::setCoda(const CodaPtr& value) { _codaPtr = value; value->setParent(shared_from_this()); }
  const FermataSet& Barline::getFermataSet() const {  return _fermataSet; }
  void Barline::removeFermata(const FermataPtr& value) { if(value) { auto i = std::find_if(_fermataSet.begin(), _fermataSet.end(), [&](const FermataPtr& item) { return item==value; }); if(i!=_fermataSet.end()) _fermataSet.erase(i); } } 
  void Barline::addFermata(const FermataPtr& value) { if(value) { _fermataSet.push_back(value); value->setParent(shared_from_this()); } }
  void Barline::clearFermataSet() { _fermataSet.clear(); }
  EndingPtr Barline::getEnding() const { return _endingPtr; }
  void Barline::setEnding(const EndingPtr& value) { _endingPtr = value; value->setParent(shared_from_this()); }
  RepeatPtr Barline::getRepeat() const { return _repeatPtr; }
  void Barline::setRepeat(const RepeatPtr& value) { _repeatPtr = value; value->setParent(shared_from_this()); }
  bool Barline::hasLocation() const { return _hasLocation; }
  void Barline::hasLocation(bool value) { _hasLocation = value; }
  RightLeftMiddleEnum Barline::location() const { return _location; }
  void Barline::location(RightLeftMiddleEnum value) { _location = value; }
  bool Barline::hasSegno() const { return _hasSegno; }
  void Barline::hasSegno(bool value) { _hasSegno = value; }
  std::string Barline::segno() const { return _segno; }
  void Barline::segno(std::string value) { _segno = value; }
  bool Barline::hasCoda() const { return _hasCoda; }
  void Barline::hasCoda(bool value) { _hasCoda = value; }
  std::string Barline::coda() const { return _coda; }
  void Barline::coda(std::string value) { _coda = value; }
  bool Barline::hasDivisions() const { return _hasDivisions; }
  void Barline::hasDivisions(bool value) { _hasDivisions = value; }
  float Barline::divisions() const { return _divisions; }
  void Barline::divisions(float value) { _divisions = value; }

  void Barline::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasLocation) {
      self.append_attribute("location").set_value(_location.operator const char *());
    }
    if(_hasSegno) {
      self.append_attribute("segno").set_value(_segno.c_str());
    }
    if(_hasCoda) {
      self.append_attribute("coda").set_value(_coda.c_str());
    }
    if(_hasDivisions) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _divisions);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("divisions").set_value(str);
    }
  }
  void Barline::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("location")) {
      _location = RightLeftMiddleEnum(attr.as_string());
      _hasLocation = true;
    }
    if(auto attr = self.attribute("segno")) {
      _segno = attr.as_string();
      _hasSegno = true;
    }
    if(auto attr = self.attribute("coda")) {
      _coda = attr.as_string();
      _hasCoda = true;
    }
    if(auto attr = self.attribute("divisions")) {
      _divisions = attr.as_float();
      _hasDivisions = true;
    }
  }
  void Barline::ostreamContents(pugi::xml_node& self) const
  {
    if(_barStylePtr) {
      auto child = self.append_child("bar-style");
      _barStylePtr->ostream(child);
    }
    if(_footnotePtr) {
      auto child = self.append_child("footnote");
      _footnotePtr->ostream(child);
    }
    if(_levelPtr) {
      auto child = self.append_child("level");
      _levelPtr->ostream(child);
    }
    if(_wavyLinePtr) {
      auto child = self.append_child("wavy-line");
      _wavyLinePtr->ostream(child);
    }
    if(_segnoPtr) {
      auto child = self.append_child("segno");
      _segnoPtr->ostream(child);
    }
    if(_codaPtr) {
      auto child = self.append_child("coda");
      _codaPtr->ostream(child);
    }
    for(auto item : _fermataSet) {
      auto child = self.append_child("fermata");
      item->ostream(child);
    }
    if(_endingPtr) {
      auto child = self.append_child("ending");
      _endingPtr->ostream(child);
    }
    if(_repeatPtr) {
      auto child = self.append_child("repeat");
      _repeatPtr->ostream(child);
    }
  }
  void Barline::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "bar-style")==0) {
        auto barStylePtr = std::make_shared<BarStyle>();
        barStylePtr->istream(child);
        setBarStyle(barStylePtr);
      }
      else if(strcmp(child.name(), "footnote")==0) {
        auto footnotePtr = std::make_shared<Footnote>();
        footnotePtr->istream(child);
        setFootnote(footnotePtr);
      }
      else if(strcmp(child.name(), "level")==0) {
        auto levelPtr = std::make_shared<Level>();
        levelPtr->istream(child);
        setLevel(levelPtr);
      }
      else if(strcmp(child.name(), "wavy-line")==0) {
        auto wavyLinePtr = std::make_shared<WavyLine>();
        wavyLinePtr->istream(child);
        setWavyLine(wavyLinePtr);
      }
      else if(strcmp(child.name(), "segno")==0) {
        auto segnoPtr = std::make_shared<Segno>();
        segnoPtr->istream(child);
        setSegno(segnoPtr);
      }
      else if(strcmp(child.name(), "coda")==0) {
        auto codaPtr = std::make_shared<Coda>();
        codaPtr->istream(child);
        setCoda(codaPtr);
      }
      else if(strcmp(child.name(), "fermata")==0) {
        auto fermataPtr = std::make_shared<Fermata>();
        fermataPtr->istream(child);
        addFermata(fermataPtr);
      }
      else if(strcmp(child.name(), "ending")==0) {
        auto endingPtr = std::make_shared<Ending>();
        endingPtr->istream(child);
        setEnding(endingPtr);
      }
      else if(strcmp(child.name(), "repeat")==0) {
        auto repeatPtr = std::make_shared<Repeat>();
        repeatPtr->istream(child);
        setRepeat(repeatPtr);
      }
    }
  }
}
