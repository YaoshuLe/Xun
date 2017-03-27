#ifndef PER_MINUTE_H
#define PER_MINUTE_H
#include "Element.h"
#include "Font.h"

namespace mxml
{
  class PerMinute: public Value<std::string>, public Font
  {
  public:
    PerMinute();
    virtual const char* tagname() const { return "per-minute"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //PER_MINUTE_H
