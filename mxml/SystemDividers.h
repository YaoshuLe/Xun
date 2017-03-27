#ifndef SYSTEM_DIVIDERS_H
#define SYSTEM_DIVIDERS_H
#include "Element.h"

namespace mxml
{
  class LeftDivider;
  using LeftDividerPtr = std::shared_ptr<LeftDivider>;
  class RightDivider;
  using RightDividerPtr = std::shared_ptr<RightDivider>;

  class SystemDividers: public Element
  {
  public:
    SystemDividers();
    virtual const char* tagname() const { return "system-dividers"; }
    LeftDividerPtr getLeftDivider() const;
    void setLeftDivider(const LeftDividerPtr& value);
    RightDividerPtr getRightDivider() const;
    void setRightDivider(const RightDividerPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    LeftDividerPtr _leftDividerPtr;
    RightDividerPtr _rightDividerPtr;
  };
}
#endif //SYSTEM_DIVIDERS_H
