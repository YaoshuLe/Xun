#ifndef PEDAL_TUNING_H
#define PEDAL_TUNING_H
#include "Element.h"

namespace mxml
{
  class PedalStep;
  using PedalStepPtr = std::shared_ptr<PedalStep>;
  class PedalAlter;
  using PedalAlterPtr = std::shared_ptr<PedalAlter>;

  class PedalTuning: public Element
  {
  public:
    PedalTuning();
    virtual const char* tagname() const { return "pedal-tuning"; }
    PedalStepPtr getPedalStep() const;
    void setPedalStep(const PedalStepPtr& value);
    PedalAlterPtr getPedalAlter() const;
    void setPedalAlter(const PedalAlterPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    PedalStepPtr _pedalStepPtr;
    PedalAlterPtr _pedalAlterPtr;
  };
}
#endif //PEDAL_TUNING_H
