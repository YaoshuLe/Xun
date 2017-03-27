#ifndef ELEMENT_POSITION_H
#define ELEMENT_POSITION_H
#include "AttrGroup.h"

namespace mxml
{
  class ElementPosition: public AttrGroup
  {
  public:
    ElementPosition();
    bool hasElement() const;
    void hasElement(bool value);
    std::string element() const;
    void element(std::string value);
    bool hasPosition() const;
    void hasPosition(bool value);
    int position() const;
    void position(int value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasElement {false};
    std::string _element;
    bool _hasPosition {false};
    int _position;
  };
}
#endif //ELEMENT_POSITION_H
