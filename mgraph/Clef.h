#ifndef CLEF_SYMBOL_H
#define CLEF_SYMBOL_H
#include "Symbol.h"

namespace mgraph
{
  class Clef: public Symbol
  {
  public:
    void expand(MSvgRenderer *renderer);
  };
}
#endif //CLEF_SYMBOL_H
