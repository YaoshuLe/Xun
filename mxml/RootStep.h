#ifndef ROOT_STEP_H
#define ROOT_STEP_H
#include "Element.h"
#include "PrintStyle.h"

namespace mxml
{
  class RootStep: public Value<StepEnum>, public PrintStyle
  {
  public:
    RootStep();
    virtual const char* tagname() const { return "root-step"; }
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
#endif //ROOT_STEP_H
