#ifndef STAFF_LAYOUT_H
#define STAFF_LAYOUT_H
#include "Element.h"

namespace mxml
{
  class StaffDistance;
  using StaffDistancePtr = std::shared_ptr<StaffDistance>;

  class StaffLayout: public Element
  {
  public:
    StaffLayout();
    virtual const char* tagname() const { return "staff-layout"; }
    StaffDistancePtr getStaffDistance() const;
    void setStaffDistance(const StaffDistancePtr& value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    StaffDistancePtr _staffDistancePtr;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //STAFF_LAYOUT_H
