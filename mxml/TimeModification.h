#ifndef TIME_MODIFICATION_H
#define TIME_MODIFICATION_H
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

  class TimeModification: public Element
  {
  public:
    TimeModification();
    virtual const char* tagname() const { return "time-modification"; }
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
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    ActualNotesPtr _actualNotesPtr;
    NormalNotesPtr _normalNotesPtr;
    NormalTypePtr _normalTypePtr;
    NormalDotSet _normalDotSet;
  };
}
#endif //TIME_MODIFICATION_H
