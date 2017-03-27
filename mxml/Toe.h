#ifndef TOE_H
#define TOE_H
#include "HeelToe.h"

namespace mxml
{
  class Toe: public HeelToe
  {
  public:
    virtual const char* tagname() const { return "toe"; }
  };
}
#endif //TOE_H
