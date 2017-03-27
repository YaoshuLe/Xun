#ifndef TRANSPOSE_H
#define TRANSPOSE_H
#include "Element.h"

namespace mxml
{
  class Diatonic;
  using DiatonicPtr = std::shared_ptr<Diatonic>;
  class Chromatic;
  using ChromaticPtr = std::shared_ptr<Chromatic>;
  class OctaveChange;
  using OctaveChangePtr = std::shared_ptr<OctaveChange>;
  class Double;
  using DoublePtr = std::shared_ptr<Double>;

  class Transpose: public Element
  {
  public:
    Transpose();
    virtual const char* tagname() const { return "transpose"; }
    DiatonicPtr getDiatonic() const;
    void setDiatonic(const DiatonicPtr& value);
    ChromaticPtr getChromatic() const;
    void setChromatic(const ChromaticPtr& value);
    OctaveChangePtr getOctaveChange() const;
    void setOctaveChange(const OctaveChangePtr& value);
    DoublePtr getDouble() const;
    void setDouble(const DoublePtr& value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DiatonicPtr _diatonicPtr;
    ChromaticPtr _chromaticPtr;
    OctaveChangePtr _octaveChangePtr;
    DoublePtr _doublePtr;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //TRANSPOSE_H
