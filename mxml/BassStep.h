#ifndef BASS_STEP_H
#define BASS_STEP_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class BassStep: public Value<StepEnum>, public PrintStyle
  {
  public:
    BassStep();
    virtual const char* tagname() const { return "bass-step"; }
    bool hasText() const;
    void hasText(bool value);
    std::string text() const;
    void text(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasText {false};
    std::string _text;
  };
}
#endif //BASS_STEP_H
