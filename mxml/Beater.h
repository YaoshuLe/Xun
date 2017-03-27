#ifndef BEATER_H
#define BEATER_H
#include "Element.h"

namespace mxml
{
  class Beater: public Value<BeaterValueEnum>
  {
  public:
    Beater();
    virtual const char* tagname() const { return "beater"; }
    bool hasTip() const;
    void hasTip(bool value);
    TipDirectionEnum tip() const;
    void tip(TipDirectionEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasTip {false};
    TipDirectionEnum _tip;
  };
}
#endif //BEATER_H
