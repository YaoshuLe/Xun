#ifndef REST_H
#define REST_H
#include "Element.h"

namespace mxml
{
  class DisplayStep;
  using DisplayStepPtr = std::shared_ptr<DisplayStep>;
  class DisplayOctave;
  using DisplayOctavePtr = std::shared_ptr<DisplayOctave>;

  class Rest: public Element
  {
  public:
    Rest();
    virtual const char* tagname() const { return "rest"; }
    DisplayStepPtr getDisplayStep() const;
    void setDisplayStep(const DisplayStepPtr& value);
    DisplayOctavePtr getDisplayOctave() const;
    void setDisplayOctave(const DisplayOctavePtr& value);
    bool hasMeasure() const;
    void hasMeasure(bool value);
    YesNoEnum measure() const;
    void measure(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DisplayStepPtr _displayStepPtr;
    DisplayOctavePtr _displayOctavePtr;
    bool _hasMeasure {false};
    YesNoEnum _measure;
  };
}
#endif //REST_H
