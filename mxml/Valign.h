#ifndef VALIGN_H
#define VALIGN_H
#include "AttrGroup.h"

namespace mxml
{
  class Valign: public AttrGroup
  {
  public:
    Valign();
    bool hasValign() const;
    void hasValign(bool value);
    ValignEnum valign() const;
    void valign(ValignEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasValign {false};
    ValignEnum _valign;
  };
}
#endif //VALIGN_H
