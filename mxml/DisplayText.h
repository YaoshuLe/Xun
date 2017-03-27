#ifndef DISPLAY_TEXT_H
#define DISPLAY_TEXT_H
#include "FormattedText.h"

namespace mxml
{
  class DisplayText: public FormattedText
  {
  public:
    virtual const char* tagname() const { return "display-text"; }
  };
}
#endif //DISPLAY_TEXT_H
