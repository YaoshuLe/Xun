#ifndef SOURCE_H
#define SOURCE_H
#include "Element.h"

namespace mxml
{
  class Source: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "source"; }
  };
}
#endif //SOURCE_H
