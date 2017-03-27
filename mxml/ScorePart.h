#ifndef SCORE_PART_H
#define SCORE_PART_H
#include "Element.h"

namespace mxml
{
  class Identification;
  using IdentificationPtr = std::shared_ptr<Identification>;
  class PartName;
  using PartNamePtr = std::shared_ptr<PartName>;
  class PartNameDisplay;
  using PartNameDisplayPtr = std::shared_ptr<PartNameDisplay>;
  class PartAbbreviation;
  using PartAbbreviationPtr = std::shared_ptr<PartAbbreviation>;
  class PartAbbreviationDisplay;
  using PartAbbreviationDisplayPtr = std::shared_ptr<PartAbbreviationDisplay>;
  class Group;
  using GroupPtr = std::shared_ptr<Group>;
  using GroupSet = std::vector<GroupPtr>;
  class ScoreInstrument;
  using ScoreInstrumentPtr = std::shared_ptr<ScoreInstrument>;
  using ScoreInstrumentSet = std::vector<ScoreInstrumentPtr>;
  class MidiInfo;
  using MidiInfoPtr = std::shared_ptr<MidiInfo>;
  using MidiInfoSet = std::vector<MidiInfoPtr>;

  class ScorePart: public Element
  {
  public:
    ScorePart();
    virtual const char* tagname() const { return "score-part"; }
    IdentificationPtr getIdentification() const;
    void setIdentification(const IdentificationPtr& value);
    PartNamePtr getPartName() const;
    void setPartName(const PartNamePtr& value);
    PartNameDisplayPtr getPartNameDisplay() const;
    void setPartNameDisplay(const PartNameDisplayPtr& value);
    PartAbbreviationPtr getPartAbbreviation() const;
    void setPartAbbreviation(const PartAbbreviationPtr& value);
    PartAbbreviationDisplayPtr getPartAbbreviationDisplay() const;
    void setPartAbbreviationDisplay(const PartAbbreviationDisplayPtr& value);
    const GroupSet& getGroupSet() const;
    void removeGroup(const GroupPtr& value);
    void addGroup(const GroupPtr& value);
    void clearGroupSet();
    const ScoreInstrumentSet& getScoreInstrumentSet() const;
    void removeScoreInstrument(const ScoreInstrumentPtr& value);
    void addScoreInstrument(const ScoreInstrumentPtr& value);
    void clearScoreInstrumentSet();
    const MidiInfoSet& getMidiInfoSet() const;
    void removeMidiInfo(const MidiInfoPtr& value);
    void addMidiInfo(const MidiInfoPtr& value);
    void clearMidiInfoSet();
    bool hasId() const;
    void hasId(bool value);
    std::string id() const;
    void id(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    IdentificationPtr _identificationPtr;
    PartNamePtr _partNamePtr;
    PartNameDisplayPtr _partNameDisplayPtr;
    PartAbbreviationPtr _partAbbreviationPtr;
    PartAbbreviationDisplayPtr _partAbbreviationDisplayPtr;
    GroupSet _groupSet;
    ScoreInstrumentSet _scoreInstrumentSet;
    MidiInfoSet _midiInfoSet;
    bool _hasId {false};
    std::string _id;
  };
}
#endif //SCORE_PART_H
