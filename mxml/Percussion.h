#ifndef PERCUSSION_H
#define PERCUSSION_H
#include "Element.h"
#include "PrintStyleAlign.h"
#include "Enclosure.h"

namespace mxml
{
  class Glass;
  using GlassPtr = std::shared_ptr<Glass>;
  class Metal;
  using MetalPtr = std::shared_ptr<Metal>;
  class Wood;
  using WoodPtr = std::shared_ptr<Wood>;
  class Pitched;
  using PitchedPtr = std::shared_ptr<Pitched>;
  class Membrane;
  using MembranePtr = std::shared_ptr<Membrane>;
  class Effect;
  using EffectPtr = std::shared_ptr<Effect>;
  class Timpani;
  using TimpaniPtr = std::shared_ptr<Timpani>;
  class Beater;
  using BeaterPtr = std::shared_ptr<Beater>;
  class Stick;
  using StickPtr = std::shared_ptr<Stick>;
  class StickLocation;
  using StickLocationPtr = std::shared_ptr<StickLocation>;
  class OtherPercussion;
  using OtherPercussionPtr = std::shared_ptr<OtherPercussion>;

  class Percussion: public Element, public PrintStyleAlign, public Enclosure
  {
  public:
    Percussion();
    virtual const char* tagname() const { return "percussion"; }
    GlassPtr getGlass() const;
    void setGlass(const GlassPtr& value);
    MetalPtr getMetal() const;
    void setMetal(const MetalPtr& value);
    WoodPtr getWood() const;
    void setWood(const WoodPtr& value);
    PitchedPtr getPitched() const;
    void setPitched(const PitchedPtr& value);
    MembranePtr getMembrane() const;
    void setMembrane(const MembranePtr& value);
    EffectPtr getEffect() const;
    void setEffect(const EffectPtr& value);
    TimpaniPtr getTimpani() const;
    void setTimpani(const TimpaniPtr& value);
    BeaterPtr getBeater() const;
    void setBeater(const BeaterPtr& value);
    StickPtr getStick() const;
    void setStick(const StickPtr& value);
    StickLocationPtr getStickLocation() const;
    void setStickLocation(const StickLocationPtr& value);
    OtherPercussionPtr getOtherPercussion() const;
    void setOtherPercussion(const OtherPercussionPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    GlassPtr _glassPtr;
    MetalPtr _metalPtr;
    WoodPtr _woodPtr;
    PitchedPtr _pitchedPtr;
    MembranePtr _membranePtr;
    EffectPtr _effectPtr;
    TimpaniPtr _timpaniPtr;
    BeaterPtr _beaterPtr;
    StickPtr _stickPtr;
    StickLocationPtr _stickLocationPtr;
    OtherPercussionPtr _otherPercussionPtr;
  };
}
#endif //PERCUSSION_H
