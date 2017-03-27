#ifndef CREATOR_H
#define CREATOR_H
#include "TypedText.h"

namespace mxml
{
  class Creator: public TypedText
  {
  public:
    virtual const char* tagname() const { return "creator"; }
  };
}
#endif //CREATOR_H
