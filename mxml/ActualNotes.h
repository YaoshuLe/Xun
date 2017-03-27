#ifndef ACTUAL_NOTES_H
#define ACTUAL_NOTES_H
#include "Element.h"

namespace mxml
{
  class ActualNotes: public Value<int>
  {
  public:
    virtual const char* tagname() const { return "actual-notes"; }
  };
}
#endif //ACTUAL_NOTES_H
