#ifndef SNAP_PIZZICATO_H
#define SNAP_PIZZICATO_H
#include "EmptyPlacement.h"

namespace mxml
{
  class SnapPizzicato: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "snap-pizzicato"; }
  };
}
#endif //SNAP_PIZZICATO_H
