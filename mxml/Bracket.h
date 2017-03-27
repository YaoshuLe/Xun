#ifndef BRACKET_H
#define BRACKET_H
#include "Element.h"
#include "LineType.h"
#include "DashedFormatting.h"
#include "Position.h"
#include "Color.h"

namespace mxml
{
  class Bracket: public Empty, public LineType, public DashedFormatting, public Position, public Color
  {
  public:
    Bracket();
    virtual const char* tagname() const { return "bracket"; }
    bool hasType() const;
    void hasType(bool value);
    StartStopContinueEnum type() const;
    void type(StartStopContinueEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasLineEnd() const;
    void hasLineEnd(bool value);
    LineEndEnum lineEnd() const;
    void lineEnd(LineEndEnum value);
    bool hasEndLength() const;
    void hasEndLength(bool value);
    float endLength() const;
    void endLength(float value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasType {false};
    StartStopContinueEnum _type;
    bool _hasNumber {false};
    int _number;
    bool _hasLineEnd {false};
    LineEndEnum _lineEnd;
    bool _hasEndLength {false};
    float _endLength;
  };
}
#endif //BRACKET_H
