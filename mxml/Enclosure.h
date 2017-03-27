#ifndef ENCLOSURE_H
#define ENCLOSURE_H
#include "AttrGroup.h"

namespace mxml
{
  class Enclosure: public AttrGroup
  {
  public:
    Enclosure();
    bool hasEnclosure() const;
    void hasEnclosure(bool value);
    EnclosureShapeEnum enclosure() const;
    void enclosure(EnclosureShapeEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasEnclosure {false};
    EnclosureShapeEnum _enclosure;
  };
}
#endif //ENCLOSURE_H
