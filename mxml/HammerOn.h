#ifndef HAMMER_ON_H
#define HAMMER_ON_H
#include "HammerOnPullOff.h"

namespace mxml
{
  class HammerOn: public HammerOnPullOff
  {
  public:
    virtual const char* tagname() const { return "hammer-on"; }
  };
}
#endif //HAMMER_ON_H
