#include "Scordatura.h"
#include <cstring>
#include "Accord.h"

namespace mxml
{
  Scordatura::Scordatura() {}
  const AccordSet& Scordatura::getAccordSet() const {  return _accordSet; }
  void Scordatura::removeAccord(const AccordPtr& value) { if(value) { auto i = std::find_if(_accordSet.begin(), _accordSet.end(), [&](const AccordPtr& item) { return item==value; }); if(i!=_accordSet.end()) _accordSet.erase(i); } } 
  void Scordatura::addAccord(const AccordPtr& value) { if(value) { _accordSet.push_back(value); value->setParent(shared_from_this()); } }
  void Scordatura::clearAccordSet() { _accordSet.clear(); }

  void Scordatura::ostreamContents(pugi::xml_node& self) const
  {
    for(auto item : _accordSet) {
      auto child = self.append_child("accord");
      item->ostream(child);
    }
  }
  void Scordatura::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "accord")==0) {
        auto accordPtr = std::make_shared<Accord>();
        accordPtr->istream(child);
        addAccord(accordPtr);
      }
    }
  }
}
