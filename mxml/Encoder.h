#ifndef ENCODER_H
#define ENCODER_H
#include "TypedText.h"

namespace mxml
{
  class Encoder: public TypedText
  {
  public:
    virtual const char* tagname() const { return "encoder"; }
  };
}
#endif //ENCODER_H
