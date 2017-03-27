#ifndef METRONOME_TUPLET_H
#define METRONOME_TUPLET_H
#include "Element.h"

namespace mxml
{
  class ActualNotes;
  using ActualNotesPtr = std::shared_ptr<ActualNotes>;
  class NormalNotes;
  using NormalNotesPtr = std::shared_ptr<NormalNotes>;
  class NormalType;
  using NormalTypePtr = std::shared_ptr<NormalType>;
  class NormalDot;
  using NormalDotPtr = std::shared_ptr<NormalDot>;
  using NormalDotSet = std::vector<NormalDotPtr>;

  class MetronomeTuplet: public Element
  {
  public:
    MetronomeTuplet();
    virtual const char* tagname() const { return "metronome-tuplet"; }
    ActualNotesPtr getActualNotes() const;
    void setActualNotes(const ActualNotesPtr& value);
    NormalNotesPtr getNormalNotes() const;
    void setNormalNotes(const NormalNotesPtr& value);
    NormalTypePtr getNormalType() const;
    void setNormalType(const NormalTypePtr& value);
    const NormalDotSet& getNormalDotSet() const;
    void removeNormalDot(const NormalDotPtr& value);
    void addNormalDot(const NormalDotPtr& value);
    void clearNormalDotSet();
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasBracket() const;
    void hasBracket(bool value);
    YesNoEnum bracket() const;
    void bracket(YesNoEnum value);
    bool hasShowNumber() const;
    void hasShowNumber(bool value);
    ShowTupletEnum showNumber() const;
    void showNumber(ShowTupletEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    ActualNotesPtr _actualNotesPtr;
    NormalNotesPtr _normalNotesPtr;
    NormalTypePtr _normalTypePtr;
    NormalDotSet _normalDotSet;
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasBracket {false};
    YesNoEnum _bracket;
    bool _hasShowNumber {false};
    ShowTupletEnum _showNumber;
  };
}
#endif //METRONOME_TUPLET_H
