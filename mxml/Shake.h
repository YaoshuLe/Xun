#ifndef SHAKE_H
#define SHAKE_H
#include "EmptyTrillSound.h"

namespace mxml
{
  class Shake: public EmptyTrillSound
  {
  public:
    virtual const char* tagname() const { return "shake"; }
  };
}
#endif //SHAKE_H
