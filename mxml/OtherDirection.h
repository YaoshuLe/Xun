#ifndef OTHER_DIRECTION_H
#define OTHER_DIRECTION_H
#include "Element.h"
#include "PrintObject.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class OtherDirection: public Value<std::string>, public PrintObject, public PrintStyleAlign
  {
  public:
    OtherDirection();
    virtual const char* tagname() const { return "other-direction"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //OTHER_DIRECTION_H
