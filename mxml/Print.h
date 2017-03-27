#ifndef PRINT_H
#define PRINT_H
#include "Element.h"
#include "PrintAttributes.h"

namespace mxml
{
  class PageLayout;
  using PageLayoutPtr = std::shared_ptr<PageLayout>;
  class SystemLayout;
  using SystemLayoutPtr = std::shared_ptr<SystemLayout>;
  class StaffLayout;
  using StaffLayoutPtr = std::shared_ptr<StaffLayout>;
  using StaffLayoutSet = std::vector<StaffLayoutPtr>;
  class MeasureLayout;
  using MeasureLayoutPtr = std::shared_ptr<MeasureLayout>;
  class MeasureNumbering;
  using MeasureNumberingPtr = std::shared_ptr<MeasureNumbering>;
  class PartNameDisplay;
  using PartNameDisplayPtr = std::shared_ptr<PartNameDisplay>;
  class PartAbbreviationDisplay;
  using PartAbbreviationDisplayPtr = std::shared_ptr<PartAbbreviationDisplay>;

  class Print: public Element, public PrintAttributes
  {
  public:
    Print();
    virtual const char* tagname() const { return "print"; }
    PageLayoutPtr getPageLayout() const;
    void setPageLayout(const PageLayoutPtr& value);
    SystemLayoutPtr getSystemLayout() const;
    void setSystemLayout(const SystemLayoutPtr& value);
    const StaffLayoutSet& getStaffLayoutSet() const;
    void removeStaffLayout(const StaffLayoutPtr& value);
    void addStaffLayout(const StaffLayoutPtr& value);
    void clearStaffLayoutSet();
    MeasureLayoutPtr getMeasureLayout() const;
    void setMeasureLayout(const MeasureLayoutPtr& value);
    MeasureNumberingPtr getMeasureNumbering() const;
    void setMeasureNumbering(const MeasureNumberingPtr& value);
    PartNameDisplayPtr getPartNameDisplay() const;
    void setPartNameDisplay(const PartNameDisplayPtr& value);
    PartAbbreviationDisplayPtr getPartAbbreviationDisplay() const;
    void setPartAbbreviationDisplay(const PartAbbreviationDisplayPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    PageLayoutPtr _pageLayoutPtr;
    SystemLayoutPtr _systemLayoutPtr;
    StaffLayoutSet _staffLayoutSet;
    MeasureLayoutPtr _measureLayoutPtr;
    MeasureNumberingPtr _measureNumberingPtr;
    PartNameDisplayPtr _partNameDisplayPtr;
    PartAbbreviationDisplayPtr _partAbbreviationDisplayPtr;
  };
}
#endif //PRINT_H
