#include "TraditionalKey.h"
#include <cstring>
#include "Cancel.h"
#include "Fifths.h"
#include "Mode.h"

namespace mxml
{
  TraditionalKey::TraditionalKey() {}
  CancelPtr TraditionalKey::getCancel() const { return _cancelPtr; }
  void TraditionalKey::setCancel(const CancelPtr& value) { _cancelPtr = value; value->setParent(shared_from_this()); }
  FifthsPtr TraditionalKey::getFifths() const { return _fifthsPtr; }
  void TraditionalKey::setFifths(const FifthsPtr& value) { _fifthsPtr = value; value->setParent(shared_from_this()); }
  ModePtr TraditionalKey::getMode() const { return _modePtr; }
  void TraditionalKey::setMode(const ModePtr& value) { _modePtr = value; value->setParent(shared_from_this()); }

  void TraditionalKey::ostreamContents(pugi::xml_node& self) const
  {
    if(_cancelPtr) {
      auto child = self.append_child("cancel");
      _cancelPtr->ostream(child);
    }
    if(_fifthsPtr) {
      auto child = self.append_child("fifths");
      _fifthsPtr->ostream(child);
    }
    if(_modePtr) {
      auto child = self.append_child("mode");
      _modePtr->ostream(child);
    }
  }
  void TraditionalKey::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "cancel")==0) {
        auto cancelPtr = std::make_shared<Cancel>();
        cancelPtr->istream(child);
        setCancel(cancelPtr);
      }
      else if(strcmp(child.name(), "fifths")==0) {
        auto fifthsPtr = std::make_shared<Fifths>();
        fifthsPtr->istream(child);
        setFifths(fifthsPtr);
      }
      else if(strcmp(child.name(), "mode")==0) {
        auto modePtr = std::make_shared<Mode>();
        modePtr->istream(child);
        setMode(modePtr);
      }
    }
  }
}
