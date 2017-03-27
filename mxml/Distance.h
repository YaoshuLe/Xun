#ifndef DISTANCE_H
#define DISTANCE_H
#include "Element.h"

namespace mxml
{
  class Distance: public Value<float>
  {
  public:
    Distance();
    virtual const char* tagname() const { return "distance"; }
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
#endif //DISTANCE_H
