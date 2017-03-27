#ifndef STRING_MUTE_H
#define STRING_MUTE_H
#include "Element.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class StringMute: public Empty, public PrintStyleAlign
  {
  public:
    StringMute();
    virtual const char* tagname() const { return "string-mute"; }
    bool hasType() const;
    void hasType(bool value);
    OnOffEnum type() const;
    void type(OnOffEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    OnOffEnum _type;
  };
}
#endif //STRING_MUTE_H
