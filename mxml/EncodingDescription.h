#ifndef ENCODING_DESCRIPTION_H
#define ENCODING_DESCRIPTION_H
#include "Element.h"

namespace mxml
{
  class EncodingDescription: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "encoding-description"; }
  };
}
#endif //ENCODING_DESCRIPTION_H
