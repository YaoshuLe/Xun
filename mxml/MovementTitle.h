#ifndef MOVEMENT_TITLE_H
#define MOVEMENT_TITLE_H
#include "Element.h"

namespace mxml
{
  class MovementTitle: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "movement-title"; }
  };
}
#endif //MOVEMENT_TITLE_H
