#ifndef KEY_OCTAVE_H
#define KEY_OCTAVE_H
#include "Element.h"

namespace mxml
{
  class KeyOctave: public Value<int>
  {
  public:
    KeyOctave();
    virtual const char* tagname() const { return "key-octave"; }
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasCancel() const;
    void hasCancel(bool value);
    YesNoEnum cancel() const;
    void cancel(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasNumber {false};
    int _number;
    bool _hasCancel {false};
    YesNoEnum _cancel;
  };
}
#endif //KEY_OCTAVE_H
