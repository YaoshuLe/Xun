#ifndef NORMAL_TYPE_H
#define NORMAL_TYPE_H
#include "Element.h"

namespace mxml
{
  class NormalType: public Value<NoteTypeValueEnum>
  {
  public:
    virtual const char* tagname() const { return "normal-type"; }
  };
}
#endif //NORMAL_TYPE_H
