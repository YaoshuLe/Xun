#ifndef REHEARSAL_H
#define REHEARSAL_H
#include "FormattedText.h"

namespace mxml
{
  class Rehearsal: public FormattedText
  {
  public:
    virtual const char* tagname() const { return "rehearsal"; }
  };
}
#endif //REHEARSAL_H
