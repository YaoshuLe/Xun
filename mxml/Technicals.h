#ifndef TECHNICALS_H
#define TECHNICALS_H
#include "Element.h"

namespace mxml
{
  using Technical = Element;
  using TechnicalPtr = std::shared_ptr<Technical>;
  using TechnicalSet = std::vector<TechnicalPtr>;
  class UpBow;
  using UpBowPtr = std::shared_ptr<UpBow>;
  class DownBow;
  using DownBowPtr = std::shared_ptr<DownBow>;
  class Harmonic;
  using HarmonicPtr = std::shared_ptr<Harmonic>;
  class OpenString;
  using OpenStringPtr = std::shared_ptr<OpenString>;
  class ThumbPosition;
  using ThumbPositionPtr = std::shared_ptr<ThumbPosition>;
  class Fingering;
  using FingeringPtr = std::shared_ptr<Fingering>;
  class Pluck;
  using PluckPtr = std::shared_ptr<Pluck>;
  class DoubleTongue;
  using DoubleTonguePtr = std::shared_ptr<DoubleTongue>;
  class TripleTongue;
  using TripleTonguePtr = std::shared_ptr<TripleTongue>;
  class Stopped;
  using StoppedPtr = std::shared_ptr<Stopped>;
  class SnapPizzicato;
  using SnapPizzicatoPtr = std::shared_ptr<SnapPizzicato>;
  class Fret;
  using FretPtr = std::shared_ptr<Fret>;
  class String;
  using StringPtr = std::shared_ptr<String>;
  class HammerOn;
  using HammerOnPtr = std::shared_ptr<HammerOn>;
  class PullOff;
  using PullOffPtr = std::shared_ptr<PullOff>;
  class Bend;
  using BendPtr = std::shared_ptr<Bend>;
  class Tap;
  using TapPtr = std::shared_ptr<Tap>;
  class Heel;
  using HeelPtr = std::shared_ptr<Heel>;
  class Toe;
  using ToePtr = std::shared_ptr<Toe>;
  class Fingernails;
  using FingernailsPtr = std::shared_ptr<Fingernails>;
  class Hole;
  using HolePtr = std::shared_ptr<Hole>;
  class Arrow;
  using ArrowPtr = std::shared_ptr<Arrow>;
  class Handbell;
  using HandbellPtr = std::shared_ptr<Handbell>;
  class OtherTechnical;
  using OtherTechnicalPtr = std::shared_ptr<OtherTechnical>;

  class Technicals: public Element
  {
  public:
    Technicals();
    virtual const char* tagname() const { return "technical"; }
    const TechnicalSet& getTechnicalSet() const;
    void removeTechnical(const TechnicalPtr& value);
    void addTechnical(const TechnicalPtr& value);
    void clearTechnicalSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    TechnicalSet _technicalSet;
  };
}
#endif //TECHNICALS_H
