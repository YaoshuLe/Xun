#ifndef ARROW_H
#define ARROW_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class ArrowDirection;
  using ArrowDirectionPtr = std::shared_ptr<ArrowDirection>;
  class ArrowStyle;
  using ArrowStylePtr = std::shared_ptr<ArrowStyle>;
  class CircularArrow;
  using CircularArrowPtr = std::shared_ptr<CircularArrow>;

  class Arrow: public Element, public PrintStyle, public Placement
  {
  public:
    Arrow();
    virtual const char* tagname() const { return "arrow"; }
    ArrowDirectionPtr getArrowDirection() const;
    void setArrowDirection(const ArrowDirectionPtr& value);
    ArrowStylePtr getArrowStyle() const;
    void setArrowStyle(const ArrowStylePtr& value);
    CircularArrowPtr getCircularArrow() const;
    void setCircularArrow(const CircularArrowPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    ArrowDirectionPtr _arrowDirectionPtr;
    ArrowStylePtr _arrowStylePtr;
    CircularArrowPtr _circularArrowPtr;
  };
}
#endif //ARROW_H
