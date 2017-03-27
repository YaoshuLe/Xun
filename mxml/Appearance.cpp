#include "Appearance.h"
#include <cstring>
#include "LineWidth.h"
#include "NoteSize.h"
#include "Distance.h"
#include "OtherAppearance.h"

namespace mxml
{
  Appearance::Appearance() {}
  const LineWidthSet& Appearance::getLineWidthSet() const {  return _lineWidthSet; }
  void Appearance::removeLineWidth(const LineWidthPtr& value) { if(value) { auto i = std::find_if(_lineWidthSet.begin(), _lineWidthSet.end(), [&](const LineWidthPtr& item) { return item==value; }); if(i!=_lineWidthSet.end()) _lineWidthSet.erase(i); } } 
  void Appearance::addLineWidth(const LineWidthPtr& value) { if(value) { _lineWidthSet.push_back(value); value->setParent(shared_from_this()); } }
  void Appearance::clearLineWidthSet() { _lineWidthSet.clear(); }
  const NoteSizeSet& Appearance::getNoteSizeSet() const {  return _noteSizeSet; }
  void Appearance::removeNoteSize(const NoteSizePtr& value) { if(value) { auto i = std::find_if(_noteSizeSet.begin(), _noteSizeSet.end(), [&](const NoteSizePtr& item) { return item==value; }); if(i!=_noteSizeSet.end()) _noteSizeSet.erase(i); } } 
  void Appearance::addNoteSize(const NoteSizePtr& value) { if(value) { _noteSizeSet.push_back(value); value->setParent(shared_from_this()); } }
  void Appearance::clearNoteSizeSet() { _noteSizeSet.clear(); }
  const DistanceSet& Appearance::getDistanceSet() const {  return _distanceSet; }
  void Appearance::removeDistance(const DistancePtr& value) { if(value) { auto i = std::find_if(_distanceSet.begin(), _distanceSet.end(), [&](const DistancePtr& item) { return item==value; }); if(i!=_distanceSet.end()) _distanceSet.erase(i); } } 
  void Appearance::addDistance(const DistancePtr& value) { if(value) { _distanceSet.push_back(value); value->setParent(shared_from_this()); } }
  void Appearance::clearDistanceSet() { _distanceSet.clear(); }
  const OtherAppearanceSet& Appearance::getOtherAppearanceSet() const {  return _otherAppearanceSet; }
  void Appearance::removeOtherAppearance(const OtherAppearancePtr& value) { if(value) { auto i = std::find_if(_otherAppearanceSet.begin(), _otherAppearanceSet.end(), [&](const OtherAppearancePtr& item) { return item==value; }); if(i!=_otherAppearanceSet.end()) _otherAppearanceSet.erase(i); } } 
  void Appearance::addOtherAppearance(const OtherAppearancePtr& value) { if(value) { _otherAppearanceSet.push_back(value); value->setParent(shared_from_this()); } }
  void Appearance::clearOtherAppearanceSet() { _otherAppearanceSet.clear(); }

  void Appearance::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _lineWidthSet) {
      auto child = self.append_child("line-width");
      item->ostream(child);
    }
    for(auto item : _noteSizeSet) {
      auto child = self.append_child("note-size");
      item->ostream(child);
    }
    for(auto item : _distanceSet) {
      auto child = self.append_child("distance");
      item->ostream(child);
    }
    for(auto item : _otherAppearanceSet) {
      auto child = self.append_child("other-appearance");
      item->ostream(child);
    }
  }
  void Appearance::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "line-width")==0) {
        auto lineWidthPtr = std::make_shared<LineWidth>();
        lineWidthPtr->istream(child);
        addLineWidth(lineWidthPtr);
      }
      else if(strcmp(child.name(), "note-size")==0) {
        auto noteSizePtr = std::make_shared<NoteSize>();
        noteSizePtr->istream(child);
        addNoteSize(noteSizePtr);
      }
      else if(strcmp(child.name(), "distance")==0) {
        auto distancePtr = std::make_shared<Distance>();
        distancePtr->istream(child);
        addDistance(distancePtr);
      }
      else if(strcmp(child.name(), "other-appearance")==0) {
        auto otherAppearancePtr = std::make_shared<OtherAppearance>();
        otherAppearancePtr->istream(child);
        addOtherAppearance(otherAppearancePtr);
      }
    }
  }
}
