#ifndef LINK_H
#define LINK_H
#include "Element.h"
#include "LinkAttributes.h"
#include "ElementPosition.h"
#include "Position.h"

namespace mxml
{
  class Link: public Empty, public LinkAttributes, public ElementPosition, public Position
  {
  public:
    Link();
    virtual const char* tagname() const { return "link"; }
    bool hasName() const;
    void hasName(bool value);
    std::string name() const;
    void name(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasName {false};
    std::string _name;
  };
}
#endif //LINK_H
