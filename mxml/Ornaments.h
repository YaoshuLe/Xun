#ifndef ORNAMENTS_H
#define ORNAMENTS_H
#include "Element.h"

namespace mxml
{
  class Ornament;
  using OrnamentPtr = std::shared_ptr<Ornament>;
  using OrnamentSet = std::vector<OrnamentPtr>;

  class Ornaments: public Element
  {
  public:
    Ornaments();
    virtual const char* tagname() const { return "ornaments"; }
    const OrnamentSet& getOrnamentSet() const;
    void removeOrnament(const OrnamentPtr& value);
    void addOrnament(const OrnamentPtr& value);
    void clearOrnamentSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    OrnamentSet _ornamentSet;
  };
}
#endif //ORNAMENTS_H
