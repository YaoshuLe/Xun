#ifndef ATTR_GROUP_H
#define ATTR_GROUP_H
#include "pugixml.hpp"
#include "Enums.h"

namespace mxml
{
  class AttrGroup
  {
  public:
    virtual ~AttrGroup() {};
  protected:  
    virtual void ostreamAttrs(pugi::xml_node& self) const = 0;
    virtual void istreamAttrs(const pugi::xml_node& self) = 0;
  };
}
#endif //ATTR_GROUP_H
