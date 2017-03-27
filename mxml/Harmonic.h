#ifndef HARMONIC_H
#define HARMONIC_H
#include "Element.h"
#include "PrintObject.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class Natural;
  using NaturalPtr = std::shared_ptr<Natural>;
  class Artificial;
  using ArtificialPtr = std::shared_ptr<Artificial>;
  class BasePitch;
  using BasePitchPtr = std::shared_ptr<BasePitch>;
  class TouchingPitch;
  using TouchingPitchPtr = std::shared_ptr<TouchingPitch>;
  class SoundingPitch;
  using SoundingPitchPtr = std::shared_ptr<SoundingPitch>;

  class Harmonic: public Element, public PrintObject, public PrintStyle, public Placement
  {
  public:
    Harmonic();
    virtual const char* tagname() const { return "harmonic"; }
    NaturalPtr getNatural() const;
    void setNatural(const NaturalPtr& value);
    ArtificialPtr getArtificial() const;
    void setArtificial(const ArtificialPtr& value);
    BasePitchPtr getBasePitch() const;
    void setBasePitch(const BasePitchPtr& value);
    TouchingPitchPtr getTouchingPitch() const;
    void setTouchingPitch(const TouchingPitchPtr& value);
    SoundingPitchPtr getSoundingPitch() const;
    void setSoundingPitch(const SoundingPitchPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    NaturalPtr _naturalPtr;
    ArtificialPtr _artificialPtr;
    BasePitchPtr _basePitchPtr;
    TouchingPitchPtr _touchingPitchPtr;
    SoundingPitchPtr _soundingPitchPtr;
  };
}
#endif //HARMONIC_H
