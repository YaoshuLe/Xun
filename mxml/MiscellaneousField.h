#ifndef MISCELLANEOUS_FIELD_H
#define MISCELLANEOUS_FIELD_H
#include "Element.h"

namespace mxml
{
  class MiscellaneousField: public Value<std::string>
  {
  public:
    MiscellaneousField();
    virtual const char* tagname() const { return "miscellaneous-field"; }
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
#endif //MISCELLANEOUS_FIELD_H
