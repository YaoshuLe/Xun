#ifndef LINK_ATTRIBUTES_H
#define LINK_ATTRIBUTES_H
#include "AttrGroup.h"

namespace mxml
{
  class LinkAttributes: public AttrGroup
  {
  public:
    LinkAttributes();
    bool hasHref() const;
    void hasHref(bool value);
    std::string href() const;
    void href(std::string value);
    bool hasType() const;
    void hasType(bool value);
    std::string type() const;
    void type(std::string value);
    bool hasRole() const;
    void hasRole(bool value);
    std::string role() const;
    void role(std::string value);
    bool hasTitle() const;
    void hasTitle(bool value);
    std::string title() const;
    void title(std::string value);
    bool hasShow() const;
    void hasShow(bool value);
    std::string show() const;
    void show(std::string value);
    bool hasActuate() const;
    void hasActuate(bool value);
    std::string actuate() const;
    void actuate(std::string value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasHref {false};
    std::string _href;
    bool _hasType {false};
    std::string _type;
    bool _hasRole {false};
    std::string _role;
    bool _hasTitle {false};
    std::string _title;
    bool _hasShow {false};
    std::string _show;
    bool _hasActuate {false};
    std::string _actuate;
  };
}
#endif //LINK_ATTRIBUTES_H
