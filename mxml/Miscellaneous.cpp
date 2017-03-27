#include "Miscellaneous.h"
#include <cstring>
#include "MiscellaneousField.h"

namespace mxml
{
  Miscellaneous::Miscellaneous() {}
  const MiscellaneousFieldSet& Miscellaneous::getMiscellaneousFieldSet() const {  return _miscellaneousFieldSet; }
  void Miscellaneous::removeMiscellaneousField(const MiscellaneousFieldPtr& value) { if(value) { auto i = std::find_if(_miscellaneousFieldSet.begin(), _miscellaneousFieldSet.end(), [&](const MiscellaneousFieldPtr& item) { return item==value; }); if(i!=_miscellaneousFieldSet.end()) _miscellaneousFieldSet.erase(i); } } 
  void Miscellaneous::addMiscellaneousField(const MiscellaneousFieldPtr& value) { if(value) { _miscellaneousFieldSet.push_back(value); value->setParent(shared_from_this()); } }
  void Miscellaneous::clearMiscellaneousFieldSet() { _miscellaneousFieldSet.clear(); }

  void Miscellaneous::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _miscellaneousFieldSet) {
      auto child = self.append_child("miscellaneous-field");
      item->ostream(child);
    }
  }
  void Miscellaneous::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "miscellaneous-field")==0) {
        auto miscellaneousFieldPtr = std::make_shared<MiscellaneousField>();
        miscellaneousFieldPtr->istream(child);
        addMiscellaneousField(miscellaneousFieldPtr);
      }
    }
  }
}
