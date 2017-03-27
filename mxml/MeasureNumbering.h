#ifndef MEASURE_NUMBERING_H
#define MEASURE_NUMBERING_H
#include "Element.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class MeasureNumbering: public Value<MeasureNumberingValueEnum>, public PrintStyleAlign
  {
  public:
    MeasureNumbering();
    virtual const char* tagname() const { return "measure-numbering"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //MEASURE_NUMBERING_H
