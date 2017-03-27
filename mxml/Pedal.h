#ifndef PEDAL_H
#define PEDAL_H
#include "Element.h"
#include "PrintStyleAlign.h"

namespace mxml
{
  class Pedal: public Empty, public PrintStyleAlign
  {
  public:
    Pedal();
    virtual const char* tagname() const { return "pedal"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopChangeContinueEnum type() const;
    void type(StartStopChangeContinueEnum value);
    bool hasLine() const;
    void hasLine(bool value);
    YesNoEnum line() const;
    void line(YesNoEnum value);
    bool hasSign() const;
    void hasSign(bool value);
    YesNoEnum sign() const;
    void sign(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopChangeContinueEnum _type;
    bool _hasLine {false};
    YesNoEnum _line;
    bool _hasSign {false};
    YesNoEnum _sign;
  };
}
#endif //PEDAL_H
