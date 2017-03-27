#ifndef SCORDATURA_H
#define SCORDATURA_H
#include "Element.h"

namespace mxml
{
  class Accord;
  using AccordPtr = std::shared_ptr<Accord>;
  using AccordSet = std::vector<AccordPtr>;

  class Scordatura: public Element
  {
  public:
    Scordatura();
    virtual const char* tagname() const { return "scordatura"; }
    const AccordSet& getAccordSet() const;
    void removeAccord(const AccordPtr& value);
    void addAccord(const AccordPtr& value);
    void clearAccordSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    AccordSet _accordSet;
  };
}
#endif //SCORDATURA_H
