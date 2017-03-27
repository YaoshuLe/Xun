#ifndef TEXT_DIRECTION_H
#define TEXT_DIRECTION_H
#include "AttrGroup.h"

namespace mxml
{
  class TextDirection: public AttrGroup
  {
  public:
    TextDirection();
    bool hasDir() const;
    void hasDir(bool value);
    TextDirectionEnum dir() const;
    void dir(TextDirectionEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasDir {false};
    TextDirectionEnum _dir;
  };
}
#endif //TEXT_DIRECTION_H
