#include "Credit.h"
#include <cstring>
#include "CreditType.h"
#include "Link.h"
#include "Bookmark.h"
#include "CreditImage.h"
#include "CreditWords.h"

namespace mxml
{
  Credit::Credit() {}
  const CreditTypeSet& Credit::getCreditTypeSet() const {  return _creditTypeSet; }
  void Credit::removeCreditType(const CreditTypePtr& value) { if(value) { auto i = std::find_if(_creditTypeSet.begin(), _creditTypeSet.end(), [&](const CreditTypePtr& item) { return item==value; }); if(i!=_creditTypeSet.end()) _creditTypeSet.erase(i); } } 
  void Credit::addCreditType(const CreditTypePtr& value) { if(value) { _creditTypeSet.push_back(value); value->setParent(shared_from_this()); } }
  void Credit::clearCreditTypeSet() { _creditTypeSet.clear(); }
  const LinkSet& Credit::getLinkSet() const {  return _linkSet; }
  void Credit::removeLink(const LinkPtr& value) { if(value) { auto i = std::find_if(_linkSet.begin(), _linkSet.end(), [&](const LinkPtr& item) { return item==value; }); if(i!=_linkSet.end()) _linkSet.erase(i); } } 
  void Credit::addLink(const LinkPtr& value) { if(value) { _linkSet.push_back(value); value->setParent(shared_from_this()); } }
  void Credit::clearLinkSet() { _linkSet.clear(); }
  const BookmarkSet& Credit::getBookmarkSet() const {  return _bookmarkSet; }
  void Credit::removeBookmark(const BookmarkPtr& value) { if(value) { auto i = std::find_if(_bookmarkSet.begin(), _bookmarkSet.end(), [&](const BookmarkPtr& item) { return item==value; }); if(i!=_bookmarkSet.end()) _bookmarkSet.erase(i); } } 
  void Credit::addBookmark(const BookmarkPtr& value) { if(value) { _bookmarkSet.push_back(value); value->setParent(shared_from_this()); } }
  void Credit::clearBookmarkSet() { _bookmarkSet.clear(); }
  CreditImagePtr Credit::getCreditImage() const { return _creditImagePtr; }
  void Credit::setCreditImage(const CreditImagePtr& value) { _creditImagePtr = value; value->setParent(shared_from_this()); }
  CreditWordsPtr Credit::getCreditWords() const { return _creditWordsPtr; }
  void Credit::setCreditWords(const CreditWordsPtr& value) { _creditWordsPtr = value; value->setParent(shared_from_this()); }
  bool Credit::hasPage() const { return _hasPage; }
  void Credit::hasPage(bool value) { _hasPage = value; }
  int Credit::page() const { return _page; }
  void Credit::page(int value) { _page = value; }

  void Credit::ostreamAttrs(pugi::xml_node& self) const
  {
    if(_hasPage) {
      char str[11]={0};
      snprintf(str, sizeof(str), "%d", _page);
      self.append_attribute("page").set_value(str);
    }
  }
  void Credit::istreamAttrs(const pugi::xml_node& self)
  {
    if(auto attr = self.attribute("page")) {
      _page = attr.as_int();
      _hasPage = true;
    }
  }
  void Credit::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _creditTypeSet) {
      auto child = self.append_child("credit-type");
      item->ostream(child);
    }
    for(auto item : _linkSet) {
      auto child = self.append_child("link");
      item->ostream(child);
    }
    for(auto item : _bookmarkSet) {
      auto child = self.append_child("bookmark");
      item->ostream(child);
    }
    if(_creditImagePtr) {
      auto child = self.append_child("credit-image");
      _creditImagePtr->ostream(child);
    }
    else if(_creditWordsPtr) {
      auto child = self.append_child("credit-words");
      _creditWordsPtr->ostream(child);
    }
  }
  void Credit::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "credit-type")==0) {
        auto creditTypePtr = std::make_shared<CreditType>();
        creditTypePtr->istream(child);
        addCreditType(creditTypePtr);
      }
      else if(strcmp(child.name(), "link")==0) {
        auto linkPtr = std::make_shared<Link>();
        linkPtr->istream(child);
        addLink(linkPtr);
      }
      else if(strcmp(child.name(), "bookmark")==0) {
        auto bookmarkPtr = std::make_shared<Bookmark>();
        bookmarkPtr->istream(child);
        addBookmark(bookmarkPtr);
      }
      else if(strcmp(child.name(), "credit-image")==0) {
        auto creditImagePtr = std::make_shared<CreditImage>();
        creditImagePtr->istream(child);
        setCreditImage(creditImagePtr);
      }
      else if(strcmp(child.name(), "credit-words")==0) {
        auto creditWordsPtr = std::make_shared<CreditWords>();
        creditWordsPtr->istream(child);
        setCreditWords(creditWordsPtr);
      }
    }
  }
}
