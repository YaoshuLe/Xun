#include "NameDisplay.h"
#include <cstring>
#include "DisplayText.h"
#include "AccidentalText.h"

namespace mxml
{
  NameDisplay::NameDisplay() {}
  DisplayTextPtr NameDisplay::getDisplayText() const { return _displayTextPtr; }
  void NameDisplay::setDisplayText(const DisplayTextPtr& value) { _displayTextPtr = value; value->setParent(shared_from_this()); }
  AccidentalTextPtr NameDisplay::getAccidentalText() const { return _accidentalTextPtr; }
  void NameDisplay::setAccidentalText(const AccidentalTextPtr& value) { _accidentalTextPtr = value; value->setParent(shared_from_this()); }

  void NameDisplay::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
  }
  void NameDisplay::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
  }
  void NameDisplay::ostreamContents(pugi::xml_node& self) const
  {
    if(_displayTextPtr) {
      auto child = self.append_child("display-text");
      _displayTextPtr->ostream(child);
    }
    if(_accidentalTextPtr) {
      auto child = self.append_child("accidental-text");
      _accidentalTextPtr->ostream(child);
    }
  }
  void NameDisplay::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "display-text")==0) {
        auto displayTextPtr = std::make_shared<DisplayText>();
        displayTextPtr->istream(child);
        setDisplayText(displayTextPtr);
      }
      else if(strcmp(child.name(), "accidental-text")==0) {
        auto accidentalTextPtr = std::make_shared<AccidentalText>();
        accidentalTextPtr->istream(child);
        setAccidentalText(accidentalTextPtr);
      }
    }
  }
}
