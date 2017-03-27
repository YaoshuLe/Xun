#ifndef PART_NAME_TEXT_H
#define PART_NAME_TEXT_H
#include "PrintStyle.h"
#include "PrintObject.h"
#include "Justify.h"

namespace mxml
{
  class PartNameText: public PrintStyle, public PrintObject, public Justify
  {
  public:
    PartNameText();
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //PART_NAME_TEXT_H
