#ifndef UP_BOW_H
#define UP_BOW_H
#include "EmptyPlacement.h"

namespace mxml
{
  class UpBow: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "up-bow"; }
  };
}
#endif //UP_BOW_H
