#ifndef NOTEHEAD_TEXT_H
#define NOTEHEAD_TEXT_H
#include "Element.h"

namespace mxml
{
  class DisplayText;
  using DisplayTextPtr = std::shared_ptr<DisplayText>;
  class AccidentalText;
  using AccidentalTextPtr = std::shared_ptr<AccidentalText>;

  class NoteheadText: public Element
  {
  public:
    NoteheadText();
    virtual const char* tagname() const { return "notehead-text"; }
    DisplayTextPtr getDisplayText() const;
    void setDisplayText(const DisplayTextPtr& value);
    AccidentalTextPtr getAccidentalText() const;
    void setAccidentalText(const AccidentalTextPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DisplayTextPtr _displayTextPtr;
    AccidentalTextPtr _accidentalTextPtr;
  };
}
#endif //NOTEHEAD_TEXT_H
