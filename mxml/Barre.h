#ifndef BARRE_H
#define BARRE_H
#include "Element.h"
#include "Color.h"

namespace mxml
{
  class Barre: public Empty, public Color
  {
  public:
    Barre();
    virtual const char* tagname() const { return "barre"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopEnum _type;
  };
}
#endif //BARRE_H
