#ifndef LINE_WIDTH_H
#define LINE_WIDTH_H
#include "Element.h"

namespace mxml
{
  class LineWidth: public Value<float>
  {
  public:
    LineWidth();
    virtual const char* tagname() const { return "line-width"; }
    bool hasType() const;
    void hasType(bool value);
    std::string type() const;
    void type(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    std::string _type;
  };
}
#endif //LINE_WIDTH_H
