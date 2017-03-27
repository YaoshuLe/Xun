#include "Bass.h"
#include <cstring>
#include "BassStep.h"
#include "BassAlter.h"

namespace mxml
{
  Bass::Bass() {}
  BassStepPtr Bass::getBassStep() const { return _bassStepPtr; }
  void Bass::setBassStep(const BassStepPtr& value) { _bassStepPtr = value; value->setParent(shared_from_this()); }
  BassAlterPtr Bass::getBassAlter() const { return _bassAlterPtr; }
  void Bass::setBassAlter(const BassAlterPtr& value) { _bassAlterPtr = value; value->setParent(shared_from_this()); }

  void Bass::ostreamContents(pugi::xml_node& self) const
  {
    if(_bassStepPtr) {
      auto child = self.append_child("bass-step");
      _bassStepPtr->ostream(child);
    }
    if(_bassAlterPtr) {
      auto child = self.append_child("bass-alter");
      _bassAlterPtr->ostream(child);
    }
  }
  void Bass::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "bass-step")==0) {
        auto bassStepPtr = std::make_shared<BassStep>();
        bassStepPtr->istream(child);
        setBassStep(bassStepPtr);
      }
      else if(strcmp(child.name(), "bass-alter")==0) {
        auto bassAlterPtr = std::make_shared<BassAlter>();
        bassAlterPtr->istream(child);
        setBassAlter(bassAlterPtr);
      }
    }
  }
}
