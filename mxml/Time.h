#ifndef TIME_H
#define TIME_H
#include "Element.h"
#include "PrintStyleAlign.h"
#include "PrintObject.h"

namespace mxml
{
  class TimeSignature;
  using TimeSignaturePtr = std::shared_ptr<TimeSignature>;
  using TimeSignatureSet = std::vector<TimeSignaturePtr>;
  class Interchangeable;
  using InterchangeablePtr = std::shared_ptr<Interchangeable>;
  class SenzaMisura;
  using SenzaMisuraPtr = std::shared_ptr<SenzaMisura>;

  class Time: public Element, public PrintStyleAlign, public PrintObject
  {
  public:
    Time();
    virtual const char* tagname() const { return "time"; }
    const TimeSignatureSet& getTimeSignatureSet() const;
    void removeTimeSignature(const TimeSignaturePtr& value);
    void addTimeSignature(const TimeSignaturePtr& value);
    void clearTimeSignatureSet();
    InterchangeablePtr getInterchangeable() const;
    void setInterchangeable(const InterchangeablePtr& value);
    SenzaMisuraPtr getSenzaMisura() const;
    void setSenzaMisura(const SenzaMisuraPtr& value);
    bool hasNumber() const;
    void hasNumber(bool value);
    int number() const;
    void number(int value);
    bool hasSymbol() const;
    void hasSymbol(bool value);
    TimeSymbolEnum symbol() const;
    void symbol(TimeSymbolEnum value);
    bool hasSeparator() const;
    void hasSeparator(bool value);
    TimeSeparatorEnum separator() const;
    void separator(TimeSeparatorEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    TimeSignatureSet _timeSignatureSet;
    InterchangeablePtr _interchangeablePtr;
    SenzaMisuraPtr _senzaMisuraPtr;
    bool _hasNumber {false};
    int _number;
    bool _hasSymbol {false};
    TimeSymbolEnum _symbol;
    bool _hasSeparator {false};
    TimeSeparatorEnum _separator;
  };
}
#endif //TIME_H
