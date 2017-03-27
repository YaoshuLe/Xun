#ifndef APPEARANCE_H
#define APPEARANCE_H
#include "Element.h"

namespace mxml
{
  class LineWidth;
  using LineWidthPtr = std::shared_ptr<LineWidth>;
  using LineWidthSet = std::vector<LineWidthPtr>;
  class NoteSize;
  using NoteSizePtr = std::shared_ptr<NoteSize>;
  using NoteSizeSet = std::vector<NoteSizePtr>;
  class Distance;
  using DistancePtr = std::shared_ptr<Distance>;
  using DistanceSet = std::vector<DistancePtr>;
  class OtherAppearance;
  using OtherAppearancePtr = std::shared_ptr<OtherAppearance>;
  using OtherAppearanceSet = std::vector<OtherAppearancePtr>;

  class Appearance: public Element
  {
  public:
    Appearance();
    virtual const char* tagname() const { return "appearance"; }
    const LineWidthSet& getLineWidthSet() const;
    void removeLineWidth(const LineWidthPtr& value);
    void addLineWidth(const LineWidthPtr& value);
    void clearLineWidthSet();
    const NoteSizeSet& getNoteSizeSet() const;
    void removeNoteSize(const NoteSizePtr& value);
    void addNoteSize(const NoteSizePtr& value);
    void clearNoteSizeSet();
    const DistanceSet& getDistanceSet() const;
    void removeDistance(const DistancePtr& value);
    void addDistance(const DistancePtr& value);
    void clearDistanceSet();
    const OtherAppearanceSet& getOtherAppearanceSet() const;
    void removeOtherAppearance(const OtherAppearancePtr& value);
    void addOtherAppearance(const OtherAppearancePtr& value);
    void clearOtherAppearanceSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    LineWidthSet _lineWidthSet;
    NoteSizeSet _noteSizeSet;
    DistanceSet _distanceSet;
    OtherAppearanceSet _otherAppearanceSet;
  };
}
#endif //APPEARANCE_H
