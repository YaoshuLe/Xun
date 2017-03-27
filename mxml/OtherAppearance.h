#ifndef OTHER_APPEARANCE_H
#define OTHER_APPEARANCE_H
#include "Element.h"

namespace mxml
{
  class OtherAppearance: public Value<std::string>
  {
  public:
    OtherAppearance();
    virtual const char* tagname() const { return "other-appearance"; }
    bool hasType() const;
    void hasType(bool value);
    std::string type() const;
    void type(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    std::string _type;
  };
}
#endif //OTHER_APPEARANCE_H
