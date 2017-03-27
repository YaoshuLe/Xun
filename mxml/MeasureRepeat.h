#ifndef MEASURE_REPEAT_H
#define MEASURE_REPEAT_H
#include "Element.h"

namespace mxml
{
  class MeasureRepeat: public Value<PositiveIntegerOrEmptyEnum>
  {
  public:
    MeasureRepeat();
    virtual const char* tagname() const { return "measure-repeat"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasSlashes() const;
    void hasSlashes(bool value);
    int slashes() const;
    void slashes(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasSlashes {false};
    int _slashes;
  };
}
#endif //MEASURE_REPEAT_H
