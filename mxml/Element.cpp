#include "Element.h"
#include <cstring>
#include <sstream>

namespace mxml
{
  Element::~Element() {}
  void Element::ostream(pugi::xml_node& self) const
  {
    ostreamAttrs(self);
    ostreamContents(self);
  }
  void Element::istream(const pugi::xml_node& self)
  {
    istreamAttrs(self);
    istreamContents(self);
  }
  void Element::setParent(const ElementPtr& value)
  {
    _parentPtr = std::weak_ptr<Element>(value);
  }
  ElementPtr Element::getParent() const
  {
    return ElementPtr(_parentPtr.lock());
  }
  void Element::clone(const ElementPtr& value) const
  {
    std::stringstream ss;
    {
      pugi::xml_document outdoc;
      auto outchild = outdoc.append_child(tagname());
      this->ostream(outchild);
      outdoc.save(ss);
    }
    {
      pugi::xml_document indoc;
      indoc.load_string(ss.str().c_str());
      auto inchild = indoc.child(tagname());
      value->istream(inchild);
    }
   }
  template<> void Value<int>::ostreamContents(pugi::xml_node& self) const {
    char str[11]={0};
    snprintf(str, sizeof(str), "%d", _value);    
    self.append_child(pugi::node_pcdata).set_value(str);
  }
  template<> void Value<int>::istreamContents(const pugi::xml_node& self) {
    _value = self.text().as_int();
  }
  template<> void Value<float>::ostreamContents(pugi::xml_node& self) const {
    char str[15]={0};
    snprintf(str, sizeof(str), "%.3f", _value);
    while(((str[strlen(str)-1]=='0')&&(strchr(str,'.')))||str[strlen(str)-1]=='.')str[strlen(str)-1]='\0';    
    self.append_child(pugi::node_pcdata).set_value(str);
  }
  template<> void Value<float>::istreamContents(const pugi::xml_node& self) {
    _value = self.text().as_float();
  }
  template<> void Value<std::string>::ostreamContents(pugi::xml_node& self) const
  {
    self.append_child(pugi::node_pcdata).set_value(_value.c_str());
  }
  template<> void Value<std::string>::istreamContents(const pugi::xml_node& self)
  {
    _value = self.text().as_string();
  }
}
