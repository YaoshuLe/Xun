#ifndef Y_POSITION_H
#define Y_POSITION_H
#include "AttrGroup.h"

namespace mxml
{
  class YPosition: public AttrGroup
  {
  public:
    YPosition();
    bool hasDefaultX() const;
    void hasDefaultX(bool value);
    float defaultX() const;
    void defaultX(float value);
    bool hasDefaultY() const;
    void hasDefaultY(bool value);
    float defaultY() const;
    void defaultY(float value);
    bool hasRelativeX() const;
    void hasRelativeX(bool value);
    float relativeX() const;
    void relativeX(float value);
    bool hasRelativeY() const;
    void hasRelativeY(bool value);
    float relativeY() const;
    void relativeY(float value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasDefaultX {false};
    float _defaultX;
    bool _hasDefaultY {false};
    float _defaultY;
    bool _hasRelativeX {false};
    float _relativeX;
    bool _hasRelativeY {false};
    float _relativeY;
  };
}
#endif //Y_POSITION_H
