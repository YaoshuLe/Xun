#ifndef TREMOLO_H
#define TREMOLO_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class Tremolo: public Value<int>, public PrintStyle, public Placement
  {
  public:
    Tremolo();
    virtual const char* tagname() const { return "tremolo"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopSingleEnum type() const;
    void type(StartStopSingleEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopSingleEnum _type;
  };
}
#endif //TREMOLO_H
