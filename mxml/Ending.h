#ifndef ENDING_H
#define ENDING_H
#include "Element.h"
#include "PrintObject.h"
#include "PrintStyle.h"

namespace mxml
{
  class Ending: public Value<std::string>, public PrintObject, public PrintStyle
  {
  public:
    Ending();
    virtual const char* tagname() const { return "ending"; }
    bool hasNumber() const;
    void hasNumber(bool value);
    std::string number() const;
    void number(std::string value);
    bool hasType() const;
    void hasType(bool value);
    StartStopDiscontinueEnum type() const;
    void type(StartStopDiscontinueEnum value);
    bool hasEndLength() const;
    void hasEndLength(bool value);
    float endLength() const;
    void endLength(float value);
    bool hasTextX() const;
    void hasTextX(bool value);
    float textX() const;
    void textX(float value);
    bool hasTextY() const;
    void hasTextY(bool value);
    float textY() const;
    void textY(float value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasNumber {false};
    std::string _number;
    bool _hasType {false};
    StartStopDiscontinueEnum _type;
    bool _hasEndLength {false};
    float _endLength;
    bool _hasTextX {false};
    float _textX;
    bool _hasTextY {false};
    float _textY;
  };
}
#endif //ENDING_H
