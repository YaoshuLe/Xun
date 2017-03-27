#ifndef RIGHTS_H
#define RIGHTS_H
#include "TypedText.h"

namespace mxml
{
  class Rights: public TypedText
  {
  public:
    virtual const char* tagname() const { return "rights"; }
  };
}
#endif //RIGHTS_H
