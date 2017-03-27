#ifndef SYLLABIC_H
#define SYLLABIC_H
#include "Element.h"

namespace mxml
{
  class Syllabic: public Value<SyllabicEnum>
  {
  public:
    virtual const char* tagname() const { return "syllabic"; }
  };
}
#endif //SYLLABIC_H
