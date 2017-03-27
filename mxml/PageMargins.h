#ifndef PAGE_MARGINS_H
#define PAGE_MARGINS_H
#include "Element.h"

namespace mxml
{
  class LeftMargin;
  using LeftMarginPtr = std::shared_ptr<LeftMargin>;
  class RightMargin;
  using RightMarginPtr = std::shared_ptr<RightMargin>;
  class TopMargin;
  using TopMarginPtr = std::shared_ptr<TopMargin>;
  class BottomMargin;
  using BottomMarginPtr = std::shared_ptr<BottomMargin>;

  class PageMargins: public Element
  {
  public:
    PageMargins();
    virtual const char* tagname() const { return "page-margins"; }
    LeftMarginPtr getLeftMargin() const;
    void setLeftMargin(const LeftMarginPtr& value);
    RightMarginPtr getRightMargin() const;
    void setRightMargin(const RightMarginPtr& value);
    TopMarginPtr getTopMargin() const;
    void setTopMargin(const TopMarginPtr& value);
    BottomMarginPtr getBottomMargin() const;
    void setBottomMargin(const BottomMarginPtr& value);
    bool hasType() const;
    void hasType(bool value);
    MarginTypeEnum type() const;
    void type(MarginTypeEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    LeftMarginPtr _leftMarginPtr;
    RightMarginPtr _rightMarginPtr;
    TopMarginPtr _topMarginPtr;
    BottomMarginPtr _bottomMarginPtr;
    bool _hasType {false};
    MarginTypeEnum _type;
  };
}
#endif //PAGE_MARGINS_H
