#ifndef CREDIT_H
#define CREDIT_H
#include "Element.h"

namespace mxml
{
  class CreditType;
  using CreditTypePtr = std::shared_ptr<CreditType>;
  using CreditTypeSet = std::vector<CreditTypePtr>;
  class Link;
  using LinkPtr = std::shared_ptr<Link>;
  using LinkSet = std::vector<LinkPtr>;
  class Bookmark;
  using BookmarkPtr = std::shared_ptr<Bookmark>;
  using BookmarkSet = std::vector<BookmarkPtr>;
  class CreditImage;
  using CreditImagePtr = std::shared_ptr<CreditImage>;
  class CreditWords;
  using CreditWordsPtr = std::shared_ptr<CreditWords>;

  class Credit: public Element
  {
  public:
    Credit();
    virtual const char* tagname() const { return "credit"; }
    const CreditTypeSet& getCreditTypeSet() const;
    void removeCreditType(const CreditTypePtr& value);
    void addCreditType(const CreditTypePtr& value);
    void clearCreditTypeSet();
    const LinkSet& getLinkSet() const;
    void removeLink(const LinkPtr& value);
    void addLink(const LinkPtr& value);
    void clearLinkSet();
    const BookmarkSet& getBookmarkSet() const;
    void removeBookmark(const BookmarkPtr& value);
    void addBookmark(const BookmarkPtr& value);
    void clearBookmarkSet();
    CreditImagePtr getCreditImage() const;
    void setCreditImage(const CreditImagePtr& value);
    CreditWordsPtr getCreditWords() const;
    void setCreditWords(const CreditWordsPtr& value);
    bool hasPage() const;
    void hasPage(bool value);
    int page() const;
    void page(int value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    CreditTypeSet _creditTypeSet;
    LinkSet _linkSet;
    BookmarkSet _bookmarkSet;
    CreditImagePtr _creditImagePtr;
    CreditWordsPtr _creditWordsPtr;
    bool _hasPage {false};
    int _page;
  };
}
#endif //CREDIT_H
