#include "ImageAttributes.h"
#include <cstring>

namespace mxml
{
  ImageAttributes::ImageAttributes() {}
  bool ImageAttributes::hasSource() const { return _hasSource; }
  void ImageAttributes::hasSource(bool value) { _hasSource = value; }
  std::string ImageAttributes::source() const { return _source; }
  void ImageAttributes::source(std::string value) { _source = value; }
  bool ImageAttributes::hasType() const { return _hasType; }
  void ImageAttributes::hasType(bool value) { _hasType = value; }
  std::string ImageAttributes::type() const { return _type; }
  void ImageAttributes::type(std::string value) { _type = value; }

  void ImageAttributes::ostreamAttrs(pugi::xml_node& self) const
  {
    Position::ostreamAttrs(self);
    Halign::ostreamAttrs(self);
    ValignImage::ostreamAttrs(self);
    if(_hasSource) {
      self.append_attribute("source").set_value(_source.c_str());
    }
    if(_hasType) {
      self.append_attribute("type").set_value(_type.c_str());
    }
  }
  void ImageAttributes::istreamAttrs(const pugi::xml_node& self)
  {
    Position::istreamAttrs(self);
    Halign::istreamAttrs(self);
    ValignImage::istreamAttrs(self);
    if(auto attr = self.attribute("source")) {
      _source = attr.as_string();
      _hasSource = true;
    }
    if(auto attr = self.attribute("type")) {
      _type = attr.as_string();
      _hasType = true;
    }
  }
}
