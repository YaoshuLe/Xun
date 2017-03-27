#include "NonTraditionalKey.h"
#include <cstring>
#include "KeyStep.h"
#include "KeyAlter.h"
#include "KeyAccidental.h"

namespace mxml
{
  NonTraditionalKey::NonTraditionalKey() {}
  KeyStepPtr NonTraditionalKey::getKeyStep() const { return _keyStepPtr; }
  void NonTraditionalKey::setKeyStep(const KeyStepPtr& value) { _keyStepPtr = value; value->setParent(shared_from_this()); }
  KeyAlterPtr NonTraditionalKey::getKeyAlter() const { return _keyAlterPtr; }
  void NonTraditionalKey::setKeyAlter(const KeyAlterPtr& value) { _keyAlterPtr = value; value->setParent(shared_from_this()); }
  KeyAccidentalPtr NonTraditionalKey::getKeyAccidental() const { return _keyAccidentalPtr; }
  void NonTraditionalKey::setKeyAccidental(const KeyAccidentalPtr& value) { _keyAccidentalPtr = value; value->setParent(shared_from_this()); }

  void NonTraditionalKey::ostreamContents(pugi::xml_node& self) const
  {
    if(_keyStepPtr) {
      auto child = self.append_child("key-step");
      _keyStepPtr->ostream(child);
    }
    if(_keyAlterPtr) {
      auto child = self.append_child("key-alter");
      _keyAlterPtr->ostream(child);
    }
    if(_keyAccidentalPtr) {
      auto child = self.append_child("key-accidental");
      _keyAccidentalPtr->ostream(child);
    }
  }
  void NonTraditionalKey::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "key-step")==0) {
        auto keyStepPtr = std::make_shared<KeyStep>();
        keyStepPtr->istream(child);
        setKeyStep(keyStepPtr);
      }
      else if(strcmp(child.name(), "key-alter")==0) {
        auto keyAlterPtr = std::make_shared<KeyAlter>();
        keyAlterPtr->istream(child);
        setKeyAlter(keyAlterPtr);
      }
      else if(strcmp(child.name(), "key-accidental")==0) {
        auto keyAccidentalPtr = std::make_shared<KeyAccidental>();
        keyAccidentalPtr->istream(child);
        setKeyAccidental(keyAccidentalPtr);
      }
    }
  }
}
