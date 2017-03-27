#ifndef SLASH_DOT_H
#define SLASH_DOT_H
#include "Element.h"

namespace mxml
{
  class SlashDot: public Empty
  {
  public:
    virtual const char* tagname() const { return "slash-dot"; }
  };
}
#endif //SLASH_DOT_H
