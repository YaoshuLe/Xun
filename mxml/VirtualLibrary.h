#ifndef VIRTUAL_LIBRARY_H
#define VIRTUAL_LIBRARY_H
#include "Element.h"

namespace mxml
{
  class VirtualLibrary: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "virtual-library"; }
  };
}
#endif //VIRTUAL_LIBRARY_H
