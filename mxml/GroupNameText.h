#ifndef GROUP_NAME_TEXT_H
#define GROUP_NAME_TEXT_H
#include "PrintStyle.h"
#include "Justify.h"

namespace mxml
{
  class GroupNameText: public PrintStyle, public Justify
  {
  public:
    GroupNameText();
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //GROUP_NAME_TEXT_H
