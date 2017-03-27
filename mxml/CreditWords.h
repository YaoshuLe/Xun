#ifndef CREDIT_WORDS_H
#define CREDIT_WORDS_H
#include "FormattedText.h"

namespace mxml
{
  class CreditWords: public FormattedText
  {
  public:
    virtual const char* tagname() const { return "credit-words"; }
  };
}
#endif //CREDIT_WORDS_H
