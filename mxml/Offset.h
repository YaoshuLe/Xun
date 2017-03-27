#ifndef OFFSET_H
#define OFFSET_H
#include "Element.h"

namespace mxml
{
  class Offset: public Value<float>
  {
  public:
    Offset();
    virtual const char* tagname() const { return "offset"; }
    bool hasSound() const;
    void hasSound(bool value);
    YesNoEnum sound() const;
    void sound(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasSound {false};
    YesNoEnum _sound;
  };
}
#endif //OFFSET_H
