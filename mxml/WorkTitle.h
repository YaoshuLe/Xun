#ifndef WORK_TITLE_H
#define WORK_TITLE_H
#include "Element.h"

namespace mxml
{
  class WorkTitle: public Value<std::string>
  {
  public:
    virtual const char* tagname() const { return "work-title"; }
  };
}
#endif //WORK_TITLE_H
