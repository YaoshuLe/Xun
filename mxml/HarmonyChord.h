#ifndef HARMONY_CHORD_H
#define HARMONY_CHORD_H
#include "Element.h"

namespace mxml
{
  class Root;
  using RootPtr = std::shared_ptr<Root>;
  class Function;
  using FunctionPtr = std::shared_ptr<Function>;
  class Kind;
  using KindPtr = std::shared_ptr<Kind>;
  class Inversion;
  using InversionPtr = std::shared_ptr<Inversion>;
  class Bass;
  using BassPtr = std::shared_ptr<Bass>;
  class Degree;
  using DegreePtr = std::shared_ptr<Degree>;
  using DegreeSet = std::vector<DegreePtr>;

  class HarmonyChord: public Element
  {
  public:
    HarmonyChord();
    virtual const char* tagname() const { return "harmony-chord"; }
    RootPtr getRoot() const;
    void setRoot(const RootPtr& value);
    FunctionPtr getFunction() const;
    void setFunction(const FunctionPtr& value);
    KindPtr getKind() const;
    void setKind(const KindPtr& value);
    InversionPtr getInversion() const;
    void setInversion(const InversionPtr& value);
    BassPtr getBass() const;
    void setBass(const BassPtr& value);
    const DegreeSet& getDegreeSet() const;
    void removeDegree(const DegreePtr& value);
    void addDegree(const DegreePtr& value);
    void clearDegreeSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    RootPtr _rootPtr;
    FunctionPtr _functionPtr;
    KindPtr _kindPtr;
    InversionPtr _inversionPtr;
    BassPtr _bassPtr;
    DegreeSet _degreeSet;
  };
}
#endif //HARMONY_CHORD_H
