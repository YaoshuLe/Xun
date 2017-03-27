#ifndef GROUP_NAME_H
#define GROUP_NAME_H
#include "Element.h"
#include "GroupNameText.h"

namespace mxml
{
  class GroupName: public Value<std::string>, public GroupNameText
  {
  public:
    GroupName();
    virtual const char* tagname() const { return "group-name"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //GROUP_NAME_H
