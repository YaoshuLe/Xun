#include "Scaling.h"
#include <cstring>
#include "Millimeters.h"
#include "Tenths.h"

namespace mxml
{
  Scaling::Scaling() {}
  MillimetersPtr Scaling::getMillimeters() const { return _millimetersPtr; }
  void Scaling::setMillimeters(const MillimetersPtr& value) { _millimetersPtr = value; value->setParent(shared_from_this()); }
  TenthsPtr Scaling::getTenths() const { return _tenthsPtr; }
  void Scaling::setTenths(const TenthsPtr& value) { _tenthsPtr = value; value->setParent(shared_from_this()); }

  void Scaling::ostreamContents(pugi::xml_node& self) const
  {
    if(_millimetersPtr) {
      auto child = self.append_child("millimeters");
      _millimetersPtr->ostream(child);
    }
    if(_tenthsPtr) {
      auto child = self.append_child("tenths");
      _tenthsPtr->ostream(child);
    }
  }
  void Scaling::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "millimeters")==0) {
        auto millimetersPtr = std::make_shared<Millimeters>();
        millimetersPtr->istream(child);
        setMillimeters(millimetersPtr);
      }
      else if(strcmp(child.name(), "tenths")==0) {
        auto tenthsPtr = std::make_shared<Tenths>();
        tenthsPtr->istream(child);
        setTenths(tenthsPtr);
      }
    }
  }
}
