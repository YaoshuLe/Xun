#ifndef FORWARD_H
#define FORWARD_H
#include "Element.h"

namespace mxml
{
  class Duration;
  using DurationPtr = std::shared_ptr<Duration>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;
  class Voice;
  using VoicePtr = std::shared_ptr<Voice>;
  class Staff;
  using StaffPtr = std::shared_ptr<Staff>;

  class Forward: public Element
  {
  public:
    Forward();
    virtual const char* tagname() const { return "forward"; }
    DurationPtr getDuration() const;
    void setDuration(const DurationPtr& value);
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    VoicePtr getVoice() const;
    void setVoice(const VoicePtr& value);
    StaffPtr getStaff() const;
    void setStaff(const StaffPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DurationPtr _durationPtr;
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    VoicePtr _voicePtr;
    StaffPtr _staffPtr;
  };
}
#endif //FORWARD_H
