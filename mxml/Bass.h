#ifndef BASS_H
#define BASS_H
#include "Element.h"

namespace mxml
{
  class BassStep;
  using BassStepPtr = std::shared_ptr<BassStep>;
  class BassAlter;
  using BassAlterPtr = std::shared_ptr<BassAlter>;

  class Bass: public Element
  {
  public:
    Bass();
    virtual const char* tagname() const { return "bass"; }
    BassStepPtr getBassStep() const;
    void setBassStep(const BassStepPtr& value);
    BassAlterPtr getBassAlter() const;
    void setBassAlter(const BassAlterPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    BassStepPtr _bassStepPtr;
    BassAlterPtr _bassAlterPtr;
  };
}
#endif //BASS_H
