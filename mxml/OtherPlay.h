#ifndef OTHER_PLAY_H
#define OTHER_PLAY_H
#include "Element.h"

namespace mxml
{
  class OtherPlay: public Value<std::string>
  {
  public:
    OtherPlay();
    virtual const char* tagname() const { return "other-play"; }
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
#endif //OTHER_PLAY_H
