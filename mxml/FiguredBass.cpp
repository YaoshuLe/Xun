#include "FiguredBass.h"
#include <cstring>
#include "Figure.h"
#include "Duration.h"
#include "Footnote.h"
#include "Level.h"

namespace mxml
{
  FiguredBass::FiguredBass() {}
  const FigureSet& FiguredBass::getFigureSet() const {  return _figureSet; }
  void FiguredBass::removeFigure(const FigurePtr& value) { if(value) { auto i = std::find_if(_figureSet.begin(), _figureSet.end(), [&](const FigurePtr& item) { return item==value; }); if(i!=_figureSet.end()) _figureSet.erase(i); } } 
  void FiguredBass::addFigure(const FigurePtr& value) { if(value) { _figureSet.push_back(value); value->setParent(shared_from_this()); } }
  void FiguredBass::clearFigureSet() { _figureSet.clear(); }
  DurationPtr FiguredBass::getDuration() const { return _durationPtr; }
  void FiguredBass::setDuration(const DurationPtr& value) { _durationPtr = value; value->setParent(shared_from_this()); }
  FootnotePtr FiguredBass::getFootnote() const { return _footnotePtr; }
  void FiguredBass::setFootnote(const FootnotePtr& value) { _footnotePtr = value; value->setParent(shared_from_this()); }
  LevelPtr FiguredBass::getLevel() const { return _levelPtr; }
  void FiguredBass::setLevel(const LevelPtr& value) { _levelPtr = value; value->setParent(shared_from_this()); }
  bool FiguredBass::hasParentheses() const { return _hasParentheses; }
  void FiguredBass::hasParentheses(bool value) { _hasParentheses = value; }
  YesNoEnum FiguredBass::parentheses() const { return _parentheses; }
  void FiguredBass::parentheses(YesNoEnum value) { _parentheses = value; }

  void FiguredBass::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    Printout::ostreamAttrs(self);
    if(_hasParentheses) {
      self.append_attribute("parentheses").set_value(_parentheses.operator const char *());
    }
  }
  void FiguredBass::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    Printout::istreamAttrs(self);
    if(auto attr = self.attribute("parentheses")) {
      _parentheses = YesNoEnum(attr.as_string());
      _hasParentheses = true;
    }
  }
  void FiguredBass::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _figureSet) {
      auto child = self.append_child("figure");
      item->ostream(child);
    }
    if(_durationPtr) {
      auto child = self.append_child("duration");
      _durationPtr->ostream(child);
    }
    if(_footnotePtr) {
      auto child = self.append_child("footnote");
      _footnotePtr->ostream(child);
    }
    if(_levelPtr) {
      auto child = self.append_child("level");
      _levelPtr->ostream(child);
    }
  }
  void FiguredBass::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "figure")==0) {
        auto figurePtr = std::make_shared<Figure>();
        figurePtr->istream(child);
        addFigure(figurePtr);
      }
      else if(strcmp(child.name(), "duration")==0) {
        auto durationPtr = std::make_shared<Duration>();
        durationPtr->istream(child);
        setDuration(durationPtr);
      }
      else if(strcmp(child.name(), "footnote")==0) {
        auto footnotePtr = std::make_shared<Footnote>();
        footnotePtr->istream(child);
        setFootnote(footnotePtr);
      }
      else if(strcmp(child.name(), "level")==0) {
        auto levelPtr = std::make_shared<Level>();
        levelPtr->istream(child);
        setLevel(levelPtr);
      }
    }
  }
}
