#ifndef STAFF_TUNING_H
#define STAFF_TUNING_H
#include "Element.h"

namespace mxml
{
  class TuningStep;
  using TuningStepPtr = std::shared_ptr<TuningStep>;
  class TuningAlter;
  using TuningAlterPtr = std::shared_ptr<TuningAlter>;
  class TuningOctave;
  using TuningOctavePtr = std::shared_ptr<TuningOctave>;

  class StaffTuning: public Element
  {
  public:
    StaffTuning();
    virtual const char* tagname() const { return "staff-tuning"; }
    TuningStepPtr getTuningStep() const;
    void setTuningStep(const TuningStepPtr& value);
    TuningAlterPtr getTuningAlter() const;
    void setTuningAlter(const TuningAlterPtr& value);
    TuningOctavePtr getTuningOctave() const;
    void setTuningOctave(const TuningOctavePtr& value);
    bool hasLine() const;
    void hasLine(bool value);
    int line() const;
    void line(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    TuningStepPtr _tuningStepPtr;
    TuningAlterPtr _tuningAlterPtr;
    TuningOctavePtr _tuningOctavePtr;
    bool _hasLine {false};
    int _line;
  };
}
#endif //STAFF_TUNING_H
