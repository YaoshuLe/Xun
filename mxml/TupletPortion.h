#ifndef TUPLET_PORTION_H
#define TUPLET_PORTION_H
#include "Element.h"

namespace mxml
{
  class TupletNumber;
  using TupletNumberPtr = std::shared_ptr<TupletNumber>;
  class TupletType;
  using TupletTypePtr = std::shared_ptr<TupletType>;
  class TupletDot;
  using TupletDotPtr = std::shared_ptr<TupletDot>;
  using TupletDotSet = std::vector<TupletDotPtr>;

  class TupletPortion: public Element
  {
  public:
    TupletPortion();
    virtual const char* tagname() const { return "tuplet-portion"; }
    TupletNumberPtr getTupletNumber() const;
    void setTupletNumber(const TupletNumberPtr& value);
    TupletTypePtr getTupletType() const;
    void setTupletType(const TupletTypePtr& value);
    const TupletDotSet& getTupletDotSet() const;
    void removeTupletDot(const TupletDotPtr& value);
    void addTupletDot(const TupletDotPtr& value);
    void clearTupletDotSet();
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    TupletNumberPtr _tupletNumberPtr;
    TupletTypePtr _tupletTypePtr;
    TupletDotSet _tupletDotSet;
  };
}
#endif //TUPLET_PORTION_H
