#ifndef IPA_H
#define IPA_H
#include "Element.h"

namespace mxml
{
  class Ipa: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "ipa"; }
  };
}
#endif //IPA_H
