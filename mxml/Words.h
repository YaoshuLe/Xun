#ifndef WORDS_H
#define WORDS_H
#include "FormattedText.h"

namespace mxml
{
  class Words: public FormattedText
  {
  public:
    virtual const char* tagname() const { return "words"; }
  };
}
#endif //WORDS_H
