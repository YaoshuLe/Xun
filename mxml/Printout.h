#ifndef PRINTOUT_H
#define PRINTOUT_H
#include "PrintObject.h"
#include "PrintSpacing.h"

namespace mxml
{
  class Printout: public PrintObject, public PrintSpacing
  {
  public:
    Printout();
    bool hasPrintDot() const;
    void hasPrintDot(bool value);
    YesNoEnum printDot() const;
    void printDot(YesNoEnum value);
    bool hasPrintLyric() const;
    void hasPrintLyric(bool value);
    YesNoEnum printLyric() const;
    void printLyric(YesNoEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasPrintDot {false};
    YesNoEnum _printDot;
    bool _hasPrintLyric {false};
    YesNoEnum _printLyric;
  };
}
#endif //PRINTOUT_H
