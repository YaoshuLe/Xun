#ifndef FEATURE_H
#define FEATURE_H
#include "Element.h"

namespace mxml
{
  class Feature: public Value<std::string>
  {
  public:
    Feature();
    virtual const char* tagname() const { return "feature"; }
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
#endif //FEATURE_H
