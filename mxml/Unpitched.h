#ifndef UNPITCHED_H
#define UNPITCHED_H
#include "Element.h"

namespace mxml
{
  class DisplayStep;
  using DisplayStepPtr = std::shared_ptr<DisplayStep>;
  class DisplayOctave;
  using DisplayOctavePtr = std::shared_ptr<DisplayOctave>;

  class Unpitched: public Element
  {
  public:
    Unpitched();
    virtual const char* tagname() const { return "unpitched"; }
    DisplayStepPtr getDisplayStep() const;
    void setDisplayStep(const DisplayStepPtr& value);
    DisplayOctavePtr getDisplayOctave() const;
    void setDisplayOctave(const DisplayOctavePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DisplayStepPtr _displayStepPtr;
    DisplayOctavePtr _displayOctavePtr;
  };
}
#endif //UNPITCHED_H
