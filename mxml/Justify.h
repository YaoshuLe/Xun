#ifndef JUSTIFY_H
#define JUSTIFY_H
#include "AttrGroup.h"

namespace mxml
{
  class Justify: public AttrGroup
  {
  public:
    Justify();
    bool hasJustify() const;
    void hasJustify(bool value);
    LeftCenterRightEnum justify() const;
    void justify(LeftCenterRightEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasJustify {false};
    LeftCenterRightEnum _justify;
  };
}
#endif //JUSTIFY_H
