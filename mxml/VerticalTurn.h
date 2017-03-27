#ifndef VERTICAL_TURN_H
#define VERTICAL_TURN_H
#include "EmptyTrillSound.h"

namespace mxml
{
  class VerticalTurn: public EmptyTrillSound
  {
  public:
    virtual const char* tagname() const { return "vertical-turn"; }
  };
}
#endif //VERTICAL_TURN_H
