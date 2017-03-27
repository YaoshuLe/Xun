#ifndef FRAME_NOTE_H
#define FRAME_NOTE_H
#include "Element.h"

namespace mxml
{
  class String;
  using StringPtr = std::shared_ptr<String>;
  class Fret;
  using FretPtr = std::shared_ptr<Fret>;
  class Fingering;
  using FingeringPtr = std::shared_ptr<Fingering>;
  class Barre;
  using BarrePtr = std::shared_ptr<Barre>;

  class FrameNote: public Element
  {
  public:
    FrameNote();
    virtual const char* tagname() const { return "frame-note"; }
    StringPtr getString() const;
    void setString(const StringPtr& value);
    FretPtr getFret() const;
    void setFret(const FretPtr& value);
    FingeringPtr getFingering() const;
    void setFingering(const FingeringPtr& value);
    BarrePtr getBarre() const;
    void setBarre(const BarrePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    StringPtr _stringPtr;
    FretPtr _fretPtr;
    FingeringPtr _fingeringPtr;
    BarrePtr _barrePtr;
  };
}
#endif //FRAME_NOTE_H
