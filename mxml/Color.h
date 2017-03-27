#ifndef COLOR_H
#define COLOR_H
#include "AttrGroup.h"

namespace mxml
{
  class Color: public AttrGroup
  {
  public:
    Color();
    bool hasColor() const;
    void hasColor(bool value);
    std::string color() const;
    void color(std::string value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasColor {false};
    std::string _color;
  };
}
#endif //COLOR_H
