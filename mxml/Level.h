#ifndef LEVEL_H
#define LEVEL_H
#include "Element.h"
#include "LevelDisplay.h"

namespace mxml
{
  class Level: public Value<std::string>, public LevelDisplay
  {
  public:
    Level();
    virtual const char* tagname() const { return "level"; }
    bool hasReference() const;
    void hasReference(bool value);
    YesNoEnum reference() const;
    void reference(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasReference {false};
    YesNoEnum _reference;
  };
}
#endif //LEVEL_H
