#ifndef SLASH_TYPE_H
#define SLASH_TYPE_H
#include "Element.h"

namespace mxml
{
  class SlashType: public Value<NoteTypeValueEnum>
  {
  public:
    virtual const char* tagname() const { return "slash-type"; }
  };
}
#endif //SLASH_TYPE_H
