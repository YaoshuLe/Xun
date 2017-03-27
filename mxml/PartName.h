#ifndef PART_NAME_H
#define PART_NAME_H
#include "Element.h"
#include "PartNameText.h"

namespace mxml
{
  class PartName: public Value<std::string>, public PartNameText
  {
  public:
    PartName();
    virtual const char* tagname() const { return "part-name"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //PART_NAME_H
