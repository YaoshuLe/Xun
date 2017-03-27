#include "PageMargins.h"
#include <cstring>
#include "LeftMargin.h"
#include "RightMargin.h"
#include "TopMargin.h"
#include "BottomMargin.h"

namespace mxml
{
  PageMargins::PageMargins() {}
  LeftMarginPtr PageMargins::getLeftMargin() const { return _leftMarginPtr; }
  void PageMargins::setLeftMargin(const LeftMarginPtr& value) { _leftMarginPtr = value; value->setParent(shared_from_this()); }
  RightMarginPtr PageMargins::getRightMargin() const { return _rightMarginPtr; }
  void PageMargins::setRightMargin(const RightMarginPtr& value) { _rightMarginPtr = value; value->setParent(shared_from_this()); }
  TopMarginPtr PageMargins::getTopMargin() const { return _topMarginPtr; }
  void PageMargins::setTopMargin(const TopMarginPtr& value) { _topMarginPtr = value; value->setParent(shared_from_this()); }
  BottomMarginPtr PageMargins::getBottomMargin() const { return _bottomMarginPtr; }
  void PageMargins::setBottomMargin(const BottomMarginPtr& value) { _bottomMarginPtr = value; value->setParent(shared_from_this()); }
  bool PageMargins::hasType() const { return _hasType; }
  void PageMargins::hasType(bool value) { _hasType = value; }
  MarginTypeEnum PageMargins::type() const { return _type; }
  void PageMargins::type(MarginTypeEnum value) { _type = value; }

  void PageMargins::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasType) {
      self.append_attribute("type").set_value(_type.operator const char *());
    }
  }
  void PageMargins::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("type")) {
      _type = MarginTypeEnum(attr.as_string());
      _hasType = true;
    }
  }
  void PageMargins::ostreamContents(pugi::xml_node& self) const
  {
    if(_leftMarginPtr) {
      auto child = self.append_child("left-margin");
      _leftMarginPtr->ostream(child);
    }
    if(_rightMarginPtr) {
      auto child = self.append_child("right-margin");
      _rightMarginPtr->ostream(child);
    }
    if(_topMarginPtr) {
      auto child = self.append_child("top-margin");
      _topMarginPtr->ostream(child);
    }
    if(_bottomMarginPtr) {
      auto child = self.append_child("bottom-margin");
      _bottomMarginPtr->ostream(child);
    }
  }
  void PageMargins::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "left-margin")==0) {
        auto leftMarginPtr = std::make_shared<LeftMargin>();
        leftMarginPtr->istream(child);
        setLeftMargin(leftMarginPtr);
      }
      else if(strcmp(child.name(), "right-margin")==0) {
        auto rightMarginPtr = std::make_shared<RightMargin>();
        rightMarginPtr->istream(child);
        setRightMargin(rightMarginPtr);
      }
      else if(strcmp(child.name(), "top-margin")==0) {
        auto topMarginPtr = std::make_shared<TopMargin>();
        topMarginPtr->istream(child);
        setTopMargin(topMarginPtr);
      }
      else if(strcmp(child.name(), "bottom-margin")==0) {
        auto bottomMarginPtr = std::make_shared<BottomMargin>();
        bottomMarginPtr->istream(child);
        setBottomMargin(bottomMarginPtr);
      }
    }
  }
}
