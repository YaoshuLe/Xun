#ifndef MEASURE_LAYOUT_H
#define MEASURE_LAYOUT_H
#include "Element.h"

namespace mxml
{
  class MeasureDistance;
  using MeasureDistancePtr = std::shared_ptr<MeasureDistance>;

  class MeasureLayout: public Element
  {
  public:
    MeasureLayout();
    virtual const char* tagname() const { return "measure-layout"; }
    MeasureDistancePtr getMeasureDistance() const;
    void setMeasureDistance(const MeasureDistancePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MeasureDistancePtr _measureDistancePtr;
  };
}
#endif //MEASURE_LAYOUT_H
