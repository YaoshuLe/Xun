#ifndef METRONOME_NOTE_H
#define METRONOME_NOTE_H
#include "Element.h"

namespace mxml
{
  class MetronomeType;
  using MetronomeTypePtr = std::shared_ptr<MetronomeType>;
  class MetronomeDot;
  using MetronomeDotPtr = std::shared_ptr<MetronomeDot>;
  using MetronomeDotSet = std::vector<MetronomeDotPtr>;
  class MetronomeBeam;
  using MetronomeBeamPtr = std::shared_ptr<MetronomeBeam>;
  using MetronomeBeamSet = std::vector<MetronomeBeamPtr>;
  class MetronomeTuplet;
  using MetronomeTupletPtr = std::shared_ptr<MetronomeTuplet>;

  class MetronomeNote: public Element
  {
  public:
    MetronomeNote();
    virtual const char* tagname() const { return "metronome-note"; }
    MetronomeTypePtr getMetronomeType() const;
    void setMetronomeType(const MetronomeTypePtr& value);
    const MetronomeDotSet& getMetronomeDotSet() const;
    void removeMetronomeDot(const MetronomeDotPtr& value);
    void addMetronomeDot(const MetronomeDotPtr& value);
    void clearMetronomeDotSet();
    const MetronomeBeamSet& getMetronomeBeamSet() const;
    void removeMetronomeBeam(const MetronomeBeamPtr& value);
    void addMetronomeBeam(const MetronomeBeamPtr& value);
    void clearMetronomeBeamSet();
    MetronomeTupletPtr getMetronomeTuplet() const;
    void setMetronomeTuplet(const MetronomeTupletPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MetronomeTypePtr _metronomeTypePtr;
    MetronomeDotSet _metronomeDotSet;
    MetronomeBeamSet _metronomeBeamSet;
    MetronomeTupletPtr _metronomeTupletPtr;
  };
}
#endif //METRONOME_NOTE_H
