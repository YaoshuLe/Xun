#ifndef HARMONY_H
#define HARMONY_H
#include "Element.h"
#include "PrintObject.h"
#include "PrintStyle.h"
#include "Placement.h"

namespace mxml
{
  class HarmonyChord;
  using HarmonyChordPtr = std::shared_ptr<HarmonyChord>;
  using HarmonyChordSet = std::vector<HarmonyChordPtr>;
  class Frame;
  using FramePtr = std::shared_ptr<Frame>;
  class Offset;
  using OffsetPtr = std::shared_ptr<Offset>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;
  class Staff;
  using StaffPtr = std::shared_ptr<Staff>;

  class Harmony: public Element, public PrintObject, public PrintStyle, public Placement
  {
  public:
    Harmony();
    virtual const char* tagname() const { return "harmony"; }
    const HarmonyChordSet& getHarmonyChordSet() const;
    void removeHarmonyChord(const HarmonyChordPtr& value);
    void addHarmonyChord(const HarmonyChordPtr& value);
    void clearHarmonyChordSet();
    FramePtr getFrame() const;
    void setFrame(const FramePtr& value);
    OffsetPtr getOffset() const;
    void setOffset(const OffsetPtr& value);
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    StaffPtr getStaff() const;
    void setStaff(const StaffPtr& value);
    bool hasType() const;
    void hasType(bool value);
    HarmonyTypeEnum type() const;
    void type(HarmonyTypeEnum value);
    bool hasPrintFrame() const;
    void hasPrintFrame(bool value);
    YesNoEnum printFrame() const;
    void printFrame(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    HarmonyChordSet _harmonyChordSet;
    FramePtr _framePtr;
    OffsetPtr _offsetPtr;
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    StaffPtr _staffPtr;
    bool _hasType {false};
    HarmonyTypeEnum _type;
    bool _hasPrintFrame {false};
    YesNoEnum _printFrame;
  };
}
#endif //HARMONY_H
