#ifndef TIME_RELATION_H
#define TIME_RELATION_H
#include "Element.h"

namespace mxml
{
  class TimeRelation: public Value<TimeRelationEnum>
  {
  public:
    virtual const char* tagname() const { return "time-relation"; }
  };
}
#endif //TIME_RELATION_H
