#ifndef TURN_H
#define TURN_H
#include "HorizontalTurn.h"

namespace mxml
{
  class Turn: public HorizontalTurn
  {
  public:
    virtual const char* tagname() const { return "turn"; }
  };
}
#endif //TURN_H
