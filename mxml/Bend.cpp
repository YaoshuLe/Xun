#include "Bend.h"
#include <cstring>
#include "BendAlter.h"
#include "PreBend.h"
#include "Release.h"
#include "WithBar.h"

namespace mxml
{
  Bend::Bend() {}
  BendAlterPtr Bend::getBendAlter() const { return _bendAlterPtr; }
  void Bend::setBendAlter(const BendAlterPtr& value) { _bendAlterPtr = value; value->setParent(shared_from_this()); }
  PreBendPtr Bend::getPreBend() const { return _preBendPtr; }
  void Bend::setPreBend(const PreBendPtr& value) { _preBendPtr = value; value->setParent(shared_from_this()); }
  ReleasePtr Bend::getRelease() const { return _releasePtr; }
  void Bend::setRelease(const ReleasePtr& value) { _releasePtr = value; value->setParent(shared_from_this()); }
  WithBarPtr Bend::getWithBar() const { return _withBarPtr; }
  void Bend::setWithBar(const WithBarPtr& value) { _withBarPtr = value; value->setParent(shared_from_this()); }

  void Bend::ostreamAttrs(pugi::xml_node& self) const
  {
    PrintStyle::ostreamAttrs(self);
    BendSound::ostreamAttrs(self);
  }
  void Bend::istreamAttrs(const pugi::xml_node& self)
  {
    PrintStyle::istreamAttrs(self);
    BendSound::istreamAttrs(self);
  }
  void Bend::ostreamContents(pugi::xml_node& self) const
  {
    if(_bendAlterPtr) {
      auto child = self.append_child("bend-alter");
      _bendAlterPtr->ostream(child);
    }
    if(_preBendPtr) {
      auto child = self.append_child("pre-bend");
      _preBendPtr->ostream(child);
    }
    else if(_releasePtr) {
      auto child = self.append_child("release");
      _releasePtr->ostream(child);
    }
    if(_withBarPtr) {
      auto child = self.append_child("with-bar");
      _withBarPtr->ostream(child);
    }
  }
  void Bend::istreamContents(const pugi::xml_node& self)
  {
    for(auto child: self.children()) {
      if(strcmp(child.name(), "bend-alter")==0) {
        auto bendAlterPtr = std::make_shared<BendAlter>();
        bendAlterPtr->istream(child);
        setBendAlter(bendAlterPtr);
      }
      else if(strcmp(child.name(), "pre-bend")==0) {
        auto preBendPtr = std::make_shared<PreBend>();
        preBendPtr->istream(child);
        setPreBend(preBendPtr);
      }
      else if(strcmp(child.name(), "release")==0) {
        auto releasePtr = std::make_shared<Release>();
        releasePtr->istream(child);
        setRelease(releasePtr);
      }
      else if(strcmp(child.name(), "with-bar")==0) {
        auto withBarPtr = std::make_shared<WithBar>();
        withBarPtr->istream(child);
        setWithBar(withBarPtr);
      }
    }
  }
}
