#ifndef CANCEL_H
#define CANCEL_H
#include "Element.h"

namespace mxml
{
  class Cancel: public Value<int>
  {
  public:
    Cancel();
    virtual const char* tagname() const { return "cancel"; }
    bool hasLocation() const;
    void hasLocation(bool value);
    CancelLocationEnum location() const;
    void location(CancelLocationEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasLocation {false};
    CancelLocationEnum _location;
  };
}
#endif //CANCEL_H
