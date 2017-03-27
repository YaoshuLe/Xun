#ifndef PAGE_LAYOUT_H
#define PAGE_LAYOUT_H
#include "Element.h"

namespace mxml
{
  class PageHeight;
  using PageHeightPtr = std::shared_ptr<PageHeight>;
  class PageWidth;
  using PageWidthPtr = std::shared_ptr<PageWidth>;
  class PageMargins;
  using PageMarginsPtr = std::shared_ptr<PageMargins>;
  using PageMarginsSet = std::vector<PageMarginsPtr>;

  class PageLayout: public Element
  {
  public:
    PageLayout();
    virtual const char* tagname() const { return "page-layout"; }
    PageHeightPtr getPageHeight() const;
    void setPageHeight(const PageHeightPtr& value);
    PageWidthPtr getPageWidth() const;
    void setPageWidth(const PageWidthPtr& value);
    const PageMarginsSet& getPageMarginsSet() const;
    void removePageMargins(const PageMarginsPtr& value);
    void addPageMargins(const PageMarginsPtr& value);
    void clearPageMarginsSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    PageHeightPtr _pageHeightPtr;
    PageWidthPtr _pageWidthPtr;
    PageMarginsSet _pageMarginsSet;
  };
}
#endif //PAGE_LAYOUT_H
