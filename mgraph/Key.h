#ifndef KEY_SYMBOL_H
#define KEY_SYMBOL_H
#include "Symbol.h"

namespace mgraph
{  
  class Key: public Symbol
  {
  public:
    void expand(MSvgRenderer *renderer);
  };
}
#endif //KEY_SYMBOL_H
