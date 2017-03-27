#ifndef SYSTEM_MARGINS_H
#define SYSTEM_MARGINS_H
#include "Element.h"

namespace mxml
{
  class LeftMargin;
  using LeftMarginPtr = std::shared_ptr<LeftMargin>;
  class RightMargin;
  using RightMarginPtr = std::shared_ptr<RightMargin>;

  class SystemMargins: public Element
  {
  public:
    SystemMargins();
    virtual const char* tagname() const { return "system-margins"; }
    LeftMarginPtr getLeftMargin() const;
    void setLeftMargin(const LeftMarginPtr& value);
    RightMarginPtr getRightMargin() const;
    void setRightMargin(const RightMarginPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    LeftMarginPtr _leftMarginPtr;
    RightMarginPtr _rightMarginPtr;
  };
}
#endif //SYSTEM_MARGINS_H
