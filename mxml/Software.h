#ifndef SOFTWARE_H
#define SOFTWARE_H
#include "Element.h"

namespace mxml
{
  class Software: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "software"; }
  };
}
#endif //SOFTWARE_H
