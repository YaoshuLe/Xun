#ifndef PITCH_H
#define PITCH_H
#include "Element.h"

namespace mxml
{
  class Step;
  using StepPtr = std::shared_ptr<Step>;
  class Alter;
  using AlterPtr = std::shared_ptr<Alter>;
  class Octave;
  using OctavePtr = std::shared_ptr<Octave>;

  class Pitch: public Element
  {
  public:
    Pitch();
    virtual const char* tagname() const { return "pitch"; }
    StepPtr getStep() const;
    void setStep(const StepPtr& value);
    AlterPtr getAlter() const;
    void setAlter(const AlterPtr& value);
    OctavePtr getOctave() const;
    void setOctave(const OctavePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    StepPtr _stepPtr;
    AlterPtr _alterPtr;
    OctavePtr _octavePtr;
  };
}
#endif //PITCH_H
