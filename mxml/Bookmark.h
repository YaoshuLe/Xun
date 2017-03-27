#ifndef BOOKMARK_H
#define BOOKMARK_H
#include "Element.h"
#include "ElementPosition.h"

namespace mxml
{
  class Bookmark: public Empty, public ElementPosition
  {
  public:
    Bookmark();
    virtual const char* tagname() const { return "bookmark"; }
    bool hasId() const;
    void hasId(bool value);
    std::string id() const;
    void id(std::string value);
    bool hasName() const;
    void hasName(bool value);
    std::string name() const;
    void name(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasId {false};
    std::string _id;
    bool _hasName {false};
    std::string _name;
  };
}
#endif //BOOKMARK_H
