#include "Stick.h"
#include <cstring>
#include "StickType.h"
#include "StickMaterial.h"

namespace mxml
{
  Stick::Stick() {}
  StickTypePtr Stick::getStickType() const { return _stickTypePtr; }
  void Stick::setStickType(const StickTypePtr& value) { _stickTypePtr = value; value->setParent(shared_from_this()); }
  StickMaterialPtr Stick::getStickMaterial() const { return _stickMaterialPtr; }
  void Stick::setStickMaterial(const StickMaterialPtr& value) { _stickMaterialPtr = value; value->setParent(shared_from_this()); }
  bool Stick::hasTip() const { return _hasTip; }
  void Stick::hasTip(bool value) { _hasTip = value; }
  TipDirectionEnum Stick::tip() const { return _tip; }
  void Stick::tip(TipDirectionEnum value) { _tip = value; }

  void Stick::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasTip) {
      self.append_attribute("tip").set_value(_tip.operator const char *());
    }
  }
  void Stick::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("tip")) {
      _tip = TipDirectionEnum(attr.as_string());
      _hasTip = true;
    }
  }
  void Stick::ostreamContents(pugi::xml_node& self) const
  {
    if(_stickTypePtr) {
      auto child = self.append_child("stick-type");
      _stickTypePtr->ostream(child);
    }
    if(_stickMaterialPtr) {
      auto child = self.append_child("stick-material");
      _stickMaterialPtr->ostream(child);
    }
  }
  void Stick::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "stick-type")==0) {
        auto stickTypePtr = std::make_shared<StickType>();
        stickTypePtr->istream(child);
        setStickType(stickTypePtr);
      }
      else if(strcmp(child.name(), "stick-material")==0) {
        auto stickMaterialPtr = std::make_shared<StickMaterial>();
        stickMaterialPtr->istream(child);
        setStickMaterial(stickMaterialPtr);
      }
    }
  }
}
