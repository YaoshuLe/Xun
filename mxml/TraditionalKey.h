#ifndef TRADITIONAL_KEY_H
#define TRADITIONAL_KEY_H
#include "Element.h"

namespace mxml
{
  class Cancel;
  using CancelPtr = std::shared_ptr<Cancel>;
  class Fifths;
  using FifthsPtr = std::shared_ptr<Fifths>;
  class Mode;
  using ModePtr = std::shared_ptr<Mode>;

  class TraditionalKey: public Element
  {
  public:
    TraditionalKey();
    virtual const char* tagname() const { return "traditional-key"; }
    CancelPtr getCancel() const;
    void setCancel(const CancelPtr& value);
    FifthsPtr getFifths() const;
    void setFifths(const FifthsPtr& value);
    ModePtr getMode() const;
    void setMode(const ModePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    CancelPtr _cancelPtr;
    FifthsPtr _fifthsPtr;
    ModePtr _modePtr;
  };
}
#endif //TRADITIONAL_KEY_H
