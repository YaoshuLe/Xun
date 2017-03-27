#ifndef TIME_SIGNATURE_H
#define TIME_SIGNATURE_H
#include "Element.h"

namespace mxml
{
  class Beats;
  using BeatsPtr = std::shared_ptr<Beats>;
  class BeatType;
  using BeatTypePtr = std::shared_ptr<BeatType>;

  class TimeSignature: public Element
  {
  public:
    TimeSignature();
    virtual const char* tagname() const { return "time-signature"; }
    BeatsPtr getBeats() const;
    void setBeats(const BeatsPtr& value);
    BeatTypePtr getBeatType() const;
    void setBeatType(const BeatTypePtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    BeatsPtr _beatsPtr;
    BeatTypePtr _beatTypePtr;
  };
}
#endif //TIME_SIGNATURE_H
