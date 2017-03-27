#ifndef OPUS_H
#define OPUS_H
#include "Element.h"
#include "LinkAttributes.h"

namespace mxml
{
  class Opus: public Empty, public LinkAttributes
  {
  public:
    Opus();
    virtual const char* tagname() const { return "opus"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //OPUS_H
