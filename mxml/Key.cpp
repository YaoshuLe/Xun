#include "Key.h"
#include <cstring>
#include "TraditionalKey.h"
#include "Cancel.h"
#include "Fifths.h"
#include "Mode.h"
#include "NonTraditionalKey.h"
#include "KeyStep.h"
#include "KeyAlter.h"
#include "KeyAccidental.h"
#include "KeyOctave.h"

namespace mxml
{
  Key::Key() {}
  TraditionalKeyPtr Key::getTraditionalKey() const { return _traditionalKeyPtr; }
  void Key::setTraditionalKey(const TraditionalKeyPtr& value) { _traditionalKeyPtr = value; value->setParent(shared_from_this()); }
  const NonTraditionalKeySet& Key::getNonTraditionalKeySet() const {  return _nonTraditionalKeySet; }
  void Key::removeNonTraditionalKey(const NonTraditionalKeyPtr& value) { if(value) { auto i = std::find_if(_nonTraditionalKeySet.begin(), _nonTraditionalKeySet.end(), [&](const NonTraditionalKeyPtr& item) { return item==value; }); if(i!=_nonTraditionalKeySet.end()) _nonTraditionalKeySet.erase(i); } } 
  void Key::addNonTraditionalKey(const NonTraditionalKeyPtr& value) { if(value) { _nonTraditionalKeySet.push_back(value); value->setParent(shared_from_this()); } }
  void Key::clearNonTraditionalKeySet() { _nonTraditionalKeySet.clear(); }
  const KeyOctaveSet& Key::getKeyOctaveSet() const {  return _keyOctaveSet; }
  void Key::removeKeyOctave(const KeyOctavePtr& value) { if(value) { auto i = std::find_if(_keyOctaveSet.begin(), _keyOctaveSet.end(), [&](const KeyOctavePtr& item) { return item==value; }); if(i!=_keyOctaveSet.end()) _keyOctaveSet.erase(i); } } 
  void Key::addKeyOctave(const KeyOctavePtr& value) { if(value) { _keyOctaveSet.push_back(value); value->setParent(shared_from_this()); } }
  void Key::clearKeyOctaveSet() { _keyOctaveSet.clear(); }
  bool Key::hasNumber() const { return _hasNumber; }
  void Key::hasNumber(bool value) { _hasNumber = value; }
  int Key::number() const { return _number; }
  void Key::number(int value) { _number = value; }

  void Key::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    PrintObject::ostreamAttrs(self);
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
  }
  void Key::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    PrintObject::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
  }
  void Key::ostreamContents(pugi::xml_node& self) const
  {
    if(_traditionalKeyPtr) {
      _traditionalKeyPtr->ostream(self);
    }
    else {
      for(auto item : _nonTraditionalKeySet) {
        item->ostream(self);
      }
    }
    for(auto item : _keyOctaveSet) {
      auto child = self.append_child("key-octave");
      item->ostream(child);
    }
  }
  void Key::istreamContents(const pugi::xml_node& self)
  {
    if(self.children().begin()==self.children().end()) return;
    auto begin = *(self.children().begin());
    if((strcmp(begin.name(), "cancel")==0) || (strcmp(begin.name(), "fifths")==0)) {
      TraditionalKeyPtr traditionalKeyPtr;
      for(auto child: self.children()) {
        if(strcmp(child.name(), "cancel")==0) {
          auto cancelPtr = std::make_shared<Cancel>();
          cancelPtr->istream(child);
          traditionalKeyPtr = std::make_shared<TraditionalKey>();
          traditionalKeyPtr->setCancel(cancelPtr);
          setTraditionalKey(traditionalKeyPtr);
        }
        else if(strcmp(child.name(), "fifths")==0) {          
          auto fifthsPtr = std::make_shared<Fifths>();
          fifthsPtr->istream(child);
          if(!traditionalKeyPtr) traditionalKeyPtr = std::make_shared<TraditionalKey>();
          traditionalKeyPtr->setFifths(fifthsPtr);
          setTraditionalKey(traditionalKeyPtr);
        }
        else if(strcmp(child.name(), "mode")==0) {
          if(traditionalKeyPtr) {
            auto modePtr = std::make_shared<Mode>();
            modePtr->istream(child);
            traditionalKeyPtr->setMode(modePtr);
          }
        }
        else if(strcmp(child.name(), "key-octave")==0) {
          auto keyOctavePtr = std::make_shared<KeyOctave>();
          keyOctavePtr->istream(child);
          addKeyOctave(keyOctavePtr);
        }
      }
    }
    else {
      NonTraditionalKeyPtr nonTraditionalKeyPtr;
      for(auto child: self.children()) {
        if(strcmp(child.name(), "key-step")==0) {
          auto keyStepPtr = std::make_shared<KeyStep>();
          keyStepPtr->istream(child);
          nonTraditionalKeyPtr = std::make_shared<NonTraditionalKey>();
          nonTraditionalKeyPtr->setKeyStep(keyStepPtr);
          addNonTraditionalKey(nonTraditionalKeyPtr);
        }
        else if(strcmp(child.name(), "key-alter")==0) {
          if(nonTraditionalKeyPtr) {
            auto keyAlterPtr = std::make_shared<KeyAlter>();
            keyAlterPtr->istream(child);
            nonTraditionalKeyPtr->setKeyAlter(keyAlterPtr);
          }
        }
        else if(strcmp(child.name(), "key-accidental")==0) {
          if(nonTraditionalKeyPtr) {
            auto keyAccidentalPtr = std::make_shared<KeyAccidental>();
            keyAccidentalPtr->istream(child);
            nonTraditionalKeyPtr->setKeyAccidental(keyAccidentalPtr);
          }
        }
        else if(strcmp(child.name(), "key-octave")==0) {
          auto keyOctavePtr = std::make_shared<KeyOctave>();
          keyOctavePtr->istream(child);
          addKeyOctave(keyOctavePtr);
        }
      }
    }
  }
}
