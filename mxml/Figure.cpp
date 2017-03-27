#include "Figure.h"
#include <cstring>
#include "Prefix.h"
#include "FigureNumber.h"
#include "Suffix.h"
#include "Extend.h"

namespace mxml
{
  Figure::Figure() {}
  PrefixPtr Figure::getPrefix() const { return _prefixPtr; }
  void Figure::setPrefix(const PrefixPtr& value) { _prefixPtr = value; value->setParent(shared_from_this()); }
  FigureNumberPtr Figure::getFigureNumber() const { return _figureNumberPtr; }
  void Figure::setFigureNumber(const FigureNumberPtr& value) { _figureNumberPtr = value; value->setParent(shared_from_this()); }
  SuffixPtr Figure::getSuffix() const { return _suffixPtr; }
  void Figure::setSuffix(const SuffixPtr& value) { _suffixPtr = value; value->setParent(shared_from_this()); }
  ExtendPtr Figure::getExtend() const { return _extendPtr; }
  void Figure::setExtend(const ExtendPtr& value) { _extendPtr = value; value->setParent(shared_from_this()); }

  void Figure::ostreamContents(pugi::xml_node& self) const
  {
    if(_prefixPtr) {
      auto child = self.append_child("prefix");
      _prefixPtr->ostream(child);
    }
    if(_figureNumberPtr) {
      auto child = self.append_child("figure-number");
      _figureNumberPtr->ostream(child);
    }
    if(_suffixPtr) {
      auto child = self.append_child("suffix");
      _suffixPtr->ostream(child);
    }
    if(_extendPtr) {
      auto child = self.append_child("extend");
      _extendPtr->ostream(child);
    }
  }
  void Figure::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "prefix")==0) {
        auto prefixPtr = std::make_shared<Prefix>();
        prefixPtr->istream(child);
        setPrefix(prefixPtr);
      }
      else if(strcmp(child.name(), "figure-number")==0) {
        auto figureNumberPtr = std::make_shared<FigureNumber>();
        figureNumberPtr->istream(child);
        setFigureNumber(figureNumberPtr);
      }
      else if(strcmp(child.name(), "suffix")==0) {
        auto suffixPtr = std::make_shared<Suffix>();
        suffixPtr->istream(child);
        setSuffix(suffixPtr);
      }
      else if(strcmp(child.name(), "extend")==0) {
        auto extendPtr = std::make_shared<Extend>();
        extendPtr->istream(child);
        setExtend(extendPtr);
      }
    }
  }
}
