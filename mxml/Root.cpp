#include "Root.h"
#include <cstring>
#include "RootStep.h"
#include "RootAlter.h"

namespace mxml
{
  Root::Root() {}
  RootStepPtr Root::getRootStep() const { return _rootStepPtr; }
  void Root::setRootStep(const RootStepPtr& value) { _rootStepPtr = value; value->setParent(shared_from_this()); }
  RootAlterPtr Root::getRootAlter() const { return _rootAlterPtr; }
  void Root::setRootAlter(const RootAlterPtr& value) { _rootAlterPtr = value; value->setParent(shared_from_this()); }

  void Root::ostreamContents(pugi::xml_node& self) const
  {
    if(_rootStepPtr) {
      auto child = self.append_child("root-step");
      _rootStepPtr->ostream(child);
    }
    if(_rootAlterPtr) {
      auto child = self.append_child("root-alter");
      _rootAlterPtr->ostream(child);
    }
  }
  void Root::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "root-step")==0) {
        auto rootStepPtr = std::make_shared<RootStep>();
        rootStepPtr->istream(child);
        setRootStep(rootStepPtr);
      }
      else if(strcmp(child.name(), "root-alter")==0) {
        auto rootAlterPtr = std::make_shared<RootAlter>();
        rootAlterPtr->istream(child);
        setRootAlter(rootAlterPtr);
      }
    }
  }
}
