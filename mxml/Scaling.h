#ifndef SCALING_H
#define SCALING_H
#include "Element.h"

namespace mxml
{
  class Millimeters;
  using MillimetersPtr = std::shared_ptr<Millimeters>;
  class Tenths;
  using TenthsPtr = std::shared_ptr<Tenths>;

  class Scaling: public Element
  {
  public:
    Scaling();
    virtual const char* tagname() const { return "scaling"; }
    MillimetersPtr getMillimeters() const;
    void setMillimeters(const MillimetersPtr& value);
    TenthsPtr getTenths() const;
    void setTenths(const TenthsPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MillimetersPtr _millimetersPtr;
    TenthsPtr _tenthsPtr;
  };
}
#endif //SCALING_H
