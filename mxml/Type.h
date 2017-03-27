#ifndef TYPE_H
#define TYPE_H
#include "NoteType.h"

namespace mxml
{
  class Type: public NoteType
  {
  public:
    virtual const char* tagname() const { return "type"; }
  };
}
#endif //TYPE_H
