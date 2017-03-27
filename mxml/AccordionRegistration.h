#ifndef ACCORDION_REGISTRATION_H
#define ACCORDION_REGISTRATION_H
#include "Element.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class AccordionHigh;
  using AccordionHighPtr = std::shared_ptr<AccordionHigh>;
  class AccordionMiddle;
  using AccordionMiddlePtr = std::shared_ptr<AccordionMiddle>;
  class AccordionLow;
  using AccordionLowPtr = std::shared_ptr<AccordionLow>;

  class AccordionRegistration: public Element, public PrintStyleAlign
  {
  public:
    AccordionRegistration();
    virtual const char* tagname() const { return "accordion-registration"; }
    AccordionHighPtr getAccordionHigh() const;
    void setAccordionHigh(const AccordionHighPtr& value);
    AccordionMiddlePtr getAccordionMiddle() const;
    void setAccordionMiddle(const AccordionMiddlePtr& value);
    AccordionLowPtr getAccordionLow() const;
    void setAccordionLow(const AccordionLowPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    AccordionHighPtr _accordionHighPtr;
    AccordionMiddlePtr _accordionMiddlePtr;
    AccordionLowPtr _accordionLowPtr;
  };
}
#endif //ACCORDION_REGISTRATION_H
