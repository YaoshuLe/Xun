#ifndef IMAGE_H
#define IMAGE_H
#include "Element.h"
#include "ImageAttributes.h"

namespace mxml
{
  class Image: public Empty, public ImageAttributes
  {
  public:
    Image();
    virtual const char* tagname() const { return "image"; }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
  };
}
#endif //IMAGE_H
