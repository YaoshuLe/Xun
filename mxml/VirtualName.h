#ifndef VIRTUAL_NAME_H
#define VIRTUAL_NAME_H
#include "Element.h"

namespace mxml
{
  class VirtualName: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "virtual-name"; }
  };
}
#endif //VIRTUAL_NAME_H
