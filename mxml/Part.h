#ifndef PART_H
#define PART_H
#include "Element.h"
#include "PartAttributes.h"

namespace mxml
{
  class Measure;
  using MeasurePtr = std::shared_ptr<Measure>;
  using MeasureSet = std::vector<MeasurePtr>;

  class Part: public Element, public PartAttributes
  {
  public:
    Part();
    virtual const char* tagname() const { return "part"; }
    const MeasureSet& getMeasureSet() const;
    void removeMeasure(const MeasurePtr& value);
    void addMeasure(const MeasurePtr& value);
    void clearMeasureSet();
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MeasureSet _measureSet;
  };
}
#endif //PART_H
