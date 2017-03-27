#ifndef TEXT_H
#define TEXT_H
#include "TextElementData.h"

namespace mxml
{
  class Text: public TextElementData
  {
  public:
    virtual const char* tagname() const { return "text"; }
  };
}
#endif //TEXT_H
