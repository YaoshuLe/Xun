#ifndef FIGURED_BASS_H
#define FIGURED_BASS_H
#include "Element.h"
#include "PrintStyle.h"
#include "Printout.h"

namespace mxml
{
  class Figure;
  using FigurePtr = std::shared_ptr<Figure>;
  using FigureSet = std::vector<FigurePtr>;
  class Duration;
  using DurationPtr = std::shared_ptr<Duration>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;

  class FiguredBass: public Element, public PrintStyle, public Printout
  {
  public:
    FiguredBass();
    virtual const char* tagname() const { return "figured-bass"; }
    const FigureSet& getFigureSet() const;
    void removeFigure(const FigurePtr& value);
    void addFigure(const FigurePtr& value);
    void clearFigureSet();
    DurationPtr getDuration() const;
    void setDuration(const DurationPtr& value);
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    bool hasParentheses() const;
    void hasParentheses(bool value);
    YesNoEnum parentheses() const;
    void parentheses(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    FigureSet _figureSet;
    DurationPtr _durationPtr;
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    bool _hasParentheses {false};
    YesNoEnum _parentheses;
  };
}
#endif //FIGURED_BASS_H
