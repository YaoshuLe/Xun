#ifndef GROUP_H
#define GROUP_H
#include "Element.h"

namespace mxml
{
  class Group: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "group"; }
  };
}
#endif //GROUP_H
