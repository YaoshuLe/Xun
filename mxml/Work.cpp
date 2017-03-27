#include "Work.h"
#include <cstring>
#include "WorkNumber.h"
#include "WorkTitle.h"
#include "Opus.h"

namespace mxml
{
  Work::Work() {}
  WorkNumberPtr Work::getWorkNumber() const { return _workNumberPtr; }
  void Work::setWorkNumber(const WorkNumberPtr& value) { _workNumberPtr = value; value->setParent(shared_from_this()); }
  WorkTitlePtr Work::getWorkTitle() const { return _workTitlePtr; }
  void Work::setWorkTitle(const WorkTitlePtr& value) { _workTitlePtr = value; value->setParent(shared_from_this()); }
  OpusPtr Work::getOpus() const { return _opusPtr; }
  void Work::setOpus(const OpusPtr& value) { _opusPtr = value; value->setParent(shared_from_this()); }

  void Work::ostreamContents(pugi::xml_node& self) const
  {
    if(_workNumberPtr) {
      auto child = self.append_child("work-number");
      _workNumberPtr->ostream(child);
    }
    if(_workTitlePtr) {
      auto child = self.append_child("work-title");
      _workTitlePtr->ostream(child);
    }
    if(_opusPtr) {
      auto child = self.append_child("opus");
      _opusPtr->ostream(child);
    }
  }
  void Work::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "work-number")==0) {
        auto workNumberPtr = std::make_shared<WorkNumber>();
        workNumberPtr->istream(child);
        setWorkNumber(workNumberPtr);
      }
      else if(strcmp(child.name(), "work-title")==0) {
        auto workTitlePtr = std::make_shared<WorkTitle>();
        workTitlePtr->istream(child);
        setWorkTitle(workTitlePtr);
      }
      else if(strcmp(child.name(), "opus")==0) {
        auto opusPtr = std::make_shared<Opus>();
        opusPtr->istream(child);
        setOpus(opusPtr);
      }
    }
  }
}
