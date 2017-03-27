#ifndef TEXT_ROTATION_H
#define TEXT_ROTATION_H
#include "AttrGroup.h"

namespace mxml
{
  class TextRotation: public AttrGroup
  {
  public:
    TextRotation();
    bool hasRotation() const;
    void hasRotation(bool value);
    float rotation() const;
    void rotation(float value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasRotation {false};
    float _rotation;
  };
}
#endif //TEXT_ROTATION_H
