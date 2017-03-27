#ifndef TIE_H
#define TIE_H
#include "Element.h"

namespace mxml
{
  class Tie: public Empty
  {
  public:
    Tie();
    virtual const char* tagname() const { return "tie"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasTimeOnly() const;
    void hasTimeOnly(bool value);
    std::string timeOnly() const;
    void timeOnly(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasTimeOnly {false};
    std::string _timeOnly;
  };
}
#endif //TIE_H
