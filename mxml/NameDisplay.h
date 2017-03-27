#ifndef NAME_DISPLAY_H
#define NAME_DISPLAY_H
#include "Element.h"
#include "PrintObject.h"

namespace mxml
{
  class DisplayText;
  using DisplayTextPtr = std::shared_ptr<DisplayText>;
  class AccidentalText;
  using AccidentalTextPtr = std::shared_ptr<AccidentalText>;

  class NameDisplay: public Element, public PrintObject
  {
  public:
    NameDisplay();
    virtual const char* tagname() const { return "name-display"; }
    DisplayTextPtr getDisplayText() const;
    void setDisplayText(const DisplayTextPtr& value);
    AccidentalTextPtr getAccidentalText() const;
    void setAccidentalText(const AccidentalTextPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DisplayTextPtr _displayTextPtr;
    AccidentalTextPtr _accidentalTextPtr;
  };
}
#endif //NAME_DISPLAY_H
