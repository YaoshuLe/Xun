#ifndef INVERTED_TURN_H
#define INVERTED_TURN_H
#include "HorizontalTurn.h"

namespace mxml
{
  class InvertedTurn: public HorizontalTurn
  {
  public:
    virtual const char* tagname() const { return "inverted-turn"; }
  };
}
#endif //INVERTED_TURN_H
