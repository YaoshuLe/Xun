#ifndef WORD_FONT_H
#define WORD_FONT_H
#include "EmptyFont.h"

namespace mxml
{
  class WordFont: public EmptyFont
  {
  public:
    virtual const char* tagname() const { return "word-font"; }
  };
}
#endif //WORD_FONT_H
