#include "PageLayout.h"
#include <cstring>
#include "PageHeight.h"
#include "PageWidth.h"
#include "PageMargins.h"

namespace mxml
{
  PageLayout::PageLayout() {}
  PageHeightPtr PageLayout::getPageHeight() const { return _pageHeightPtr; }
  void PageLayout::setPageHeight(const PageHeightPtr& value) { _pageHeightPtr = value; value->setParent(shared_from_this()); }
  PageWidthPtr PageLayout::getPageWidth() const { return _pageWidthPtr; }
  void PageLayout::setPageWidth(const PageWidthPtr& value) { _pageWidthPtr = value; value->setParent(shared_from_this()); }
  const PageMarginsSet& PageLayout::getPageMarginsSet() const {  return _pageMarginsSet; }
  void PageLayout::removePageMargins(const PageMarginsPtr& value) { if(value) { auto i = std::find_if(_pageMarginsSet.begin(), _pageMarginsSet.end(), [&](const PageMarginsPtr& item) { return item==value; }); if(i!=_pageMarginsSet.end()) _pageMarginsSet.erase(i); } } 
  void PageLayout::addPageMargins(const PageMarginsPtr& value) { if(value) { _pageMarginsSet.push_back(value); value->setParent(shared_from_this()); } }
  void PageLayout::clearPageMarginsSet() { _pageMarginsSet.clear(); }

  void PageLayout::ostreamContents(pugi::xml_node& self) const
  {
    if(_pageHeightPtr) {
      auto child = self.append_child("page-height");
      _pageHeightPtr->ostream(child);
    }
    if(_pageWidthPtr) {
      auto child = self.append_child("page-width");
      _pageWidthPtr->ostream(child);
    }
    for(auto item : _pageMarginsSet) {
      auto child = self.append_child("page-margins");
      item->ostream(child);
    }
  }
  void PageLayout::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "page-height")==0) {
        auto pageHeightPtr = std::make_shared<PageHeight>();
        pageHeightPtr->istream(child);
        setPageHeight(pageHeightPtr);
      }
      else if(strcmp(child.name(), "page-width")==0) {
        auto pageWidthPtr = std::make_shared<PageWidth>();
        pageWidthPtr->istream(child);
        setPageWidth(pageWidthPtr);
      }
      else if(strcmp(child.name(), "page-margins")==0) {
        auto pageMarginsPtr = std::make_shared<PageMargins>();
        pageMarginsPtr->istream(child);
        addPageMargins(pageMarginsPtr);
      }
    }
  }
}
