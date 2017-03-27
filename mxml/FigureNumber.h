#ifndef FIGURE_NUMBER_H
#define FIGURE_NUMBER_H
#include "StyleText.h"

namespace mxml
{
  class FigureNumber: public StyleText
  {
  public:
    virtual const char* tagname() const { return "figure-number"; }
  };
}
#endif //FIGURE_NUMBER_H
