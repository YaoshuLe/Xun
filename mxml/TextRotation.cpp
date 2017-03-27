#include "TextRotation.h"
#include <cstring>

namespace mxml
{
  TextRotation::TextRotation() {}
  bool TextRotation::hasRotation() const { return _hasRotation; }
  void TextRotation::hasRotation(bool value) { _hasRotation = value; }
  float TextRotation::rotation() const { return _rotation; }
  void TextRotation::rotation(float value) { _rotation = value; }

  void TextRotation::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasRotation) {
      char str[15]={0};
      snprintf(str, sizeof(str), "%.3f", _rotation);
      while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';
      self.append_attribute("rotation").set_value(str);
    }
  }
  void TextRotation::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("rotation")) {
      _rotation = attr.as_float();
      _hasRotation = true;
    }
  }
}
