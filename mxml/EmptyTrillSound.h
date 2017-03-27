#ifndef EMPTY_TRILL_SOUND_H
#define EMPTY_TRILL_SOUND_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"
#include "TrillSound.h"

namespace mxml
{
  class EmptyTrillSound: public Empty, public PrintStyle, public Placement, public TrillSound
  {
  public:
    EmptyTrillSound();
    virtual const char* tagname() const { return "empty-trill-sound"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //EMPTY_TRILL_SOUND_H
