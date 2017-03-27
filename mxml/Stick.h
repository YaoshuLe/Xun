#ifndef STICK_H
#define STICK_H
#include "Element.h"

namespace mxml
{
  class StickType;
  using StickTypePtr = std::shared_ptr<StickType>;
  class StickMaterial;
  using StickMaterialPtr = std::shared_ptr<StickMaterial>;

  class Stick: public Element
  {
  public:
    Stick();
    virtual const char* tagname() const { return "stick"; }
    StickTypePtr getStickType() const;
    void setStickType(const StickTypePtr& value);
    StickMaterialPtr getStickMaterial() const;
    void setStickMaterial(const StickMaterialPtr& value);
    bool hasTip() const;
    void hasTip(bool value);
    TipDirectionEnum tip() const;
    void tip(TipDirectionEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    StickTypePtr _stickTypePtr;
    StickMaterialPtr _stickMaterialPtr;
    bool _hasTip {false};
    TipDirectionEnum _tip;
  };
}
#endif //STICK_H
