#ifndef MEASURE_STYLE_H
#define MEASURE_STYLE_H
#include "Element.h"
#include "Font.h"
#include "Color.h"

namespace mxml
{
  class MultipleRest;
  using MultipleRestPtr = std::shared_ptr<MultipleRest>;
  class MeasureRepeat;
  using MeasureRepeatPtr = std::shared_ptr<MeasureRepeat>;
  class BeatRepeat;
  using BeatRepeatPtr = std::shared_ptr<BeatRepeat>;
  class Slash;
  using SlashPtr = std::shared_ptr<Slash>;

  class MeasureStyle: public Element, public Font, public Color
  {
  public:
    MeasureStyle();
    virtual const char* tagname() const { return "measure-style"; }
    MultipleRestPtr getMultipleRest() const;
    void setMultipleRest(const MultipleRestPtr& value);
    MeasureRepeatPtr getMeasureRepeat() const;
    void setMeasureRepeat(const MeasureRepeatPtr& value);
    BeatRepeatPtr getBeatRepeat() const;
    void setBeatRepeat(const BeatRepeatPtr& value);
    SlashPtr getSlash() const;
    void setSlash(const SlashPtr& value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MultipleRestPtr _multipleRestPtr;
    MeasureRepeatPtr _measureRepeatPtr;
    BeatRepeatPtr _beatRepeatPtr;
    SlashPtr _slashPtr;
    bool _hasNumber {false};
    int _number;
  };
}
#endif //MEASURE_STYLE_H
