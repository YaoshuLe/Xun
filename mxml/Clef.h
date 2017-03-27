#ifndef CLEF_H
#define CLEF_H
#include "Element.h"
#include "PrintStyle.h"
#include "PrintObject.h"

namespace mxml
{
  class Sign;
  using SignPtr = std::shared_ptr<Sign>;
  class Line;
  using LinePtr = std::shared_ptr<Line>;
  class ClefOctaveChange;
  using ClefOctaveChangePtr = std::shared_ptr<ClefOctaveChange>;

  class Clef: public Element, public PrintStyle, public PrintObject
  {
  public:
    Clef();
    virtual const char* tagname() const { return "clef"; }
    SignPtr getSign() const;
    void setSign(const SignPtr& value);
    LinePtr getLine() const;
    void setLine(const LinePtr& value);
    ClefOctaveChangePtr getClefOctaveChange() const;
    void setClefOctaveChange(const ClefOctaveChangePtr& value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasAdditional() const;
    void hasAdditional(bool value);
    YesNoEnum additional() const;
    void additional(YesNoEnum value);
    bool hasSize() const;
    void hasSize(bool value);
    SymbolSizeEnum size() const;
    void size(SymbolSizeEnum value);
    bool hasAfterBarline() const;
    void hasAfterBarline(bool value);
    YesNoEnum afterBarline() const;
    void afterBarline(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    SignPtr _signPtr;
    LinePtr _linePtr;
    ClefOctaveChangePtr _clefOctaveChangePtr;
    bool _hasNumber {false};
    int _number;
    bool _hasAdditional {false};
    YesNoEnum _additional;
    bool _hasSize {false};
    SymbolSizeEnum _size;
    bool _hasAfterBarline {false};
    YesNoEnum _afterBarline;
  };
}
#endif //CLEF_H
