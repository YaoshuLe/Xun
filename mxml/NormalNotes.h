#ifndef NORMAL_NOTES_H
#define NORMAL_NOTES_H
#include "Element.h"

namespace mxml
{
  class NormalNotes: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "normal-notes"; }
  };
}
#endif //NORMAL_NOTES_H
