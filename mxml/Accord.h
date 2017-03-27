#ifndef ACCORD_H
#define ACCORD_H
#include "Element.h"

namespace mxml
{
  class TuningStep;
  using TuningStepPtr = std::shared_ptr<TuningStep>;
  class TuningAlter;
  using TuningAlterPtr = std::shared_ptr<TuningAlter>;
  class TuningOctave;
  using TuningOctavePtr = std::shared_ptr<TuningOctave>;

  class Accord: public Element
  {
  public:
    Accord();
    virtual const char* tagname() const { return "accord"; }
    TuningStepPtr getTuningStep() const;
    void setTuningStep(const TuningStepPtr& value);
    TuningAlterPtr getTuningAlter() const;
    void setTuningAlter(const TuningAlterPtr& value);
    TuningOctavePtr getTuningOctave() const;
    void setTuningOctave(const TuningOctavePtr& value);
    bool hasString() const;
    void hasString(bool value);
    int string() const;
    void string(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    TuningStepPtr _tuningStepPtr;
    TuningAlterPtr _tuningAlterPtr;
    TuningOctavePtr _tuningOctavePtr;
    bool _hasString {false};
    int _string;
  };
}
#endif //ACCORD_H
