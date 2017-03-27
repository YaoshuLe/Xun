#ifndef WORK_NUMBER_H
#define WORK_NUMBER_H
#include "Element.h"

namespace mxml
{
  class WorkNumber: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "work-number"; }
  };
}
#endif //WORK_NUMBER_H
