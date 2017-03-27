#ifndef INVERTED_MORDENT_H
#define INVERTED_MORDENT_H
#include "Mordent.h"

namespace mxml
{
  class InvertedMordent: public Mordent
  {
  public:
    virtual const char* tagname() const { return "inverted-mordent"; }
  };
}
#endif //INVERTED_MORDENT_H
