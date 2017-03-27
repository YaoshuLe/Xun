#ifndef WORK_H
#define WORK_H
#include "Element.h"

namespace mxml
{
  class WorkNumber;
  using WorkNumberPtr = std::shared_ptr<WorkNumber>;
  class WorkTitle;
  using WorkTitlePtr = std::shared_ptr<WorkTitle>;
  class Opus;
  using OpusPtr = std::shared_ptr<Opus>;

  class Work: public Element
  {
  public:
    Work();
    virtual const char* tagname() const { return "work"; }
    WorkNumberPtr getWorkNumber() const;
    void setWorkNumber(const WorkNumberPtr& value);
    WorkTitlePtr getWorkTitle() const;
    void setWorkTitle(const WorkTitlePtr& value);
    OpusPtr getOpus() const;
    void setOpus(const OpusPtr& value);
  private:
    virtual void ostreamAttrs(pugi::xml_node& self) const { (void)self; }
    virtual void istreamAttrs(const pugi::xml_node& self) { (void)self; }
    virtual void ostreamContents(pugi::xml_node& self) const;
    virtual void istreamContents(const pugi::xml_node& self);
    WorkNumberPtr _workNumberPtr;
    WorkTitlePtr _workTitlePtr;
    OpusPtr _opusPtr;
  };
}
#endif //WORK_H
