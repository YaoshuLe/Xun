#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include "Element.h"

namespace mxml
{
  class Instrument: public Empty
  {
  public:
    Instrument();
    virtual const char* tagname() const { return "instrument"; }
    bool hasId() const;
    void hasId(bool value);
    std::string id() const;
    void id(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasId {false};
    std::string _id;
  };
}
#endif //INSTRUMENT_H
