#ifndef DOWN_BOW_H
#define DOWN_BOW_H
#include "EmptyPlacement.h"

namespace mxml
{
  class DownBow: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "down-bow"; }
  };
}
#endif //DOWN_BOW_H
