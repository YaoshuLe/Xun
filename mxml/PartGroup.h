#ifndef PART_GROUP_H
#define PART_GROUP_H
#include "Element.h"

namespace mxml
{
  class GroupName;
  using GroupNamePtr = std::shared_ptr<GroupName>;
  class GroupNameDisplay;
  using GroupNameDisplayPtr = std::shared_ptr<GroupNameDisplay>;
  class GroupAbbreviation;
  using GroupAbbreviationPtr = std::shared_ptr<GroupAbbreviation>;
  class GroupAbbreviationDisplay;
  using GroupAbbreviationDisplayPtr = std::shared_ptr<GroupAbbreviationDisplay>;
  class GroupSymbol;
  using GroupSymbolPtr = std::shared_ptr<GroupSymbol>;
  class GroupBarline;
  using GroupBarlinePtr = std::shared_ptr<GroupBarline>;
  class GroupTime;
  using GroupTimePtr = std::shared_ptr<GroupTime>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;

  class PartGroup: public Element
  {
  public:
    PartGroup();
    virtual const char* tagname() const { return "part-group"; }
    GroupNamePtr getGroupName() const;
    void setGroupName(const GroupNamePtr& value);
    GroupNameDisplayPtr getGroupNameDisplay() const;
    void setGroupNameDisplay(const GroupNameDisplayPtr& value);
    GroupAbbreviationPtr getGroupAbbreviation() const;
    void setGroupAbbreviation(const GroupAbbreviationPtr& value);
    GroupAbbreviationDisplayPtr getGroupAbbreviationDisplay() const;
    void setGroupAbbreviationDisplay(const GroupAbbreviationDisplayPtr& value);
    GroupSymbolPtr getGroupSymbol() const;
    void setGroupSymbol(const GroupSymbolPtr& value);
    GroupBarlinePtr getGroupBarline() const;
    void setGroupBarline(const GroupBarlinePtr& value);
    GroupTimePtr getGroupTime() const;
    void setGroupTime(const GroupTimePtr& value);
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
    bool hasType() const;
    void hasType(bool value);
    StartStopEnum type() const;
    void type(StartStopEnum value);
    bool hasNumber() const;
    void hasNumber(bool value);
    std::string number() const;
    void number(std::string value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const;
    virtual void istreamAttrs(const pugi::xml_node& self);
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    GroupNamePtr _groupNamePtr;
    GroupNameDisplayPtr _groupNameDisplayPtr;
    GroupAbbreviationPtr _groupAbbreviationPtr;
    GroupAbbreviationDisplayPtr _groupAbbreviationDisplayPtr;
    GroupSymbolPtr _groupSymbolPtr;
    GroupBarlinePtr _groupBarlinePtr;
    GroupTimePtr _groupTimePtr;
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
    bool _hasType {false};
    StartStopEnum _type;
    bool _hasNumber {false};
    std::string _number;
  };
}
#endif //PART_GROUP_H
