#include "Print.h"
#include <cstring>
#include "PageLayout.h"
#include "SystemLayout.h"
#include "StaffLayout.h"
#include "MeasureLayout.h"
#include "MeasureNumbering.h"
#include "PartNameDisplay.h"
#include "PartAbbreviationDisplay.h"

namespace mxml
{
  Print::Print() {}
  PageLayoutPtr Print::getPageLayout() const { return _pageLayoutPtr; }
  void Print::setPageLayout(const PageLayoutPtr& value) { _pageLayoutPtr = value; value->setParent(shared_from_this()); }
  SystemLayoutPtr Print::getSystemLayout() const { return _systemLayoutPtr; }
  void Print::setSystemLayout(const SystemLayoutPtr& value) { _systemLayoutPtr = value; value->setParent(shared_from_this()); }
  const StaffLayoutSet& Print::getStaffLayoutSet() const {  return _staffLayoutSet; }
  void Print::removeStaffLayout(const StaffLayoutPtr& value) { if(value) { auto i = std::find_if(_staffLayoutSet.begin(), _staffLayoutSet.end(), [&](const StaffLayoutPtr& item) { return item==value; }); if(i!=_staffLayoutSet.end()) _staffLayoutSet.erase(i); } } 
  void Print::addStaffLayout(const StaffLayoutPtr& value) { if(value) { _staffLayoutSet.push_back(value); value->setParent(shared_from_this()); } }
  void Print::clearStaffLayoutSet() { _staffLayoutSet.clear(); }
  MeasureLayoutPtr Print::getMeasureLayout() const { return _measureLayoutPtr; }
  void Print::setMeasureLayout(const MeasureLayoutPtr& value) { _measureLayoutPtr = value; value->setParent(shared_from_this()); }
  MeasureNumberingPtr Print::getMeasureNumbering() const { return _measureNumberingPtr; }
  void Print::setMeasureNumbering(const MeasureNumberingPtr& value) { _measureNumberingPtr = value; value->setParent(shared_from_this()); }
  PartNameDisplayPtr Print::getPartNameDisplay() const { return _partNameDisplayPtr; }
  void Print::setPartNameDisplay(const PartNameDisplayPtr& value) { _partNameDisplayPtr = value; value->setParent(shared_from_this()); }
  PartAbbreviationDisplayPtr Print::getPartAbbreviationDisplay() const { return _partAbbreviationDisplayPtr; }
  void Print::setPartAbbreviationDisplay(const PartAbbreviationDisplayPtr& value) { _partAbbreviationDisplayPtr = value; value->setParent(shared_from_this()); }

  void Print::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintAttributes::ostreamAttrs(self);
  }
  void Print::istreamAttrs(const pugi::xml_node& self)
  {
    PrintAttributes::istreamAttrs(self);
  }
  void Print::ostreamContents(pugi::xml_node& self) const
  {
    if(_pageLayoutPtr) {
      auto child = self.append_child("page-layout");
      _pageLayoutPtr->ostream(child);
    }
    if(_systemLayoutPtr) {
      auto child = self.append_child("system-layout");
      _systemLayoutPtr->ostream(child);
    }
    for(auto item : _staffLayoutSet) {
      auto child = self.append_child("staff-layout");
      item->ostream(child);
    }
    if(_measureLayoutPtr) {
      auto child = self.append_child("measure-layout");
      _measureLayoutPtr->ostream(child);
    }
    if(_measureNumberingPtr) {
      auto child = self.append_child("measure-numbering");
      _measureNumberingPtr->ostream(child);
    }
    if(_partNameDisplayPtr) {
      auto child = self.append_child("part-name-display");
      _partNameDisplayPtr->ostream(child);
    }
    if(_partAbbreviationDisplayPtr) {
      auto child = self.append_child("part-abbreviation-display");
      _partAbbreviationDisplayPtr->ostream(child);
    }
  }
  void Print::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "page-layout")==0) {
        auto pageLayoutPtr = std::make_shared<PageLayout>();
        pageLayoutPtr->istream(child);
        setPageLayout(pageLayoutPtr);
      }
      else if(strcmp(child.name(), "system-layout")==0) {
        auto systemLayoutPtr = std::make_shared<SystemLayout>();
        systemLayoutPtr->istream(child);
        setSystemLayout(systemLayoutPtr);
      }
      else if(strcmp(child.name(), "staff-layout")==0) {
        auto staffLayoutPtr = std::make_shared<StaffLayout>();
        staffLayoutPtr->istream(child);
        addStaffLayout(staffLayoutPtr);
      }
      else if(strcmp(child.name(), "measure-layout")==0) {
        auto measureLayoutPtr = std::make_shared<MeasureLayout>();
        measureLayoutPtr->istream(child);
        setMeasureLayout(measureLayoutPtr);
      }
      else if(strcmp(child.name(), "measure-numbering")==0) {
        auto measureNumberingPtr = std::make_shared<MeasureNumbering>();
        measureNumberingPtr->istream(child);
        setMeasureNumbering(measureNumberingPtr);
      }
      else if(strcmp(child.name(), "part-name-display")==0) {
        auto partNameDisplayPtr = std::make_shared<PartNameDisplay>();
        partNameDisplayPtr->istream(child);
        setPartNameDisplay(partNameDisplayPtr);
      }
      else if(strcmp(child.name(), "part-abbreviation-display")==0) {
        auto partAbbreviationDisplayPtr = std::make_shared<PartAbbreviationDisplay>();
        partAbbreviationDisplayPtr->istream(child);
        setPartAbbreviationDisplay(partAbbreviationDisplayPtr);
      }
    }
  }
}
