#include "Harmony.h"
#include <cstring>
#include "HarmonyChord.h"
#include "Root.h"
#include "Function.h"
#include "Kind.h"
#include "Inversion.h"
#include "Bass.h"
#include "Degree.h"
#include "Frame.h"
#include "Offset.h"
#include "Footnote.h"
#include "Level.h"
#include "Staff.h"

namespace mxml
{
  Harmony::Harmony() {}
  const HarmonyChordSet& Harmony::getHarmonyChordSet() const {  return _harmonyChordSet; }
  void Harmony::removeHarmonyChord(const HarmonyChordPtr& value) { if(value) { auto i = std::find_if(_harmonyChordSet.begin(), _harmonyChordSet.end(), [&](const HarmonyChordPtr& item) { return item==value; }); if(i!=_harmonyChordSet.end()) _harmonyChordSet.erase(i); } } 
  void Harmony::addHarmonyChord(const HarmonyChordPtr& value) { if(value) { _harmonyChordSet.push_back(value); value->setParent(shared_from_this()); } }
  void Harmony::clearHarmonyChordSet() { _harmonyChordSet.clear(); }
  FramePtr Harmony::getFrame() const { return _framePtr; }
  void Harmony::setFrame(const FramePtr& value) { _framePtr = value; value->setParent(shared_from_this()); }
  OffsetPtr Harmony::getOffset() const { return _offsetPtr; }
  void Harmony::setOffset(const OffsetPtr& value) { _offsetPtr = value; value->setParent(shared_from_this()); }
  FootnotePtr Harmony::getFootnote() const { return _footnotePtr; }
  void Harmony::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr Harmony::getLevel() const { return _levelPtr; }
  void Harmony::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  StaffPtr Harmony::getStaff() const { return _staffPtr; }
  void Harmony::setStaff(const StaffPtr& value) { _staffPtr = value; value->setParent(shared_from_this()); }
  bool Harmony::hasType() const { return _hasType; }
  void Harmony::hasType(bool value) { _hasType = value; }
  HarmonyTypeEnum Harmony::type() const { return _type; }
  void Harmony::type(HarmonyTypeEnum value) { _type = value; }
  bool Harmony::hasPrintFrame() const { return _hasPrintFrame; }
  void Harmony::hasPrintFrame(bool value) { _hasPrintFrame = value; }
  YesNoEnum Harmony::printFrame() const { return _printFrame; }
  void Harmony::printFrame(YesNoEnum value) { _printFrame = value; }

  void Harmony::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintStyle::ostreamAttrs(self);
    Placement::ostreamAttrs(self);
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
    if(_hasPrintFrame) {
      self.append_attribute("print-frame").set_value(_printFrame.operator const char *());
    }
  }
  void Harmony::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintStyle::istreamAttrs(self);
    Placement::istreamAttrs(self);
    if(auto attr = self.attribute("type")) {
      _type = HarmonyTypeEnum(attr.as_string());
      _hasType = true;
    }
    if(auto attr = self.attribute("print-frame")) {
      _printFrame = YesNoEnum(attr.as_string());
      _hasPrintFrame = true;
    }
  }
  void Harmony::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _harmonyChordSet) {
      item->ostream(self);
    }
    if(_framePtr) {
      auto child = self.append_child("frame");
      _framePtr->ostream(child);
    }
    if(_offsetPtr) {
      auto child = self.append_child("offset");
      _offsetPtr->ostream(child);
    }
    if(_footnotePtr) {
      auto child = self.append_child("footnote");
      _footnotePtr->ostream(child);
    }
    if(_levelPtr) {
      auto child = self.append_child("level");
      _levelPtr->ostream(child);
    }
    if(_staffPtr) {
      auto child = self.append_child("staff");
      _staffPtr->ostream(child);
    }
  }
  void Harmony::istreamContents(const pugi::xml_node& self)
  {
    HarmonyChordPtr harmonyChordPtr;
    for(auto child: self.children()) {
      if(strcmp(child.name(), "root")==0) {
        auto rootPtr = std::make_shared<Root>();
        rootPtr->istream(child);
        harmonyChordPtr = std::make_shared<HarmonyChord>();
        harmonyChordPtr->setRoot(rootPtr);
        addHarmonyChord(harmonyChordPtr);
      }
      else if(strcmp(child.name(), "function")==0) {
        auto functionPtr = std::make_shared<Function>();
        functionPtr->istream(child);
        harmonyChordPtr = std::make_shared<HarmonyChord>();
        harmonyChordPtr->setFunction(functionPtr);
        addHarmonyChord(harmonyChordPtr);
      }
      else if(strcmp(child.name(), "kind")==0) {
        if(harmonyChordPtr) {
          auto kindPtr = std::make_shared<Kind>();
          kindPtr->istream(child);
          harmonyChordPtr->setKind(kindPtr);
        }
      }
      else if(strcmp(child.name(), "inversion")==0) {
        if(harmonyChordPtr) {
          auto inversionPtr = std::make_shared<Inversion>();
          inversionPtr->istream(child);
          harmonyChordPtr->setInversion(inversionPtr);
        }  
      }
      else if(strcmp(child.name(), "bass")==0) {
        if(harmonyChordPtr) {
          auto bassPtr = std::make_shared<Bass>();
          bassPtr->istream(child);
          harmonyChordPtr->setBass(bassPtr);
        }  
      }
      else if(strcmp(child.name(), "degree")==0) {
        if(harmonyChordPtr) {
          auto degreePtr = std::make_shared<Degree>();
          degreePtr->istream(child);
          harmonyChordPtr->addDegree(degreePtr);
        }  
      }
      else if(strcmp(child.name(), "frame")==0) {
        auto framePtr = std::make_shared<Frame>();
        framePtr->istream(child);
        setFrame(framePtr);
      }
      else if(strcmp(child.name(), "offset")==0) {
        auto offsetPtr = std::make_shared<Offset>();
        offsetPtr->istream(child);
        setOffset(offsetPtr);
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
      else if(strcmp(child.name(), "staff")==0) {
        auto staffPtr = std::make_shared<Staff>();
        staffPtr->istream(child);
        setStaff(staffPtr);
      }
    }
  }
}
