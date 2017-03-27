#ifndef SLASH_H
#define SLASH_H
#include "Element.h"

namespace mxml
{
  class SlashType;
  using SlashTypePtr = std::shared_ptr<SlashType>;
  class SlashDot;
  using SlashDotPtr = std::shared_ptr<SlashDot>;
  using SlashDotSet = std::vector<SlashDotPtr>;

  class Slash: public Element
  {
  public:
    Slash();
    virtual const char* tagname() const { return "slash"; }
    SlashTypePtr getSlashType() const;
    void setSlashType(const SlashTypePtr& value);
    const SlashDotSet& getSlashDotSet() const;
    void removeSlashDot(const SlashDotPtr& value);
    void addSlashDot(const SlashDotPtr& value);
    void clearSlashDotSet();
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasUseDots() const;
    void hasUseDots(bool value);
    YesNoEnum useDots() const;
    void useDots(YesNoEnum value);
    bool hasUseStems() const;
    void hasUseStems(bool value);
    YesNoEnum useStems() const;
    void useStems(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    SlashTypePtr _slashTypePtr;
    SlashDotSet _slashDotSet;
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasUseDots {false};
    YesNoEnum _useDots;
    bool _hasUseStems {false};
    YesNoEnum _useStems;
  };
}
#endif //SLASH_H
