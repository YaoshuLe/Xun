#ifndef HAMMER_ON_PULL_OFF_H
#define HAMMER_ON_PULL_OFF_H
#include "Element.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class HammerOnPullOff: public Value<std::string>, public PrintStyle, public Placement
  {
  public:
    HammerOnPullOff();
    virtual const char* tagname() const { return "hammer-on-pull-off"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //HAMMER_ON_PULL_OFF_H
