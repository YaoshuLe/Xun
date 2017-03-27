#ifndef RELEASE_H
#define RELEASE_H
#include "Element.h"

namespace mxml
{
  class Release: public Empty
  {
  public:
    virtual const char* tagname() const { return "release"; }
  };
}
#endif //RELEASE_H
