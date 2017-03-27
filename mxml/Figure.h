#ifndef FIGURE_H
#define FIGURE_H
#include "Element.h"

namespace mxml
{
  class Prefix;
  using PrefixPtr = std::shared_ptr<Prefix>;
  class FigureNumber;
  using FigureNumberPtr = std::shared_ptr<FigureNumber>;
  class Suffix;
  using SuffixPtr = std::shared_ptr<Suffix>;
  class Extend;
  using ExtendPtr = std::shared_ptr<Extend>;

  class Figure: public Element
  {
  public:
    Figure();
    virtual const char* tagname() const { return "figure"; }
    PrefixPtr getPrefix() const;
    void setPrefix(const PrefixPtr& value);
    FigureNumberPtr getFigureNumber() const;
    void setFigureNumber(const FigureNumberPtr& value);
    SuffixPtr getSuffix() const;
    void setSuffix(const SuffixPtr& value);
    ExtendPtr getExtend() const;
    void setExtend(const ExtendPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    PrefixPtr _prefixPtr;
    FigureNumberPtr _figureNumberPtr;
    SuffixPtr _suffixPtr;
    ExtendPtr _extendPtr;
  };
}
#endif //FIGURE_H
