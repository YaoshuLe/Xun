#ifndef ENCODING_DATE_H
#define ENCODING_DATE_H
#include "Element.h"

namespace mxml
{
  class EncodingDate: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "encoding-date"; }
  };
}
#endif //ENCODING_DATE_H
