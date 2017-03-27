#ifndef NON_ARPEGGIATE_H
#define NON_ARPEGGIATE_H
#include "Element.h"
#include "Position.h"
#include "Placement.h"
#include "Color.h"

namespace mxml
{
  class NonArpeggiate: public Empty, public Position, public Placement, public Color
  {
  public:
    NonArpeggiate();
    virtual const char* tagname() const { return "non-arpeggiate"; }
    bool hasType() const;
    void hasType(bool value);
    TopBottomEnum type() const;
    void type(TopBottomEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    TopBottomEnum _type;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //NON_ARPEGGIATE_H
