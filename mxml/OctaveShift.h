#ifndef OCTAVE_SHIFT_H
#define OCTAVE_SHIFT_H
#include "Element.h"
#include "DashedFormatting.h"
#include "PrintStyle.h"

namespace mxml
{
  class OctaveShift: public Empty, public DashedFormatting, public PrintStyle
  {
  public:
    OctaveShift();
    virtual const char* tagname() const { return "octave-shift"; }
    bool hasType() const;
    void hasType(bool value);
    UpDownStopContinueEnum type() const;
    void type(UpDownStopContinueEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasSize() const;
    void hasSize(bool value);
    int size() const;
    void size(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    UpDownStopContinueEnum _type;
    bool _hasNumber {false};
    int _number;
    bool _hasSize {false};
    int _size;
  };
}
#endif //OCTAVE_SHIFT_H
