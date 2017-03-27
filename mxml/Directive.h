#ifndef DIRECTIVE_H
#define DIRECTIVE_H
#include "AttrGroup.h"

namespace mxml
{
  class Directive: public AttrGroup
  {
  public:
    Directive();
    bool hasDirective() const;
    void hasDirective(bool value);
    YesNoEnum directive() const;
    void directive(YesNoEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasDirective {false};
    YesNoEnum _directive;
  };
}
#endif //DIRECTIVE_H
