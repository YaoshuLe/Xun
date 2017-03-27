#ifndef FOOTNOTE_H
#define FOOTNOTE_H
#include "FormattedText.h"

namespace mxml
{
  class Footnote: public FormattedText
  {
  public:
    virtual const char* tagname() const { return "footnote"; }
  };
}
#endif //FOOTNOTE_H
