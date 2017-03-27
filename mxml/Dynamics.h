#ifndef DYNAMICS_H
#define DYNAMICS_H
#include "Element.h"
#include "PrintStyleAlign.h"
#include "Placement.h"
#include "TextDecoration.h"
#include "Enclosure.h"

namespace mxml
{
  using Dynamic = Element;
  using DynamicPtr = std::shared_ptr<Dynamic>;
  using DynamicSet = std::vector<DynamicPtr>;
  class P;
  using PPtr = std::shared_ptr<P>;
  class Pp;
  using PpPtr = std::shared_ptr<Pp>;
  class Ppp;
  using PppPtr = std::shared_ptr<Ppp>;
  class Pppp;
  using PpppPtr = std::shared_ptr<Pppp>;
  class Ppppp;
  using PppppPtr = std::shared_ptr<Ppppp>;
  class Pppppp;
  using PpppppPtr = std::shared_ptr<Pppppp>;
  class F;
  using FPtr = std::shared_ptr<F>;
  class Ff;
  using FfPtr = std::shared_ptr<Ff>;
  class Fff;
  using FffPtr = std::shared_ptr<Fff>;
  class Ffff;
  using FfffPtr = std::shared_ptr<Ffff>;
  class Fffff;
  using FffffPtr = std::shared_ptr<Fffff>;
  class Ffffff;
  using FfffffPtr = std::shared_ptr<Ffffff>;
  class Mp;
  using MpPtr = std::shared_ptr<Mp>;
  class Mf;
  using MfPtr = std::shared_ptr<Mf>;
  class Sf;
  using SfPtr = std::shared_ptr<Sf>;
  class Sfp;
  using SfpPtr = std::shared_ptr<Sfp>;
  class Sfpp;
  using SfppPtr = std::shared_ptr<Sfpp>;
  class Fp;
  using FpPtr = std::shared_ptr<Fp>;
  class Rf;
  using RfPtr = std::shared_ptr<Rf>;
  class Rfz;
  using RfzPtr = std::shared_ptr<Rfz>;
  class Sfz;
  using SfzPtr = std::shared_ptr<Sfz>;
  class Sffz;
  using SffzPtr = std::shared_ptr<Sffz>;
  class Fz;
  using FzPtr = std::shared_ptr<Fz>;
  class OtherDynamics;
  using OtherDynamicsPtr = std::shared_ptr<OtherDynamics>;

  class Dynamics: public Element, public PrintStyleAlign, public Placement, public TextDecoration, public Enclosure
  {
  public:
    Dynamics();
    virtual const char* tagname() const { return "dynamics"; }
    const DynamicSet& getDynamicSet() const;
    void removeDynamic(const DynamicPtr& value);
    void addDynamic(const DynamicPtr& value);
    void clearDynamicSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DynamicSet _dynamicSet;
  };
}
#endif //DYNAMICS_H
