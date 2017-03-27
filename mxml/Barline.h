#ifndef BARLINE_H
#define BARLINE_H
#include "Element.h"

namespace mxml
{
  class BarStyle;
  using BarStylePtr = std::shared_ptr<BarStyle>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;
  class WavyLine;
  using WavyLinePtr = std::shared_ptr<WavyLine>;
  class Segno;
  using SegnoPtr = std::shared_ptr<Segno>;
  class Coda;
  using CodaPtr = std::shared_ptr<Coda>;
  class Fermata;
  using FermataPtr = std::shared_ptr<Fermata>;
  using FermataSet = std::vector<FermataPtr>;
  class Ending;
  using EndingPtr = std::shared_ptr<Ending>;
  class Repeat;
  using RepeatPtr = std::shared_ptr<Repeat>;

  class Barline: public Element
  {
  public:
    Barline();
    virtual const char* tagname() const { return "barline"; }
    BarStylePtr getBarStyle() const;
    void setBarStyle(const BarStylePtr& value);
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    WavyLinePtr getWavyLine() const;
    void setWavyLine(const WavyLinePtr& value);
    SegnoPtr getSegno() const;
    void setSegno(const SegnoPtr& value);
    CodaPtr getCoda() const;
    void setCoda(const CodaPtr& value);
    const FermataSet& getFermataSet() const;
    void removeFermata(const FermataPtr& value);
    void addFermata(const FermataPtr& value);
    void clearFermataSet();
    EndingPtr getEnding() const;
    void setEnding(const EndingPtr& value);
    RepeatPtr getRepeat() const;
    void setRepeat(const RepeatPtr& value);
    bool hasLocation() const;
    void hasLocation(bool value);
    RightLeftMiddleEnum location() const;
    void location(RightLeftMiddleEnum value);
    bool hasSegno() const;
    void hasSegno(bool value);
    std::string segno() const;
    void segno(std::string value);
    bool hasCoda() const;
    void hasCoda(bool value);
    std::string coda() const;
    void coda(std::string value);
    bool hasDivisions() const;
    void hasDivisions(bool value);
    float divisions() const;
    void divisions(float value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    BarStylePtr _barStylePtr;
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    WavyLinePtr _wavyLinePtr;
    SegnoPtr _segnoPtr;
    CodaPtr _codaPtr;
    FermataSet _fermataSet;
    EndingPtr _endingPtr;
    RepeatPtr _repeatPtr;
    bool _hasLocation {false};
    RightLeftMiddleEnum _location;
    bool _hasSegno {false};
    std::string _segno;
    bool _hasCoda {false};
    std::string _coda;
    bool _hasDivisions {false};
    float _divisions;
  };
}
#endif //BARLINE_H
