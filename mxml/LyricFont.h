#ifndef LYRIC_FONT_H
#define LYRIC_FONT_H
#include "Element.h"
#include "Font.h"

namespace mxml
{
  class LyricFont: public Empty, public Font
  {
  public:
    LyricFont();
    virtual const char* tagname() const { return "lyric-font"; }
    bool hasNumber() const;
    void hasNumber(bool value);
    std::string number() const;
    void number(std::string value);
    bool hasName() const;
    void hasName(bool value);
    std::string name() const;
    void name(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasNumber {false};
    std::string _number;
    bool _hasName {false};
    std::string _name;
  };
}
#endif //LYRIC_FONT_H
