#ifndef HEEL_H
#define HEEL_H
#include "HeelToe.h"

namespace mxml
{
  class Heel: public HeelToe
  {
  public:
    virtual const char* tagname() const { return "heel"; }
  };
}
#endif //HEEL_H
