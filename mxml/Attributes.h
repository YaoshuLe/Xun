#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H
#include "Element.h"

namespace mxml
{
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;
  class Divisions;
  using DivisionsPtr = std::shared_ptr<Divisions>;
  class Key;
  using KeyPtr = std::shared_ptr<Key>;
  using KeySet = std::vector<KeyPtr>;
  class Time;
  using TimePtr = std::shared_ptr<Time>;
  using TimeSet = std::vector<TimePtr>;
  class Staves;
  using StavesPtr = std::shared_ptr<Staves>;
  class PartSymbol;
  using PartSymbolPtr = std::shared_ptr<PartSymbol>;
  class Instruments;
  using InstrumentsPtr = std::shared_ptr<Instruments>;
  class Clef;
  using ClefPtr = std::shared_ptr<Clef>;
  using ClefSet = std::vector<ClefPtr>;
  class StaffDetails;
  using StaffDetailsPtr = std::shared_ptr<StaffDetails>;
  using StaffDetailsSet = std::vector<StaffDetailsPtr>;
  class Transpose;
  using TransposePtr = std::shared_ptr<Transpose>;
  using TransposeSet = std::vector<TransposePtr>;
  class MeasureStyle;
  using MeasureStylePtr = std::shared_ptr<MeasureStyle>;
  using MeasureStyleSet = std::vector<MeasureStylePtr>;

  class Attributes: public Element
  {
  public:
    Attributes();
    virtual const char* tagname() const { return "attributes"; }
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    DivisionsPtr getDivisions() const;
    void setDivisions(const DivisionsPtr& value);
    const KeySet& getKeySet() const;
    void removeKey(const KeyPtr& value);
    void addKey(const KeyPtr& value);
    void clearKeySet();
    const TimeSet& getTimeSet() const;
    void removeTime(const TimePtr& value);
    void addTime(const TimePtr& value);
    void clearTimeSet();
    StavesPtr getStaves() const;
    void setStaves(const StavesPtr& value);
    PartSymbolPtr getPartSymbol() const;
    void setPartSymbol(const PartSymbolPtr& value);
    InstrumentsPtr getInstruments() const;
    void setInstruments(const InstrumentsPtr& value);
    const ClefSet& getClefSet() const;
    void removeClef(const ClefPtr& value);
    void addClef(const ClefPtr& value);
    void clearClefSet();
    const StaffDetailsSet& getStaffDetailsSet() const;
    void removeStaffDetails(const StaffDetailsPtr& value);
    void addStaffDetails(const StaffDetailsPtr& value);
    void clearStaffDetailsSet();
    const TransposeSet& getTransposeSet() const;
    void removeTranspose(const TransposePtr& value);
    void addTranspose(const TransposePtr& value);
    void clearTransposeSet();
    const MeasureStyleSet& getMeasureStyleSet() const;
    void removeMeasureStyle(const MeasureStylePtr& value);
    void addMeasureStyle(const MeasureStylePtr& value);
    void clearMeasureStyleSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    DivisionsPtr _divisionsPtr;
    KeySet _keySet;
    TimeSet _timeSet;
    StavesPtr _stavesPtr;
    PartSymbolPtr _partSymbolPtr;
    InstrumentsPtr _instrumentsPtr;
    ClefSet _clefSet;
    StaffDetailsSet _staffDetailsSet;
    TransposeSet _transposeSet;
    MeasureStyleSet _measureStyleSet;
  };
}
#endif //ATTRIBUTES_H
