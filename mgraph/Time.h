#ifndef TIME_SYMBOL_H
#define TIME_SYMBOL_H
#include "Symbol.h"

namespace mgraph
{  
  class Time: public Symbol
  {
  public:
    void expand(MSvgRenderer *renderer);
  };
}
#endif //TIME_SYMBOL_H
