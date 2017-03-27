#ifndef TUPLET_NORMAL_H
#define TUPLET_NORMAL_H
#include "TupletPortion.h"

namespace mxml
{
  class TupletNormal: public TupletPortion
  {
  public:
    virtual const char* tagname() const { return "tuplet-normal"; }
  };
}
#endif //TUPLET_NORMAL_H
