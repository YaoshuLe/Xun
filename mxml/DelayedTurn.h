#ifndef DELAYED_TURN_H
#define DELAYED_TURN_H
#include "HorizontalTurn.h"

namespace mxml
{
  class DelayedTurn: public HorizontalTurn
  {
  public:
    virtual const char* tagname() const { return "delayed-turn"; }
  };
}
#endif //DELAYED_TURN_H
