#ifndef ACCENT_H
#define ACCENT_H
#include "EmptyPlacement.h"

namespace mxml
{
  class Accent: public EmptyPlacement
  {
  public:
    virtual const char* tagname() const { return "accent"; }
  };
}
#endif //ACCENT_H
