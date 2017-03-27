#ifndef IMAGE_ATTRIBUTES_H
#define IMAGE_ATTRIBUTES_H
#include "Position.h"
#include "Halign.h"
#include "ValignImage.h"

namespace mxml
{
  class ImageAttributes: public Position, public Halign, public ValignImage
  {
  public:
    ImageAttributes();
    bool hasSource() const;
    void hasSource(bool value);
    std::string source() const;
    void source(std::string value);
    bool hasType() const;
    void hasType(bool value);
    std::string type() const;
    void type(std::string value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasSource {false};
    std::string _source;
    bool _hasType {false};
    std::string _type;
  };
}
#endif //IMAGE_ATTRIBUTES_H
