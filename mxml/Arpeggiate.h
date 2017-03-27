#ifndef ARPEGGIATE_H
#define ARPEGGIATE_H
#include "Element.h"
#include "Position.h"
#include "Placement.h"
#include "Color.h"

namespace mxml
{
  class Arpeggiate: public Empty, public Position, public Placement, public Color
  {
  public:
    Arpeggiate();
    virtual const char* tagname() const { return "arpeggiate"; }
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasDirection() const;
    void hasDirection(bool value);
    UpDownEnum direction() const;
    void direction(UpDownEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasNumber {false};
    int _number;
    bool _hasDirection {false};
    UpDownEnum _direction;
  };
}
#endif //ARPEGGIATE_H
