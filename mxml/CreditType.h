#ifndef CREDIT_TYPE_H
#define CREDIT_TYPE_H
#include "Element.h"

namespace mxml
{
  class CreditType: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "credit-type"; }
  };
}
#endif //CREDIT_TYPE_H
