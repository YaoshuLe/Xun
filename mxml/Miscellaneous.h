#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H
#include "Element.h"

namespace mxml
{
  class MiscellaneousField;
  using MiscellaneousFieldPtr = std::shared_ptr<MiscellaneousField>;
  using MiscellaneousFieldSet = std::vector<MiscellaneousFieldPtr>;

  class Miscellaneous: public Element
  {
  public:
    Miscellaneous();
    virtual const char* tagname() const { return "miscellaneous"; }
    const MiscellaneousFieldSet& getMiscellaneousFieldSet() const;
    void removeMiscellaneousField(const MiscellaneousFieldPtr& value);
    void addMiscellaneousField(const MiscellaneousFieldPtr& value);
    void clearMiscellaneousFieldSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MiscellaneousFieldSet _miscellaneousFieldSet;
  };
}
#endif //MISCELLANEOUS_H
