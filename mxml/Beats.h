#ifndef BEATS_H
#define BEATS_H
#include "Element.h"

namespace mxml
{
  class Beats: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "beats"; }
  };
}
#endif //BEATS_H
