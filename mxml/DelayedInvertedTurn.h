#ifndef DELAYED_INVERTED_TURN_H
#define DELAYED_INVERTED_TURN_H
#include "HorizontalTurn.h"

namespace mxml
{
  class DelayedInvertedTurn: public HorizontalTurn
  {
  public:
    virtual const char* tagname() const { return "delayed-inverted-turn"; }
  };
}
#endif //DELAYED_INVERTED_TURN_H
