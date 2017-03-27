#ifndef MEASURE_H
#define MEASURE_H
#include "Element.h"
#include "MeasureAttributes.h"

namespace mxml
{
  using MusicData = Element;
  using MusicDataPtr = std::shared_ptr<MusicData>;
  using MusicDataSet = std::vector<MusicDataPtr>;


  class Measure;
  using MeasurePtr = std::shared_ptr<Measure>;
  class StaffDetails;
  using StaffDetailsPtr = std::shared_ptr<StaffDetails>;
  class Clef;
  using ClefPtr = std::shared_ptr<Clef>;
  class Key;
  using KeyPtr = std::shared_ptr<Key>;

  class Measure: public Element, public MeasureAttributes
  {
  public:
    Measure();
    virtual const char* tagname() const { return "measure"; }
    const MusicDataSet& getMusicDataSet() const;
    void removeMusicData(const MusicDataPtr& value);
    void addMusicData(const MusicDataPtr& value);
    void clearMusicDataSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    MusicDataSet _musicDataSet;
  public:
    MeasurePtr getNextMeasure() const;
    MeasurePtr getPrevMeasure() const;
    StaffDetailsPtr getStaffDetails(int snb) const;
    ClefPtr getClef(int snb) const;
    KeyPtr getKey(int snb) const;
  };
}
#endif //MEASURE_H
