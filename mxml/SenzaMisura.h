#ifndef SENZA_MISURA_H
#define SENZA_MISURA_H
#include "Element.h"

namespace mxml
{
  class SenzaMisura: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "senza-misura"; }
  };
}
#endif //SENZA_MISURA_H
