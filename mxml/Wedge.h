#ifndef WEDGE_H
#define WEDGE_H
#include "Element.h"
#include "LineType.h"
#include "DashedFormatting.h"
#include "Position.h"
#include "Color.h"

namespace mxml
{
  class Wedge: public Empty, public LineType, public DashedFormatting, public Position, public Color
  {
  public:
    Wedge();
    virtual const char* tagname() const { return "wedge"; }
    bool hasType() const;
    void hasType(bool value);
    WedgeTypeEnum type() const;
    void type(WedgeTypeEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasSpread() const;
    void hasSpread(bool value);
    float spread() const;
    void spread(float value);
    bool hasNiente() const;
    void hasNiente(bool value);
    YesNoEnum niente() const;
    void niente(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    WedgeTypeEnum _type;
    bool _hasNumber {false};
    int _number;
    bool _hasSpread {false};
    float _spread;
    bool _hasNiente {false};
    YesNoEnum _niente;
  };
}
#endif //WEDGE_H
