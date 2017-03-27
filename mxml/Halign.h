#ifndef HALIGN_H
#define HALIGN_H
#include "AttrGroup.h"

namespace mxml
{
  class Halign: public AttrGroup
  {
  public:
    Halign();
    bool hasHalign() const;
    void hasHalign(bool value);
    LeftCenterRightEnum halign() const;
    void halign(LeftCenterRightEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasHalign {false};
    LeftCenterRightEnum _halign;
  };
}
#endif //HALIGN_H
