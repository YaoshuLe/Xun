#ifndef TOUCHING_PITCH_H
#define TOUCHING_PITCH_H
#include "Element.h"

namespace mxml
{
  class TouchingPitch: public Empty
  {
  public:
    virtual const char* tagname() const { return "touching-pitch"; }
  };
}
#endif //TOUCHING_PITCH_H
