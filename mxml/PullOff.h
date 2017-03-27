#ifndef PULL_OFF_H
#define PULL_OFF_H
#include "HammerOnPullOff.h"

namespace mxml
{
  class PullOff: public HammerOnPullOff
  {
  public:
    virtual const char* tagname() const { return "pull-off"; }
  };
}
#endif //PULL_OFF_H
