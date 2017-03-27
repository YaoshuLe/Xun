#ifndef GROUP_BARLINE_H
#define GROUP_BARLINE_H
#include "Element.h"
#include "Color.h"

namespace mxml
{
  class GroupBarline: public Value<GroupBarlineValueEnum>, public Color
  {
  public:
    GroupBarline();
    virtual const char* tagname() const { return "group-barline"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //GROUP_BARLINE_H
