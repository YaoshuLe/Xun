#include "VirtualInstrument.h"
#include <cstring>
#include "VirtualLibrary.h"
#include "VirtualName.h"

namespace mxml
{
  VirtualInstrument::VirtualInstrument() {}
  VirtualLibraryPtr VirtualInstrument::getVirtualLibrary() const { return _virtualLibraryPtr; }
  void VirtualInstrument::setVirtualLibrary(const VirtualLibraryPtr& value) { _virtualLibraryPtr = value; value->setParent(shared_from_this()); }
  VirtualNamePtr VirtualInstrument::getVirtualName() const { return _virtualNamePtr; }
  void VirtualInstrument::setVirtualName(const VirtualNamePtr& value) { _virtualNamePtr = value; value->setParent(shared_from_this()); }

  void VirtualInstrument::ostreamContents(pugi::xml_node& self) const
  {
    if(_virtualLibraryPtr) {
      auto child = self.append_child("virtual-library");
      _virtualLibraryPtr->ostream(child);
    }
    if(_virtualNamePtr) {
      auto child = self.append_child("virtual-name");
      _virtualNamePtr->ostream(child);
    }
  }
  void VirtualInstrument::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "virtual-library")==0) {
        auto virtualLibraryPtr = std::make_shared<VirtualLibrary>();
        virtualLibraryPtr->istream(child);
        setVirtualLibrary(virtualLibraryPtr);
      }
      else if(strcmp(child.name(), "virtual-name")==0) {
        auto virtualNamePtr = std::make_shared<VirtualName>();
        virtualNamePtr->istream(child);
        setVirtualName(virtualNamePtr);
      }
    }
  }
}
