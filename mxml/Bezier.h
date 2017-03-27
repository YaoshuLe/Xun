#ifndef BEZIER_H
#define BEZIER_H
#include "AttrGroup.h"

namespace mxml
{
  class Bezier: public AttrGroup
  {
  public:
    Bezier();
    bool hasBezierOffset() const;
    void hasBezierOffset(bool value);
    float bezierOffset() const;
    void bezierOffset(float value);
    bool hasBezierOffset2() const;
    void hasBezierOffset2(bool value);
    float bezierOffset2() const;
    void bezierOffset2(float value);
    bool hasBezierX() const;
    void hasBezierX(bool value);
    float bezierX() const;
    void bezierX(float value);
    bool hasBezierY() const;
    void hasBezierY(bool value);
    float bezierY() const;
    void bezierY(float value);
    bool hasBezierX2() const;
    void hasBezierX2(bool value);
    float bezierX2() const;
    void bezierX2(float value);
    bool hasBezierY2() const;
    void hasBezierY2(bool value);
    float bezierY2() const;
    void bezierY2(float value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasBezierOffset {false};
    float _bezierOffset;
    bool _hasBezierOffset2 {false};
    float _bezierOffset2;
    bool _hasBezierX {false};
    float _bezierX;
    bool _hasBezierY {false};
    float _bezierY;
    bool _hasBezierX2 {false};
    float _bezierX2;
    bool _hasBezierY2 {false};
    float _bezierY2;
  };
}
#endif //BEZIER_H
