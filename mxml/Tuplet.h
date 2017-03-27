#ifndef TUPLET_H
#define TUPLET_H
#include "Element.h"
#include "LineShape.h"
#include "Position.h"
#include "Placement.h"

namespace mxml
{
  class TupletActual;
  using TupletActualPtr = std::shared_ptr<TupletActual>;
  class TupletNormal;
  using TupletNormalPtr = std::shared_ptr<TupletNormal>;

  class Tuplet: public Element, public LineShape, public Position, public Placement
  {
  public:
    Tuplet();
    virtual const char* tagname() const { return "tuplet"; }
    TupletActualPtr getTupletActual() const;
    void setTupletActual(const TupletActualPtr& value);
    TupletNormalPtr getTupletNormal() const;
    void setTupletNormal(const TupletNormalPtr& value);
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasBracket() const;
    void hasBracket(bool value);
    YesNoEnum bracket() const;
    void bracket(YesNoEnum value);
    bool hasShowNumber() const;
    void hasShowNumber(bool value);
    ShowTupletEnum showNumber() const;
    void showNumber(ShowTupletEnum value);
    bool hasShowType() const;
    void hasShowType(bool value);
    ShowTupletEnum showType() const;
    void showType(ShowTupletEnum value);
  protected:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    TupletActualPtr _tupletActualPtr;
    TupletNormalPtr _tupletNormalPtr;
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasNumber {false};
    int _number;
    bool _hasBracket {false};
    YesNoEnum _bracket;
    bool _hasShowNumber {false};
    ShowTupletEnum _showNumber;
    bool _hasShowType {false};
    ShowTupletEnum _showType;
  };
}
#endif //TUPLET_H
