#ifndef ACCIDENTAL_H
#define ACCIDENTAL_H
#include "Element.h"
#include "LevelDisplay.h"
#include "PrintStyle.h"

namespace mxml
{
  class Accidental: public Value<AccidentalValueEnum>, public LevelDisplay, public PrintStyle
  {
  public:
    Accidental();
    virtual const char* tagname() const { return "accidental"; }
    bool hasCautionary() const;
    void hasCautionary(bool value);
    YesNoEnum cautionary() const;
    void cautionary(YesNoEnum value);
    bool hasEditorial() const;
    void hasEditorial(bool value);
    YesNoEnum editorial() const;
    void editorial(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasCautionary {false};
    YesNoEnum _cautionary;
    bool _hasEditorial {false};
    YesNoEnum _editorial;
  };
}
#endif //ACCIDENTAL_H
