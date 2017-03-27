#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include "Element.h"

namespace mxml
{
  class Ensemble: public Value<PositiveIntegerOrEmptyEnum>
  {
  public:
    virtual const char* tagname() const { return "ensemble"; }
  };
}
#endif //ENSEMBLE_H
