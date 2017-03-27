#ifndef PART_ATTRIBUTES_H
#define PART_ATTRIBUTES_H
#include "AttrGroup.h"

namespace mxml
{
  class PartAttributes: public AttrGroup
  {
  public:
    PartAttributes();
    bool hasId() const;
    void hasId(bool value);
    std::string id() const;
    void id(std::string value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasId {false};
    std::string _id;
  };
}
#endif //PART_ATTRIBUTES_H
