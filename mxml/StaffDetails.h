#ifndef STAFF_DETAILS_H
#define STAFF_DETAILS_H
#include "Element.h"
#include "PrintObject.h"
#include "PrintSpacing.h"

namespace mxml
{
  class StaffType;
  using StaffTypePtr = std::shared_ptr<StaffType>;
  class StaffLines;
  using StaffLinesPtr = std::shared_ptr<StaffLines>;
  class StaffTuning;
  using StaffTuningPtr = std::shared_ptr<StaffTuning>;
  using StaffTuningSet = std::vector<StaffTuningPtr>;
  class Capo;
  using CapoPtr = std::shared_ptr<Capo>;
  class StaffSize;
  using StaffSizePtr = std::shared_ptr<StaffSize>;

  class StaffDetails: public Element, public PrintObject, public PrintSpacing
  {
  public:
    StaffDetails();
    virtual const char* tagname() const { return "staff-details"; }
    StaffTypePtr getStaffType() const;
    void setStaffType(const StaffTypePtr& value);
    StaffLinesPtr getStaffLines() const;
    void setStaffLines(const StaffLinesPtr& value);
    const StaffTuningSet& getStaffTuningSet() const;
    void removeStaffTuning(const StaffTuningPtr& value);
    void addStaffTuning(const StaffTuningPtr& value);
    void clearStaffTuningSet();
    CapoPtr getCapo() const;
    void setCapo(const CapoPtr& value);
    StaffSizePtr getStaffSize() const;
    void setStaffSize(const StaffSizePtr& value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasShowFrets() const;
    void hasShowFrets(bool value);
    ShowFretsEnum showFrets() const;
    void showFrets(ShowFretsEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    StaffTypePtr _staffTypePtr;
    StaffLinesPtr _staffLinesPtr;
    StaffTuningSet _staffTuningSet;
    CapoPtr _capoPtr;
    StaffSizePtr _staffSizePtr;
    bool _hasNumber {false};
    int _number;
    bool _hasShowFrets {false};
    ShowFretsEnum _showFrets;
  };
}
#endif //STAFF_DETAILS_H
