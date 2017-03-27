#ifndef DIRECTION_H
#define DIRECTION_H
#include "Element.h"
#include "Placement.h"
#include "Directive.h"

namespace mxml
{
  class DirectionType;
  using DirectionTypePtr = std::shared_ptr<DirectionType>;
  using DirectionTypeSet = std::vector<DirectionTypePtr>;
  class Offset;
  using OffsetPtr = std::shared_ptr<Offset>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;
  class Voice;
  using VoicePtr = std::shared_ptr<Voice>;
  class Staff;
  using StaffPtr = std::shared_ptr<Staff>;
  class Sound;
  using SoundPtr = std::shared_ptr<Sound>;

  class Direction: public Element, public Placement, public Directive
  {
  public:
    Direction();
    virtual const char* tagname() const { return "direction"; }
    const DirectionTypeSet& getDirectionTypeSet() const;
    void removeDirectionType(const DirectionTypePtr& value);
    void addDirectionType(const DirectionTypePtr& value);
    void clearDirectionTypeSet();
    OffsetPtr getOffset() const;
    void setOffset(const OffsetPtr& value);
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    VoicePtr getVoice() const;
    void setVoice(const VoicePtr& value);
    StaffPtr getStaff() const;
    void setStaff(const StaffPtr& value);
    SoundPtr getSound() const;
    void setSound(const SoundPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DirectionTypeSet _directionTypeSet;
    OffsetPtr _offsetPtr;
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    VoicePtr _voicePtr;
    StaffPtr _staffPtr;
    SoundPtr _soundPtr;
  };
}
#endif //DIRECTION_H
