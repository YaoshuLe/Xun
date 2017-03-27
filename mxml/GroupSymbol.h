#ifndef GROUP_SYMBOL_H
#define GROUP_SYMBOL_H
#include "Element.h"
#include "Position.h"
#include "Color.h"

namespace mxml
{
  class GroupSymbol: public Value<GroupSymbolValueEnum>, public Position, public Color
  {
  public:
    GroupSymbol();
    virtual const char* tagname() const { return "group-symbol"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //GROUP_SYMBOL_H
