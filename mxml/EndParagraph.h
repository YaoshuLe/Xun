#ifndef END_PARAGRAPH_H
#define END_PARAGRAPH_H
#include "Element.h"

namespace mxml
{
  class EndParagraph: public Empty
  {
  public:
    virtual const char* tagname() const { return "end-paragraph"; }
  };
}
#endif //END_PARAGRAPH_H
