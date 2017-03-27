#ifndef ARTICULATIONS_H
#define ARTICULATIONS_H
#include "Element.h"

namespace mxml
{
  using Articulation = Element;
  using ArticulationPtr = std::shared_ptr<Articulation>;
  using ArticulationSet = std::vector<ArticulationPtr>;
  class Accent;
  using AccentPtr = std::shared_ptr<Accent>;
  class StrongAccent;
  using StrongAccentPtr = std::shared_ptr<StrongAccent>;
  class Staccato;
  using StaccatoPtr = std::shared_ptr<Staccato>;
  class Tenuto;
  using TenutoPtr = std::shared_ptr<Tenuto>;
  class DetachedLegato;
  using DetachedLegatoPtr = std::shared_ptr<DetachedLegato>;
  class Staccatissimo;
  using StaccatissimoPtr = std::shared_ptr<Staccatissimo>;
  class Spiccato;
  using SpiccatoPtr = std::shared_ptr<Spiccato>;
  class Scoop;
  using ScoopPtr = std::shared_ptr<Scoop>;
  class Plop;
  using PlopPtr = std::shared_ptr<Plop>;
  class Doit;
  using DoitPtr = std::shared_ptr<Doit>;
  class Falloff;
  using FalloffPtr = std::shared_ptr<Falloff>;
  class BreathMark;
  using BreathMarkPtr = std::shared_ptr<BreathMark>;
  class Caesura;
  using CaesuraPtr = std::shared_ptr<Caesura>;
  class Stress;
  using StressPtr = std::shared_ptr<Stress>;
  class Unstress;
  using UnstressPtr = std::shared_ptr<Unstress>;
  class OtherArticulation;
  using OtherArticulationPtr = std::shared_ptr<OtherArticulation>;

  class Articulations: public Element
  {
  public:
    Articulations();
    virtual const char* tagname() const { return "articulations"; }
    const ArticulationSet& getArticulationSet() const;
    void removeArticulation(const ArticulationPtr& value);
    void addArticulation(const ArticulationPtr& value);
    void clearArticulationSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    ArticulationSet _articulationSet;
  };
}
#endif //ARTICULATIONS_H
