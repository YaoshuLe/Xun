#ifndef VALIGN_IMAGE_H
#define VALIGN_IMAGE_H
#include "AttrGroup.h"

namespace mxml
{
  class ValignImage: public AttrGroup
  {
  public:
    ValignImage();
    bool hasValign() const;
    void hasValign(bool value);
    ValignImageEnum valign() const;
    void valign(ValignImageEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasValign {false};
    ValignImageEnum _valign;
  };
}
#endif //VALIGN_IMAGE_H
