#include "TupletPortion.h"
#include <cstring>
#include "TupletNumber.h"
#include "TupletType.h"
#include "TupletDot.h"

namespace mxml
{
  TupletPortion::TupletPortion() {}
  TupletNumberPtr TupletPortion::getTupletNumber() const { return _tupletNumberPtr; }
  void TupletPortion::setTupletNumber(const TupletNumberPtr& value) { _tupletNumberPtr = value; value->setParent(shared_from_this()); }
  TupletTypePtr TupletPortion::getTupletType() const { return _tupletTypePtr; }
  void TupletPortion::setTupletType(const TupletTypePtr& value) { _tupletTypePtr = value; value->setParent(shared_from_this()); }
  const TupletDotSet& TupletPortion::getTupletDotSet() const {  return _tupletDotSet; }
  void TupletPortion::removeTupletDot(const TupletDotPtr& value) { if(value) { auto i = std::find_if(_tupletDotSet.begin(), _tupletDotSet.end(), [&](const TupletDotPtr& item) { return item==value; }); if(i!=_tupletDotSet.end()) _tupletDotSet.erase(i); } } 
  void TupletPortion::addTupletDot(const TupletDotPtr& value) { if(value) { _tupletDotSet.push_back(value); value->setParent(shared_from_this()); } }
  void TupletPortion::clearTupletDotSet() { _tupletDotSet.clear(); }

  void TupletPortion::ostreamContents(pugi::xml_node& self) const
  {
    if(_tupletNumberPtr) {
      auto child = self.append_child("tuplet-number");
      _tupletNumberPtr->ostream(child);
    }
    if(_tupletTypePtr) {
      auto child = self.append_child("tuplet-type");
      _tupletTypePtr->ostream(child);
    }
    for(auto item : _tupletDotSet) {
      auto child = self.append_child("tuplet-dot");
      item->ostream(child);
    }
  }
  void TupletPortion::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "tuplet-number")==0) {
        auto tupletNumberPtr = std::make_shared<TupletNumber>();
        tupletNumberPtr->istream(child);
        setTupletNumber(tupletNumberPtr);
      }
      else if(strcmp(child.name(), "tuplet-type")==0) {
        auto tupletTypePtr = std::make_shared<TupletType>();
        tupletTypePtr->istream(child);
        setTupletType(tupletTypePtr);
      }
      else if(strcmp(child.name(), "tuplet-dot")==0) {
        auto tupletDotPtr = std::make_shared<TupletDot>();
        tupletDotPtr->istream(child);
        addTupletDot(tupletDotPtr);
      }
    }
  }
}
