#ifndef BEAT_REPEAT_H
#define BEAT_REPEAT_H
#include "Element.h"

namespace mxml
{
  class SlashType;
  using SlashTypePtr = std::shared_ptr<SlashType>;
  class SlashDot;
  using SlashDotPtr = std::shared_ptr<SlashDot>;
  using SlashDotSet = std::vector<SlashDotPtr>;

  class BeatRepeat: public Element
  {
  public:
    BeatRepeat();
    virtual const char* tagname() const { return "beat-repeat"; }
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
    bool hasSlashes() const;
    void hasSlashes(bool value);
    int slashes() const;
    void slashes(int value);
    bool hasUseDots() const;
    void hasUseDots(bool value);
    YesNoEnum useDots() const;
    void useDots(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    SlashTypePtr _slashTypePtr;
    SlashDotSet _slashDotSet;
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasSlashes {false};
    int _slashes;
    bool _hasUseDots {false};
    YesNoEnum _useDots;
  };
}
#endif //BEAT_REPEAT_H
