#ifndef BASE_PITCH_H
#define BASE_PITCH_H
#include "Element.h"

namespace mxml
{
  class BasePitch: public Empty
  {
  public:
    virtual const char* tagname() const { return "base-pitch"; }
  };
}
#endif //BASE_PITCH_H
