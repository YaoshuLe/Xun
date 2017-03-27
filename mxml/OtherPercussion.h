#ifndef OTHER_PERCUSSION_H
#define OTHER_PERCUSSION_H
#include "Element.h"

namespace mxml
{
  class OtherPercussion: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "other-percussion"; }
  };
}
#endif //OTHER_PERCUSSION_H
