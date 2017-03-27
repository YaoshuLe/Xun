#include "AccordionRegistration.h"
#include <cstring>
#include "AccordionHigh.h"
#include "AccordionMiddle.h"
#include "AccordionLow.h"

namespace mxml
{
  AccordionRegistration::AccordionRegistration() {}
  AccordionHighPtr AccordionRegistration::getAccordionHigh() const { return _accordionHighPtr; }
  void AccordionRegistration::setAccordionHigh(const AccordionHighPtr& value) { _accordionHighPtr = value; value->setParent(shared_from_this()); }
  AccordionMiddlePtr AccordionRegistration::getAccordionMiddle() const { return _accordionMiddlePtr; }
  void AccordionRegistration::setAccordionMiddle(const AccordionMiddlePtr& value) { _accordionMiddlePtr = value; value->setParent(shared_from_this()); }
  AccordionLowPtr AccordionRegistration::getAccordionLow() const { return _accordionLowPtr; }
  void AccordionRegistration::setAccordionLow(const AccordionLowPtr& value) { _accordionLowPtr = value; value->setParent(shared_from_this()); }

  void AccordionRegistration::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyleAlign::ostreamAttrs(self);
  }
  void AccordionRegistration::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyleAlign::istreamAttrs(self);
  }
  void AccordionRegistration::ostreamContents(pugi::xml_node& self) const
  {
    if(_accordionHighPtr) {
      auto child = self.append_child("accordion-high");
      _accordionHighPtr->ostream(child);
    }
    if(_accordionMiddlePtr) {
      auto child = self.append_child("accordion-middle");
      _accordionMiddlePtr->ostream(child);
    }
    if(_accordionLowPtr) {
      auto child = self.append_child("accordion-low");
      _accordionLowPtr->ostream(child);
    }
  }
  void AccordionRegistration::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "accordion-high")==0) {
        auto accordionHighPtr = std::make_shared<AccordionHigh>();
        accordionHighPtr->istream(child);
        setAccordionHigh(accordionHighPtr);
      }
      else if(strcmp(child.name(), "accordion-middle")==0) {
        auto accordionMiddlePtr = std::make_shared<AccordionMiddle>();
        accordionMiddlePtr->istream(child);
        setAccordionMiddle(accordionMiddlePtr);
      }
      else if(strcmp(child.name(), "accordion-low")==0) {
        auto accordionLowPtr = std::make_shared<AccordionLow>();
        accordionLowPtr->istream(child);
        setAccordionLow(accordionLowPtr);
      }
    }
  }
}
