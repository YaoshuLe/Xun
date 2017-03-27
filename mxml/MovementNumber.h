#ifndef MOVEMENT_NUMBER_H
#define MOVEMENT_NUMBER_H
#include "Element.h"

namespace mxml
{
  class MovementNumber: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "movement-number"; }
  };
}
#endif //MOVEMENT_NUMBER_H
