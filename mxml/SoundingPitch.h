#ifndef SOUNDING_PITCH_H
#define SOUNDING_PITCH_H
#include "Element.h"

namespace mxml
{
  class SoundingPitch: public Empty
  {
  public:
    virtual const char* tagname() const { return "sounding-pitch"; }
  };
}
#endif //SOUNDING_PITCH_H
