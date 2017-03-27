#ifndef DEGREE_ALTER_H
#define DEGREE_ALTER_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class DegreeAlter: public Value<float>, public PrintStyle
  {
  public:
    DegreeAlter();
    virtual const char* tagname() const { return "degree-alter"; }
    bool hasPlusMinus() const;
    void hasPlusMinus(bool value);
    YesNoEnum plusMinus() const;
    void plusMinus(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasPlusMinus {false};
    YesNoEnum _plusMinus;
  };
}
#endif //DEGREE_ALTER_H
