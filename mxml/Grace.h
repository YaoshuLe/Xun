#ifndef GRACE_H
#define GRACE_H
#include "Element.h"

namespace mxml
{
  class Grace: public Empty
  {
  public:
    Grace();
    virtual const char* tagname() const { return "grace"; }
    bool hasStealTimePrevious() const;
    void hasStealTimePrevious(bool value);
    float stealTimePrevious() const;
    void stealTimePrevious(float value);
    bool hasStealTimeFollowing() const;
    void hasStealTimeFollowing(bool value);
    float stealTimeFollowing() const;
    void stealTimeFollowing(float value);
    bool hasMakeTime() const;
    void hasMakeTime(bool value);
    float makeTime() const;
    void makeTime(float value);
    bool hasSlash() const;
    void hasSlash(bool value);
    YesNoEnum slash() const;
    void slash(YesNoEnum value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    bool _hasStealTimePrevious {false};
    float _stealTimePrevious;
    bool _hasStealTimeFollowing {false};
    float _stealTimeFollowing;
    bool _hasMakeTime {false};
    float _makeTime;
    bool _hasSlash {false};
    YesNoEnum _slash;
  };
}
#endif //GRACE_H
