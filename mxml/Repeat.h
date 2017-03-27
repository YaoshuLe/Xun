#ifndef REPEAT_H
#define REPEAT_H
#include "Element.h"

namespace mxml
{
  class Repeat: public Empty
  {
  public:
    Repeat();
    virtual const char* tagname() const { return "repeat"; }
    bool hasDirection() const;
    void hasDirection(bool value);
    BackwardForwardEnum direction() const;
    void direction(BackwardForwardEnum value);
    bool hasTimes() const;
    void hasTimes(bool value);
    int times() const;
    void times(int value);
    bool hasWinged() const;
    void hasWinged(bool value);
    WingedEnum winged() const;
    void winged(WingedEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasDirection {false};
    BackwardForwardEnum _direction;
    bool _hasTimes {false};
    int _times;
    bool _hasWinged {false};
    WingedEnum _winged;
  };
}
#endif //REPEAT_H
