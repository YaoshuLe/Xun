#include "StaffDetails.h"
#include <cstring>
#include "StaffType.h"
#include "StaffLines.h"
#include "StaffTuning.h"
#include "Capo.h"
#include "StaffSize.h"

namespace mxml
{
  StaffDetails::StaffDetails() {}
  StaffTypePtr StaffDetails::getStaffType() const { return _staffTypePtr; }
  void StaffDetails::setStaffType(const StaffTypePtr& value) { _staffTypePtr = value; value->setParent(shared_from_this()); }
  StaffLinesPtr StaffDetails::getStaffLines() const { return _staffLinesPtr; }
  void StaffDetails::setStaffLines(const StaffLinesPtr& value) { _staffLinesPtr = value; value->setParent(shared_from_this()); }
  const StaffTuningSet& StaffDetails::getStaffTuningSet() const {  return _staffTuningSet; }
  void StaffDetails::removeStaffTuning(const StaffTuningPtr& value) { if(value) { auto i = std::find_if(_staffTuningSet.begin(), _staffTuningSet.end(), [&](const StaffTuningPtr& item) { return item==value; }); if(i!=_staffTuningSet.end()) _staffTuningSet.erase(i); } } 
  void StaffDetails::addStaffTuning(const StaffTuningPtr& value) { if(value) { _staffTuningSet.push_back(value); value->setParent(shared_from_this()); } }
  void StaffDetails::clearStaffTuningSet() { _staffTuningSet.clear(); }
  CapoPtr StaffDetails::getCapo() const { return _capoPtr; }
  void StaffDetails::setCapo(const CapoPtr& value) { _capoPtr = value; value->setParent(shared_from_this()); }
  StaffSizePtr StaffDetails::getStaffSize() const { return _staffSizePtr; }
  void StaffDetails::setStaffSize(const StaffSizePtr& value) { _staffSizePtr = value; value->setParent(shared_from_this()); }
  bool StaffDetails::hasNumber() const { return _hasNumber; }
  void StaffDetails::hasNumber(bool value) { _hasNumber = value; }
  int StaffDetails::number() const { return _number; }
  void StaffDetails::number(int value) { _number = value; }
  bool StaffDetails::hasShowFrets() const { return _hasShowFrets; }
  void StaffDetails::hasShowFrets(bool value) { _hasShowFrets = value; }
  ShowFretsEnum StaffDetails::showFrets() const { return _showFrets; }
  void StaffDetails::showFrets(ShowFretsEnum value) { _showFrets = value; }

  void StaffDetails::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintObject::ostreamAttrs(self);
    PrintSpacing::ostreamAttrs(self);
    if(_hasNumber) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _number);
      self.append_attribute("number").set_value(str);
    }
    if(_hasShowFrets) {
      self.append_attribute("show-frets").set_value(_showFrets.operator const char *());
    }
  }
  void StaffDetails::istreamAttrs(const pugi::xml_node& self)
  {
    PrintObject::istreamAttrs(self);
    PrintSpacing::istreamAttrs(self);
    if(auto attr = self.attribute("number")) {
      _number = attr.as_int();
      _hasNumber = true;
    }
    if(auto attr = self.attribute("show-frets")) {
      _showFrets = ShowFretsEnum(attr.as_string());
      _hasShowFrets = true;
    }
  }
  void StaffDetails::ostreamContents(pugi::xml_node& self) const
  {
    if(_staffTypePtr) {
      auto child = self.append_child("staff-type");
      _staffTypePtr->ostream(child);
    }
    if(_staffLinesPtr) {
      auto child = self.append_child("staff-lines");
      _staffLinesPtr->ostream(child);
    }
    for(auto item : _staffTuningSet) {
      auto child = self.append_child("staff-tuning");
      item->ostream(child);
    }
    if(_capoPtr) {
      auto child = self.append_child("capo");
      _capoPtr->ostream(child);
    }
    if(_staffSizePtr) {
      auto child = self.append_child("staff-size");
      _staffSizePtr->ostream(child);
    }
  }
  void StaffDetails::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "staff-type")==0) {
        auto staffTypePtr = std::make_shared<StaffType>();
        staffTypePtr->istream(child);
        setStaffType(staffTypePtr);
      }
      else if(strcmp(child.name(), "staff-lines")==0) {
        auto staffLinesPtr = std::make_shared<StaffLines>();
        staffLinesPtr->istream(child);
        setStaffLines(staffLinesPtr);
      }
      else if(strcmp(child.name(), "staff-tuning")==0) {
        auto staffTuningPtr = std::make_shared<StaffTuning>();
        staffTuningPtr->istream(child);
        addStaffTuning(staffTuningPtr);
      }
      else if(strcmp(child.name(), "capo")==0) {
        auto capoPtr = std::make_shared<Capo>();
        capoPtr->istream(child);
        setCapo(capoPtr);
      }
      else if(strcmp(child.name(), "staff-size")==0) {
        auto staffSizePtr = std::make_shared<StaffSize>();
        staffSizePtr->istream(child);
        setStaffSize(staffSizePtr);
      }
    }
  }
}
