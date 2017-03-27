#ifndef LYRIC_LANGUAGE_H
#define LYRIC_LANGUAGE_H
#include "Element.h"

namespace mxml
{
  class LyricLanguage: public Empty
  {
  public:
    LyricLanguage();
    virtual const char* tagname() const { return "lyric-language"; }
    bool hasNumber() const;
    void hasNumber(bool value);
    std::string number() const;
    void number(std::string value);
    bool hasName() const;
    void hasName(bool value);
    std::string name() const;
    void name(std::string value);
    bool hasLang() const;
    void hasLang(bool value);
    std::string lang() const;
    void lang(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasNumber {false};
    std::string _number;
    bool _hasName {false};
    std::string _name;
    bool _hasLang {false};
    std::string _lang;
  };
}
#endif //LYRIC_LANGUAGE_H
