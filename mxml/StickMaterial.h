#ifndef STICK_MATERIAL_H
#define STICK_MATERIAL_H
#include "Element.h"

namespace mxml
{
  class StickMaterial: public Value<StickMaterialEnum>
  {
  public:
    virtual const char* tagname() const { return "stick-material"; }
  };
}
#endif //STICK_MATERIAL_H
