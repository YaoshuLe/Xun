#ifndef ELEMENT_H
#define ELEMENT_H
#include <memory>
#include <vector>
#include <algorithm>
#include "pugixml.hpp"
#include "Enums.h"

namespace mxml
{
  using Tick = long;
  const Tick DIVISIONS  = 26880;

  class Element;
  using ElementPtr = std::shared_ptr<Element>;
  using ElementSet = std::vector<ElementPtr>;

  class Element: public std::enable_shared_from_this<Element>
  {
  public:
    virtual ~Element();
    virtual const char* tagname() const = 0;
    void ostream(pugi::xml_node& self) const;
    void istream(const pugi::xml_node& self);
    void setParent(const ElementPtr& value);        
    ElementPtr getParent() const;
    template<typename T> std::shared_ptr<T> getParent() const;
    void clone(const ElementPtr& value) const;
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const = 0;
    virtual void istreamAttrs(const pugi::xml_node& self) = 0;
    virtual void ostreamContents(pugi::xml_node& self) const = 0;
    virtual void istreamContents(const pugi::xml_node& self) = 0;
    std::weak_ptr<Element> _parentPtr;
  };
  template<typename T> std::shared_ptr<T> Element::getParent() const
  {
    ElementPtr ptr(_parentPtr.lock());
    while(ptr&&(!std::dynamic_pointer_cast<T>(ptr).get())) {
      ptr = ptr->getParent();
    }
    return std::dynamic_pointer_cast<T>(ptr);
  }

  class Empty: public Element
  {
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const { (void)self; }
    virtual void istreamContents(const pugi::xml_node& self) { (void)self; }
  };

  template<class T> class Value: public Element
  {
  public:
    T value() const {
      return _value;
    }
    void value(T value) {
      _value = value;
    }
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const {
      self.append_child(pugi::node_pcdata).set_value(_value.operator const char *());
    }
    virtual void istreamContents(const pugi::xml_node& self) {
      _value = T(self.text().as_string());
    }
    T _value;
  };
  template<> void Value<int>::ostreamContents(pugi::xml_node& self) const;
  template<> void Value<int>::istreamContents(const pugi::xml_node& self);
  template<> void Value<float>::ostreamContents(pugi::xml_node& self) const;
  template<> void Value<float>::istreamContents(const pugi::xml_node& self);
  template<> void Value<std::string>::ostreamContents(pugi::xml_node& self) const;
  template<> void Value<std::string>::istreamContents(const pugi::xml_node& self);
}
#endif //ELEMENT_H
