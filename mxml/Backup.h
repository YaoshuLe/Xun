#ifndef BACKUP_H
#define BACKUP_H
#include "Element.h"

namespace mxml
{
  class Duration;
  using DurationPtr = std::shared_ptr<Duration>;
  class Footnote;
  using FootnotePtr = std::shared_ptr<Footnote>;
  class Level;
  using LevelPtr = std::shared_ptr<Level>;

  class Backup: public Element
  {
  public:
    Backup();
    virtual const char* tagname() const { return "backup"; }
    DurationPtr getDuration() const;
    void setDuration(const DurationPtr& value);
    FootnotePtr getFootnote() const;
    void setFootnote(const FootnotePtr& value);
    LevelPtr getLevel() const;
    void setLevel(const LevelPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    DurationPtr _durationPtr;
    FootnotePtr _footnotePtr;
    LevelPtr _levelPtr;
  };
}
#endif //BACKUP_H
