#ifndef RELATION_H
#define RELATION_H
#include "TypedText.h"

namespace mxml
{
  class Relation: public TypedText
  {
  public:
    virtual const char* tagname() const { return "relation"; }
  };
}
#endif //RELATION_H
