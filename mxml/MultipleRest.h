#ifndef MULTIPLE_REST_H
#define MULTIPLE_REST_H
#include "Element.h"

namespace mxml
{
  class MultipleRest: public Value<PositiveIntegerOrEmptyEnum>
  {
  public:
    MultipleRest();
    virtual const char* tagname() const { return "multiple-rest"; }
    bool hasUseSymbols() const;
    void hasUseSymbols(bool value);
    YesNoEnum useSymbols() const;
    void useSymbols(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasUseSymbols {false};
    YesNoEnum _useSymbols;
  };
}
#endif //MULTIPLE_REST_H
