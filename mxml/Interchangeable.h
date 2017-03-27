#ifndef INTERCHANGEABLE_H
#define INTERCHANGEABLE_H
#include "Element.h"

namespace mxml
{
  class TimeRelation;
  using TimeRelationPtr = std::shared_ptr<TimeRelation>;
  class TimeSignature;
  using TimeSignaturePtr = std::shared_ptr<TimeSignature>;
  using TimeSignatureSet = std::vector<TimeSignaturePtr>;

  class Interchangeable: public Element
  {
  public:
    Interchangeable();
    virtual const char* tagname() const { return "interchangeable"; }
    TimeRelationPtr getTimeRelation() const;
    void setTimeRelation(const TimeRelationPtr& value);
    const TimeSignatureSet& getTimeSignatureSet() const;
    void removeTimeSignature(const TimeSignaturePtr& value);
    void addTimeSignature(const TimeSignaturePtr& value);
    void clearTimeSignatureSet();
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
    TimeRelationPtr _timeRelationPtr;
    TimeSignatureSet _timeSignatureSet;
    bool _hasSymbol {false};
    TimeSymbolEnum _symbol;
    bool _hasSeparator {false};
    TimeSeparatorEnum _separator;
  };
}
#endif //INTERCHANGEABLE_H
